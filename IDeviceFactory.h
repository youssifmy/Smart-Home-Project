#ifndef IDEVICEFACTORY_H
#define IDEVICEFACTORY_H
#include "Device.h"
#include "Lights/Light.h"
#include "Thermostats/Thermostat.h"
#include "Cameras/SecurityCamera.h"
#include "MotionSensor.h"
#include "DoorLock.h"

using namespace std;

class IDeviceFactory {
public:
    virtual Light* createLight(string name) = 0;
    virtual Thermostat* createThermostat(string name) = 0;
    virtual SecurityCamera* createSecurityCamera(string name) = 0;
    virtual MotionSensor* createMotionSensor(string name) = 0;
    virtual DoorLock* createDoorLock(string name) = 0;
    virtual ~IDeviceFactory() {};

    
};
#endif
