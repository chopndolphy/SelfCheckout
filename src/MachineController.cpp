#include "MachineController.h"

MachineController::MachineController(UserInterface* interface, ScoMachine* machine) {
    currentState = &Reset::getInstance();
    pInterface = interface;
    pMachine = machine;
    pTransaction = nullptr;
}
MachineController::~MachineController() {
}
void MachineController::setState(MachineState& newState) {
    currentState->exit(this);
    currentState = &newState;
    currentState->enter(this);
}
void MachineController::toggle() {
    currentState->toggle(this);
}
void MachineController::resetAction() {
    pMachine->resetMachine();
}
void MachineController::scanAction() {
    while(!pMachine->setCurrentBarcode(pInterface->readBarcode())) {
        pInterface->displayInputError();
    }
    if (pMachine->getCurrentBarcode() == "done") {
        pTransaction->setScanning(false);
        return;
    }
    pTransaction->addItem(pMachine->getItem(pMachine->getCurrentBarcode()));
    pInterface->displayScannedItems(pTransaction->getScannedProducts(), pTransaction->getRunningBalance());
}
void MachineController::paymentAction() {
    pTransaction->setFinalTax(pMachine->calculateTax(pTransaction->getRunningBalance()));
    pTransaction->setFinalBill(pMachine->calculateFinalBill(pTransaction->getRunningBalance()));
    pInterface->displayBalances(pTransaction->getFinalTax(), pTransaction->getFinalBill());
    if (pInterface->askIfPayingCash()) {
        double cashInserted = pInterface->insertCash();
        //check if enough cash.
        pTransaction->setCashPayed(cashInserted);
        pTransaction->setChangeOwed(pTransaction->getCashPayed() - pTransaction->getFinalBill());
        pTransaction->setChangeQuantities(pMachine->calculateChange(pTransaction->getChangeOwed()));
        pInterface->displayChange(pTransaction->getCashPayed(), pTransaction->getChangeOwed(), pTransaction->getChangeQuantities());
    } else {
        pTransaction->setCreditApprovalCode(pMachine->approveCredit());
        pInterface->displayCreditApproval(pTransaction->getCreditApprovalCode());
    }
    if (pInterface->askIfRecieptNeeded()) {
        pInterface->displayReciept(*pTransaction);
    }
    pMachine->updateMachine(pTransaction->getCashPayed(), pTransaction->getChangeOwed(), pTransaction->getFinalBill());
}
void MachineController::resultsAction() {
    pInterface->displayDayResults(pMachine->getChangeRepoBalance(), pMachine->getCashPurchaseRepoBalance(), pMachine->getDayIncome(), pMachine->getTotalIncome());
}
void MachineController::exitAction() {
    pInterface->displayGoodbye();
}
void MachineController::createTransaction() {
    pTransaction = pMachine->createTransaction();
    pInterface->displayWelcomeMessage(pMachine->getLogoArt());
}
void MachineController::deleteTransaction() {
    pMachine->deleteTransaction();
    pTransaction = nullptr;
}