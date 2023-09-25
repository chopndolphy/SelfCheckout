#include "Scan.h"

void Scan::enter(MachineController* controller) {
    if (controller->getTransaction() == nullptr) {
        controller->createTransaction();
    }
    controller->scanAction();
}
void Scan::toggle(MachineController* controller) {
    if (controller->isScanning()) {
        controller->setState(Scan::getInstance());
    } else {
        controller->setState(Payment::getInstance());
    }
}
void Scan::exit(MachineController* controller) {
    
}
MachineState& Scan::getInstance() {
    static Scan singleton;
    return singleton;
}