#include "ScoMachine.h"


const double ScoMachine::changeRefillAmount {200};
const double ScoMachine::changeEmptiedAmount {50};

ScoMachine::ScoMachine() {
    State machineState = State::Reset;
}
void ScoMachine::resetMachine() {
    productList = pReader->readProductList();
    logoArt = pReader->readLogoArt();

    cashPurchaseRepoBalance = 0;
    changeRepoBalance = changeRefillAmount;
    dayIncome = 0;
}
void ScoMachine::updateMachine(double cashInserted, double changeGiven, double finalBill, bool moreCustomers) {
    cashPurchaseRepoBalance += cashInserted;
    changeRepoBalance -= changeGiven;
    dayIncome += finalBill;
    totalIncome += finalBill;
    // if (changeRepoBalance < changeEmptiedAmount || !moreCustomers)
    // {
    //     machineRunning = 0;
    // }
    // else
    // {
    //     machineRunning = 1;
    // }
}
void ScoMachine::advanceState() {
    machineState = stateTransitions[machineState];
}