#ifndef SMARTTHERMOSTATA_H
#define SMARTTHERMOSTATA_H
#include "thermostat.h"
using namespace std;
class SmartThermostatA : public Thermostat {
public:
    SmartThermostatA(string name) : Thermostat(name){
        cout << "Smart Thermostat A " << name << " created." << endl;
    }
};
#endif
