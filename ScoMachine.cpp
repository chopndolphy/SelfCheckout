#include "ScoMachine.h"


const double ScoMachine::changeRefillAmount {200};
const double ScoMachine::changeEmptiedAmount {50};

ScoMachine::ScoMachine() {
    State machineState = State::Reset;
}
void ScoMachine::resetMachine() {
    makeProductMap("product_list.csv");

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
std::map<std::string, Product*> ScoMachine::makeProductMap(std::string fileName) {
    std::vector<std::vector<std::string>> productMapFile = pReader->readCSV(fileName);
    std::vector<Product> products;
    std::map<std::string, Product*> productMap;
    for (int i = 0; i < productMapFile.size(); i++) {
        products.emplace_back(productMapFile.at(i).at(0), productMapFile.at(i).at(1), productMapFile.at(i).at(2));
        productMap.emplace(productMapFile.at(i).at(0), products.back());
    }
    return productMap;
}