#include "ConcreteMachineStates.h"

void Reset::toggle(ScoMachine* machine) {
    machine->setState(Scan::getInstance());
}
MachineState& Reset::getInstance() {
    static Reset singleton;
    return singleton;
}
void Scan::toggle(ScoMachine* machine) {
    machine->setState(Payment::getInstance());
}
MachineState& Scan::getInstance() {
    static Scan singleton;
    return singleton;
}
void Payment::toggle(ScoMachine* machine) {
    machine->setState(Results::getInstance());
}
MachineState& Payment::getInstance() {
    static Payment singleton;
    return singleton;
}
void Results::toggle(ScoMachine* machine) {
    machine->setState(Exit::getInstance());
}
MachineState& Results::getInstance() {
    static Results singleton;
    return singleton;
}
void Exit::toggle(ScoMachine* machine) {
    machine->setState(Reset::getInstance());
}
MachineState& Exit::getInstance() {
    static Exit singleton;
    return singleton;
}