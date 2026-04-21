#ifndef BRANDBFACTORY_H
#define BRANDBFACTORY_H
#include "IDeviceFactory.h"
#include "Lights/HalogenLight.h"
#include "Thermostats/SmartThermostatB.h"
#include "MotionSensor.h"
#include "Cameras/WeirdCamera.h"
#include "DoorLock.h"

class BrandBFactory : public IDeviceFactory {
public:
    Light* createLight(string name) override {
        return new HalogenLight(name);
    }

    Thermostat* createThermostat(string name) override {
        return new SmartThermostatB(name);
    }

    SecurityCamera* createSecurityCamera(string name) override {
        return new WeirdCamera(name);
    }

    MotionSensor* createMotionSensor(string name) override {
        return new MotionSensor(name);
    }

    DoorLock* createDoorLock(string name) override {
        return new DoorLock(name);
    }
};

#endif