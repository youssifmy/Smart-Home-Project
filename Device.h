#ifndef DEVICE_H
#define DEVICE_H
#include<string>
#include<iostream>
using namespace std;
// Abstract base class for all Devices
class Device{
protected:
    string name;

public:
    Device(string name): name(name){};
    virtual ~Device(){};

    virtual void turnOn()= 0;
    virtual void turnOff() =0;

    string getName ()const{
        return name;
    };

    virtual void getStat()const = 0;

};

#endif