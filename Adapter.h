#ifndef ADAPTER_H
#define ADAPTER_H
#include "Device.h"
using namespace std;

class OldDevice {
    private:
        string name;
    public:
        OldDevice(string n) : name(n) {};
        void turnedOn() {
            cout << "Old Device " << name << " is powered ON." << endl;
        }
        void turnedOff() {
            cout << "Old Device " << name << " is powered OFF." << endl;
        }
        void getStatus() const {
            cout << "Old Device " << name << " status: Unknown (legacy device)" << endl;
        }

        string getName() const {
            return name;
        }

};

class DeviceAdapter : public Device {
    private:
        OldDevice* oldDevice;
    public:
        DeviceAdapter(OldDevice* od) : Device(od->getName()), oldDevice(od) {};
        
        void turnOn() override {
            oldDevice->turnedOn();
        }

        void turnOff() override {
            oldDevice->turnedOff();
        }

        void getStat() const override {
            oldDevice->getStatus();
        }
};

#endif



