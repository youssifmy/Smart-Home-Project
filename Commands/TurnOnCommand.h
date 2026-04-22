#ifndef TurnOnCommand_H
#define TurnOnCommand_H
#include "Command.h"
#include "../Device.h"
using namespace std;

class TurnOnCommand : public Command {
private:
    Device* device;
public:
    TurnOnCommand(Device* device) : device(device){};

    void execute() override{
        device -> turnOn();
    }

    void undo() override{
        device -> turnOff();
    }
};
#endif