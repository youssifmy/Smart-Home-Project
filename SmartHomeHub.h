#ifndef SMARTHOMEHUB_H
#define SMARTHOMEHUB_H
#include <vector>
#include <algorithm>
#include <iostream>
#include "Device.h"
#include "Commands/Command.h"
#include "Commands/CommandManager.h"
#include "DeviceGroup.h"
using namespace std;

class SmartHomeHub {
private:
    vector<Device*> devices;
    vector<DeviceGroup*> deviceGroups;
    CommandManager commandManager;

    SmartHomeHub() {};
    SmartHomeHub(const SmartHomeHub&) = delete;
    SmartHomeHub& operator=(const SmartHomeHub&) = delete;

public:
    static SmartHomeHub& getInstance(){
        static SmartHomeHub instance;
        return instance;
    }

    void addDevice(Device* device){
        devices.push_back(device);
        cout << "Device " << device -> getName() << " is added to the Smart Home Hub." << endl;
    }

    void addDeviceGroup(DeviceGroup* group){
        deviceGroups.push_back(group);
        cout << "Device Group " << group -> getName() << " is added to the Smart Home Hub." << endl;
    }

    void removeDevice(Device* device){
        devices.erase(remove(devices.begin(), devices.end(), device), devices.end());
        cout << "Device " << device -> getName() << " is removed from the Smart Home Hub." << endl;
    }

    void removeDeviceGroup(DeviceGroup* group){
        deviceGroups.erase(remove(deviceGroups.begin(), deviceGroups.end(), group), deviceGroups.end());
        cout << "Device Group " << group -> getName() << " is removed from the Smart Home Hub." << endl;
    }

    void executeCommand(Command* command){
        commandManager.executeCommand(command);
    }

    void undoLastCommand(){
        commandManager.undoLastCommand();
    }


    void turnOnAllDevices(){
        cout << "Turning on all devices in the Smart Home Hub." << endl;
        for (auto device : devices){
            device -> turnOn();
        }
    }

    void turnOffAllDevices(){
        cout << "Turning off all devices in the Smart Home Hub." << endl;
        for (auto device : devices){
            device -> turnOff();
        }
    }

    void getAllDevicesStatus() const{
        cout << "Status of all devices in the Smart Home Hub:" << endl;
        for (auto device : devices){
            device -> getStat();
        }
        for (auto group : deviceGroups){
            cout << "Status of device group " << group -> getName() << ":" << endl;
            for (auto device : group -> getDevices()){
                device -> getStat();
            }
        }
    }
    
};


#endif
