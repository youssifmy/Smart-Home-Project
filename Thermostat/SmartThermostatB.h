#ifndef SMARTTHERMOSTATB_H
#define SMARTTHERMOSTATB_H
#include "thermostat.h"
using namespace std;
class SmartThermostatB : public Thermostat {
public:
    SmartThermostatB(string name) : Thermostat(name){
        cout << "Smart Thermostat B " << name << " created." << endl;
    }
};
#endif
