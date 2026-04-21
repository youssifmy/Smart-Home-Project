#ifndef BRANDAFACTORY_H
#define BRANDAFACTORY_H
#include "IDeviceFactory.h"
#include "Lights/LEDLight.h"
#include "Thermostats/SmartThermostatA.h"
#include "MotionSensor.h"
#include "Cameras/WirelessCamera.h"
#include "DoorLock.h"

class BrandAFactory : public IDeviceFactory {
public:
    Light* createLight(string name) override {
        return new LEDLight(name);
    }

    Thermostat* createThermostat(string name) override {
        return new SmartThermostatA(name);
    }

    SecurityCamera* createSecurityCamera(string name) override {
        return new WirelessCamera(name);
    }

    MotionSensor* createMotionSensor(string name) override {
        return new MotionSensor(name);
    }

    DoorLock* createDoorLock(string name) override {
        return new DoorLock(name);
    }
};

#endif