#include "MachineController.h"

MachineController::MachineController(UserInterface* interface, ScoMachine* machine) {
    pInterface = interface;
    pMachine = machine;  
    pTransaction = new Transaction;
}
MachineController::~MachineController() {
    delete pTransaction;
}
void MachineController::executeAction() {
    resetAction();
}
void MachineController::resetAction() {
    pMachine->resetMachine();
    pInterface->displayWelcomeMessage(pMachine->getLogoArt());
    pMachine->toggle();
}
void MachineController::scanAction() {
    while(pTransaction->isScanning()) {
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
    pMachine->toggle();
}
void MachineController::paymentAction() {
    pTransaction->setFinalTax(pMachine->calculateTax(pTransaction->getRunningBalance()));
    pTransaction->setFinalBill(pMachine->calculateFinalBill(pTransaction->getRunningBalance()));
    pInterface->displayBalances(pTransaction->getFinalTax(), pTransaction->getFinalBill());
    if (pInterface->askIfPayingCash()) {
        pTransaction->setCashPayed(pInterface->insertCash());
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
    pInterface->askIfMoreCustomers();
    pMachine->toggle();
}
void MachineController::resultsAction() {
    pInterface->displayDayResults(pMachine->getChangeRepoBalance(), pMachine->getCashPurchaseRepoBalance(), pMachine->getDayIncome(), pMachine->getTotalIncome());
    pInterface->askIfNewDay();
    pMachine->toggle();
}
void MachineController::exitAction() {
    pInterface->displayGoodbye();
}