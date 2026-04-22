#ifndef HALOGENLIGHT_H
#define HALOGENLIGHT_H
#include "Light.h"
using namespace std;
class HalogenLight : public Light {
public:
    HalogenLight(const string& name): Light(name){
        cout << "Halogen Light " << name << " created." << endl;
    }
};
#endif