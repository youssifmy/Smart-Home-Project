#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H
#include "Device.h"
#include <vector>
#include "Observer.h"
using namespace std;
class MotionSensor : public Device, public ISubject {
private:
    bool isOn;
    vector<Device*> linkedDevices;
public:
    MotionSensor(string name) : Device(name) , isOn(false){};

    void turnOn() override{
        isOn = true;
        cout << "Motion Sensor " << name << " is turned ON." << endl;
        for (auto device : linkedDevices){
            device -> turnOn();
        }
        notify("Motion Detected", name);
    }

    void turnOff() override{
        isOn = false;
        cout << "Motion Sensor " << name << " is turned OFF." << endl;
        for (auto device : linkedDevices){
            device -> turnOff();
        }
            notify("Motion Stopped", name);
    }

    void linkDevice(Device* device){
        linkedDevices.push_back(device);
        cout << "Device " << device -> getName() << " is linked to Motion Sensor " << name << "." << endl;
    }

    void getStat() const override{
        cout << "Motion Sensor " << name << " is " << (isOn ? "On" : "Off") 
        << ", linked devices: " << to_string(linkedDevices.size()) << endl;
    }
};
#endif
