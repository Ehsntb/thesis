#include <omnetpp.h>
#include "LightIoTMessage_m.h"

using namespace omnetpp;

class SensorNode : public cSimpleModule {
  private:
    cMessage *sendEvent;                  // تایمر داخلی برای ارسال دوره‌ای
    int msgId = 0;                        // شناسه پیام‌ها
    double batteryCapacity = 5000.0;      // ظرفیت اولیه باتری (میلی‌ژول)
    double consumptionPerMessage = 20.0;  // مصرف هر ارسال (میلی‌ژول)

  protected:
    virtual void initialize() override {
        sendEvent = new cMessage("sendEvent");
        scheduleAt(simTime() + uniform(0.5, 1.5), sendEvent);  // ارسال اولیه با تأخیر تصادفی
    }

    virtual void handleMessage(cMessage *msg) override {
        if (batteryCapacity < consumptionPerMessage) {
            EV << "[SensorNode] Battery depleted. Node stopped.\n";
            delete msg;
            sendEvent = nullptr;
            return;
        }

        LightIoTMessage *packet = new LightIoTMessage("SensorData");
        packet->setId(msgId++);
        packet->setHmac("VALID"); // نشانه امنیت معتبر
        packet->setTimestamp(simTime());

        send(packet, "out");
        batteryCapacity -= consumptionPerMessage;

        scheduleAt(simTime() + uniform(0.9, 1.1), sendEvent); // ارسال بعدی
    }

    virtual void finish() override {
        double percent = (batteryCapacity / 5000.0) * 100;
        EV << "[SensorNode] Energy Remaining: " << batteryCapacity
           << " mJ (" << percent << "%)\n";
        if (sendEvent != nullptr) {
            cancelAndDelete(sendEvent);
        }
    }
};

Define_Module(SensorNode);