#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include"../Device.h"
using namespace std;

class Thermostat : public Device {
private:
    double currentTemp;
    double targetTemp;
    bool isOn;
    string mode;

public:
    Thermostat(string name): Device(name) , currentTemp(20.0) , targetTemp(26.0) , mode("Heating") , isOn(false){};

    virtual void turnOn() override{
        isOn = true;
        cout << "Thermostat " << name << " is On || current temperature is :" << currentTemp << "C" << endl;
    }

    virtual void turnOff() override{
        isOn = false;
        cout << "Thermostat " << name << " is Off || current temperature is :" << currentTemp << "C" << endl;
    }

    virtual void setTargetTemp(double temp){
        targetTemp = temp;
        cout << "Thermostat " << name << " target temperature is set to :" << targetTemp << "C" << endl;
    }

    virtual void setMode(string m){
        mode = m;
        cout << "Thermostat " << name << " mode is set to :" << mode << endl;
    }

    virtual void getStat() const{
        cout << "Thermostat " << name << " is " << (isOn ? "On" : "Off") 
        << ", current temperature is " << currentTemp 
        << "C, target temperature is " << targetTemp << "C, mode is " << mode << endl;
    }
};


#endif