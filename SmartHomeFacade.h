#ifndef SMARTHOMEFACADE_H
#define SMARTHOMEFACADE_H
#include "SmartHomeHub.h"
#include "DeviceGroup.h"
#include "IDeviceFactory.h"
using namespace std;

enum class AutomationMode { ENERGY_SAVING, COMFORT };

class SmartHomeFacade {
private:
    SmartHomeHub& hub;
    IDeviceFactory* factory;
    AutomationMode currentMode;
public:
    SmartHomeFacade(IDeviceFactory* f) 
        : hub(SmartHomeHub::getInstance()), factory(f), currentMode(AutomationMode::COMFORT) {}

    // ── Automation Mode Switch (switchable at runtime) ────────────────────
    void setMode(AutomationMode mode) {
        currentMode = mode;
        if (currentMode == AutomationMode::ENERGY_SAVING) {
            cout << "=== ENERGY SAVING MODE ACTIVATED ===" << endl;
            cout << "Lights will dim/turn off when rooms are unoccupied." << endl;
            hub.turnOffAllDevices();
        } else {
            cout << "=== COMFORT MODE ACTIVATED ===" << endl;
            cout << "Lights and temperature set to preferred levels." << endl;
            hub.turnOnAllDevices();
        }
    }

    AutomationMode getMode() const { return currentMode; }

    // ── Routines ──────────────────────────────────────────────────────────
    void MorningMode(){
        cout << "Activating Morning Mode..."<< endl;
        hub.turnOnAllDevices();

    };

    void EveningMode(){
        cout << "Activating Evening Mode..."<< endl;
        hub.turnOffAllDevices();
        
    };

    void SecurityMode(){
        cout << "Activating Security Mode..."<< endl;
        hub.turnOffAllDevices();
        
    }

    Device* createDevice(string type, string name){
        Device* device = nullptr;
        if (type == "Light"){
            device = factory -> createLight(name);
        } else if (type == "Thermostat"){
            device = factory -> createThermostat(name);
        } else if (type == "SecurityCamera"){
            device = factory -> createSecurityCamera(name);
        } else if (type == "MotionSensor"){
            device = factory -> createMotionSensor(name);
        } else if (type == "DoorLock"){
            device = factory -> createDoorLock(name);
        } else {
            cout << "Unknown device type: " << type << endl;
            return nullptr;
        }

        if(device){
            hub.addDevice(device);
            return device;

        }

            return nullptr;
    }

    void showAllDevicesStatus(){
        hub.getAllDevicesStatus();
    }
       
};

#endif