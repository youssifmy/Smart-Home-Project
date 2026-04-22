#ifndef TurnOnGroupCommand_H
#define TurnOnGroupCommand_H
#include "Command.h"
#include "../DeviceGroup.h"
using namespace std;

class TurnOnGroupCommand : public Command {
private:
    DeviceGroup* deviceGroup;
public:
    TurnOnGroupCommand(DeviceGroup* deviceGroup) : deviceGroup(deviceGroup){};

    void execute() override{
        deviceGroup -> turnOn();
    }   

    void undo() override{
        deviceGroup -> turnOff();
    }
};
#endif