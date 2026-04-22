#ifndef TurnOffCommand_H
#define TurnOffCommand_H
#include "Command.h"
#include "../Device.h"
using namespace std;

class TurnOffCommand : public Command {
private:
    Device* device;
public:
    TurnOffCommand(Device* device) : device(device){};

    void execute() override{
        device -> turnOff();
    }

    void undo() override{
        device -> turnOn();
    }
};
#endif