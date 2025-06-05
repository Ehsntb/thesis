#include <omnetpp.h>
#include "LightIoTMessage_m.h"

using namespace omnetpp;

class CloudServer : public cSimpleModule {
  private:
    int received = 0;
    simtime_t totalDelay = 0;

  protected:
    virtual void handleMessage(cMessage *msg) override {
        LightIoTMessage *m = check_and_cast<LightIoTMessage *>(msg);
        simtime_t delay = simTime() - m->getTimestamp();

        EV << "[CloudServer] Received message ID=" << m->getId()
           << " | Delay: " << delay << "s\n";

        totalDelay += delay;
        received++;

        delete m;
    }

    virtual void finish() override {
        double avgDelay = (received > 0) ? totalDelay.dbl() / received : 0.0;

        EV << "[CloudServer] Total Messages Received: " << received << endl;
        EV << "[CloudServer] Average End-to-End Delay: " << avgDelay << " seconds" << endl;
    }
};

Define_Module(CloudServer);