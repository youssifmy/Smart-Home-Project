#ifndef ONSTATE_H
#define ONSTATE_H
#include "DeviceState.h"
class OnState : public IDeviceState {
public:
    void turnOn(Light* light) override {
        cout << "Light is already ON." << endl;
    }
    void turnOff(Light* light) override;        // defined in Light.h
    void AdjBrightness(Light* light, int level) override; // defined in Light.h
    void getStat(const Light* light) const override { cout << "ON" << endl; }
};
#endif