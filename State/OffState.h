#ifndef OFFSTATE_H
#define OFFSTATE_H
#include "DeviceState.h"
class OffState : public IDeviceState {
public:
    void turnOn(Light* light) override;         // defined in Light.h
    void turnOff(Light* light) override {
        cout << "Light is already OFF." << endl;
    }
    void AdjBrightness(Light* light, int level) override; // defined in Light.h
    void getStat(const Light* light) const override { cout << "OFF" << endl; }
};
#endif