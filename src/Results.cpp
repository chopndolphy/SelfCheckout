#include "Results.h"

void Results::enter(MachineController* controller) {
    controller->resultsAction();
}
void Results::toggle(MachineController* controller) {
    if (controller->newDay()) {
        controller->setState(Reset::getInstance());
    } else {
        controller->setState(Exit::getInstance());
    }
}
void Results::exit(MachineController* controller) {
    
}
MachineState& Results::getInstance() {
    static Results singleton;
    return singleton;
}