#include <omnetpp.h>
#include "LightIoTMessage_m.h"
#include <set>

using namespace omnetpp;

class GatewayNode : public cSimpleModule {
  private:
    int received = 0;
    int forwarded = 0;
    int dropped = 0;

    double battery = 5000.0;      // میلی‌ژول
    double costPerMsg = 10.0;     // مصرف هر پردازش

    std::set<int> seenIds;        // پیام‌هایی که قبلاً دیده شده‌اند

  protected:
    virtual void handleMessage(cMessage *msg) override {
        LightIoTMessage *m = check_and_cast<LightIoTMessage *>(msg);
        received++;

        if (battery < costPerMsg) {
            EV << "[GatewayNode] Battery depleted. Dropping message.\n";
            dropped++;
            delete m;
            return;
        }

        if (seenIds.count(m->getId())) {
            EV << "[GatewayNode] Duplicate message ID=" << m->getId() << " → Dropped\n";
            dropped++;
            delete m;
            return;
        }

        if (strcmp(m->getHmac(), "VALID") != 0) {
            EV << "[GatewayNode] Invalid HMAC → Dropped\n";
            dropped++;
            delete m;
            return;
        }

        seenIds.insert(m->getId());
        forwarded++;
        battery -= costPerMsg;

        send(m, "out");
    }

    virtual void finish() override {
        double percent = (battery / 5000.0) * 100;
        EV << "[GatewayNode] Received=" << received
           << ", Forwarded=" << forwarded
           << ", Dropped=" << dropped << endl;

        EV << "[GatewayNode] Energy Remaining: " << battery
           << " mJ (" << percent << "%)\n";
    }
};

Define_Module(GatewayNode);