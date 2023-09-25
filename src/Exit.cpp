#include "Exit.h"

void Exit::enter(MachineController* controller) {
    controller->exitAction();
}
void Exit::toggle(MachineController* controller) {

}
void Exit::exit(MachineController* controller) {
    
}
MachineState& Exit::getInstance() {
    static Exit singleton;
    return singleton;
}