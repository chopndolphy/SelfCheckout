#include "Payment.h"

void Payment::enter(MachineController* controller) {
    controller->paymentAction();
}
void Payment::toggle(MachineController* controller) {
    if (controller->moreCustomers()) {
        controller->setState(Scan::getInstance());
    } else {
        controller->setState(Results::getInstance());
    }
}
void Payment::exit(MachineController* controller) {
    controller->deleteTransaction();
}
MachineState& Payment::getInstance() {
    static Payment singleton;
    return singleton;
}