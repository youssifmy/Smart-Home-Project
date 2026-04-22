#ifndef ADJUSTSTATE_H
#define ADJUSTSTATE_H
#include "DeviceState.h"
class AdjustState : public IDeviceState {
public:
    void turnOn(Light* light) override;         // defined in Light.h
    void turnOff(Light* light) override;        // defined in Light.h
    void AdjBrightness(Light* light, int level) override {
        cout << "Adjusting brightness to " << level << "%" << endl;
    }
    void getStat(const Light* light) const override { cout << "DIMMED" << endl; }
};
#endif