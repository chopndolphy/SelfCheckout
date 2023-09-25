#include "Reset.h"

void Reset::enter(MachineController* controller) {

}
void Reset::toggle(MachineController* controller) {
    controller->resetAction();
    controller->setState(Scan::getInstance());
}
void Reset::exit(MachineController* controller) {

}
MachineState& Reset::getInstance() {
    static Reset singleton;
    return singleton;
}