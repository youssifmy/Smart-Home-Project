#ifndef DOORLOCK_H
#define DOORLOCK_H
#include "Device.h"
#include "Observer.h"
using namespace std;
class DoorLock : public Device , public ISubject {
private:
    bool isLocked;
public:
    DoorLock(string name) : Device(name) , isLocked(false){};
    
    void lock(){
        isLocked = true;
        cout << "Door Lock " << name << " is locked." << endl;
        notify("Door Locked", name);
    }

    void unlock(){
        isLocked = false;
        cout << "Door Lock " << name << " is unlocked." << endl;
        notify("Door Unlocked", name);
    }

    void turnOn() override{
        lock();
        
    }

    void turnOff() override{
        unlock();
    }

    void getStat() const override{
        cout << "Door Lock " << name << " is " << (isLocked ? "locked" : "unlocked") << endl;
    }
};
#endif