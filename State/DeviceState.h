#ifndef DEVICESTATE_H
#define DEVICESTATE_H
#include <iostream>
#include <string>
using namespace std;
class Light;

class IDeviceState {
    public:
        virtual void turnOn(Light* light) = 0;
        virtual void turnOff(Light* light) = 0;
        virtual void AdjBrightness(Light* light, int level) = 0;
        virtual void getStat(const Light* light) const = 0;
        virtual ~IDeviceState() {};
};

#endif