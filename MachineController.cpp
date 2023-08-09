#include "MachineController.h"

MachineController::MachineController(UserInterface* interface, ScoMachine* machine) {
    pInterface = interface;
    pMachine = machine;
}
void MachineController::executeAction() {
    switch (pMachine->getState()) {
        case State::Reset:
            resetAction();
            break;
        case State::Scan:
            scanAction();
            break;
        case State::Payment:
            paymentAction();
            break;
        case State::Results:
            resultsAction();
        default:
            break;
    }
    pMachine->advanceState();
}
void MachineController::resetAction() {
    pMachine->resetMachine();
    pInterface->displayWelcomeMessage();
}
void MachineController::scanAction() {
    Transaction t;
    Transaction* pTransaction;
    while(pTransaction->isScanning()) {
        pTransaction->scanItem(pInterface->readBarcode());
        pInterface->displayScannedItems();
    }
}
void MachineController::paymentAction() {

}
void MachineController::resultsAction() {

}
void MachineController::exitAction() {
    pInterface->displayGoodbye();
}