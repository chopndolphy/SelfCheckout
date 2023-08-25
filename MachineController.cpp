#include "MachineController.h"

MachineController::MachineController(UserInterface* interface, ScoMachine* machine) {
    pInterface = interface;
    pMachine = machine;
    Transaction t(pMachine->getProductMap());
    pTransaction = &t;
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
    pInterface->displayWelcomeMessage(pMachine->getLogoArt());
}
void MachineController::scanAction() {
    while(pTransaction->isScanning()) {
        pTransaction->scanItem(pInterface->readBarcode());
        pInterface->displayScannedItems(pTransaction->getScannedProducts(), pTransaction->getRunningBalance());
    }
}
void MachineController::paymentAction() {
    pTransaction->calculateBalances();
    pInterface->displayBalances(pTransaction->getFinalTax(), pTransaction->getFinalBill());
    if (pInterface->askIfPayingCash()) {
        pTransaction->calculateChange(pInterface->insertCash());
        pInterface->displayChange(pTransaction->getTransactionCashPayed(), pTransaction->getChangeOwed(), pTransaction->getTransactionChangeQuantities());
    } else {
        pTransaction->approveCredit();
        pInterface->displayCreditApproval(pTransaction->getCreditApprovalCode());
    }
    if (pInterface->askIfRecieptNeeded()) {
        pInterface->displayReciept(pTransaction);
    }
    pMachine->updateMachine(pTransaction->getTransactionCashPayed(), pTransaction->getChangeOwed(), pTransaction->getFinalBill());
}
void MachineController::resultsAction() {
    pInterface->displayDayResults(pMachine->getChangeRepoBalance(), pMachine->getCashPurchaseRepoBalance(), pMachine->getDayIncome(), pMachine->getTotalIncome());
}
void MachineController::exitAction() {
    pInterface->displayGoodbye();
}