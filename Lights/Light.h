#ifndef LIGHT_H
#define LIGHT_H
#include<iostream>
#include<string>
#include"../Device.h"
#include"../Observer.h"
#include"../State/DeviceState.h"
#include "../State/OnState.h"
#include "../State/OffState.h"
#include "../State/AdujstState.h"
using namespace std;


class OnState;
class OffState;
class AdjustState;

class Light: public Device, public ISubject, public IObserver {
private:
    int brightness;
    bool isOn;
    IDeviceState* currentState;

public:
 
    Light(string name);

  
    void turnOn() override  { currentState->turnOn(this); }
    void turnOff() override { currentState->turnOff(this); }

    virtual void AdjBrightness(int level) { currentState->AdjBrightness(this, level); }

    void getStat() const override {
        cout << "Light " << name << " | brightness: " << brightness << "% | state: ";
        currentState->getStat(this);
    }

  
    void setState(IDeviceState* newState) {
        delete currentState;
        currentState = newState;
    }

   
    void setIsOn(bool v)      { isOn = v; }
    void setBrightness(int b) { brightness = b; }
    bool getIsOn() const      { return isOn; }
    int  getBrightness() const { return brightness; }
    string getLightName() const { return name; }

    void update(const string& event, const string& sourceName) override {
        if (event == "Motion Detected") {
            cout << "Light " << name << " AUTO-ON triggered by " << sourceName << endl;
            turnOn();
        }
    }

    virtual ~Light() { delete currentState; }
};

inline Light::Light(string name)
    : Device(name), isOn(false), brightness(0), currentState(new OffState()) {}


inline void OnState::turnOff(Light* light) {
    light->setIsOn(false);
    light->setBrightness(0);
    cout << "Light " << light->getLightName() << " turned OFF." << endl;
    light->notify("Light Turned Off", light->getLightName());
    light->setState(new OffState());
}
inline void OnState::AdjBrightness(Light* light, int level) {
    light->setBrightness(level);
    cout << "Light " << light->getLightName() << " dimmed to " << level << "%" << endl;
    light->notify("Brightness Adjusted", light->getLightName());
    light->setState(new AdjustState());
}


inline void OffState::turnOn(Light* light) {
    light->setIsOn(true);
    light->setBrightness(100);
    cout << "Light " << light->getLightName() << " turned ON." << endl;
    light->notify("Light Turned On", light->getLightName());
    light->setState(new OnState());
}
inline void OffState::AdjBrightness(Light* light, int level) {
    cout << "Cannot dim - Light " << light->getLightName() << " is OFF." << endl;
}

inline void AdjustState::turnOn(Light* light) {
    light->setIsOn(true);
    light->setBrightness(100);
    cout << "Light " << light->getLightName() << " turned fully ON from DIMMED." << endl;
    light->notify("Light Turned On", light->getLightName());
    light->setState(new OnState());
}
inline void AdjustState::turnOff(Light* light) {
    light->setIsOn(false);
    light->setBrightness(0);
    cout << "Light " << light->getLightName() << " turned OFF from DIMMED." << endl;
    light->notify("Light Turned Off", light->getLightName());
    light->setState(new OffState());
}




#endif