#ifndef DeVICEGROUP_H
#define DeVICEGROUP_H
#include <vector>
#include <algorithm>
#include "Device.h"
using namespace std;

class DeviceGroup : public Device {
private:
    vector<Device*> devices;
public:
    DeviceGroup(string name) : Device(name){};

    void addDevice(Device* device){
        devices.push_back(device);
    };

    void RemoveDevice(Device* device){
        devices.erase(remove(devices.begin(), devices.end(), device), devices.end());
    };

    void turnOn() override{
        cout << "turning on all devices in the group " << name << endl;
        for(auto device : devices){
            device -> turnOn();
        }

    };

    void turnOff() override{
        cout << "turning off all devices in the group " << name << endl;
        for(auto device : devices){
            device -> turnOff();
        }

    };

    void getStat() const override{
        cout << "Status of all devices in the group " << name << ":" << endl;
        for (auto device : devices){
            device -> getStat();
        }
    }

    vector<Device*> getDevices() const{
        return devices;
    }


};

#endif