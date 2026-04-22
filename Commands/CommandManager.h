#ifndef COMMANDMANAGER_H
#define COMMANDMANAGER_H

#include <stack>
#include "Command.h"
using namespace std;

class CommandManager {
private:
    stack<Command*> commandsHistory;

public:
    void executeCommand(Command* command) {
        command -> execute();
        commandsHistory.push(command);
    }

    void undoLastCommand() {
        if (!commandsHistory.empty()) {
            Command* lastcom = commandsHistory.top();

            lastcom -> undo();
            commandsHistory.pop();
            
        }
    }
};
#endif