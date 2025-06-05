#include <omnetpp.h>
#include "LightIoTMessage_m.h"

using namespace omnetpp;

class FakeNode : public cSimpleModule {
  private:
    cMessage *attackEvent;
    int fakeId = 1000; // ID بالا برای تشخیص آسان
    int mode = 1; // 1 = Replay, 2 = MITM

  protected:
    virtual void initialize() override {
        attackEvent = new cMessage("attackEvent");
        mode = par("attackMode"); // مقداردهی از فایل ini
        scheduleAt(simTime() + uniform(2.0, 3.0), attackEvent);
    }

    virtual void handleMessage(cMessage *msg) override {
        LightIoTMessage *fake = new LightIoTMessage("FakePacket");

        if (mode == 1) {
            fake->setId(fakeId);             // ثابت نگه‌داشتن ID
            fake->setHmac("VALID");          // بازپخش معتبر
        } else {
            fake->setId(fakeId++);
            fake->setHmac("INVALID");        // جعل HMAC در MITM
        }

        fake->setTimestamp(simTime() - 2);   // بازپخش قدیمی
        send(fake, "out");

        scheduleAt(simTime() + uniform(2.0, 3.0), attackEvent);
    }

    virtual void finish() override {
        cancelAndDelete(attackEvent);
        EV << "[FakeNode] Attack simulation completed.\n";
    }
};

Define_Module(FakeNode);