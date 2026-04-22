#ifndef LEDLIGHT_H
#define LEDLIGHT_H
#include "Light.h"
using namespace std;

class LEDLight : public Light {
public:
    LEDLight(const string& name): Light(name){
        cout << "LED Light " << name << " created." << endl;
    };
};
#endif