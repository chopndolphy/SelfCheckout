#include "ScoMachine.h"


const double ScoMachine::changeRefillAmount {200};
const double ScoMachine::changeEmptiedAmount {50};

ScoMachine::ScoMachine() {
    machineState = State::Reset;
    machineProductMap = makeProductMap("CSV_Files/product_list.csv");
    logoArt = makeLogoArt("CSV_Files/logo_art.csv");
}
void ScoMachine::resetMachine() {
    cashPurchaseRepoBalance = 0;
    changeRepoBalance = changeRefillAmount;
    dayIncome = 0;
}
void ScoMachine::updateMachine(double cashInserted, double changeGiven, double finalBill) {
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
    std::vector<std::vector<std::string>> productMapFile = Reader::readCSV(fileName);
    std::vector<Product> products;
    std::map<std::string, Product*> productMap;
    for (size_t i = 0; i < productMapFile.size(); i++) {
        products.emplace_back(productMapFile.at(i).at(0), productMapFile.at(i).at(1), productMapFile.at(i).at(2));
        productMap.emplace(productMapFile.at(i).at(0), &products.back());
    }
    return productMap;
}
std::string ScoMachine::makeLogoArt(std::string fileName) {
    std::vector<std::vector<std::string>> logoArtFile = Reader::readCSV(fileName);
    std::string logoString;
    for (size_t i = 0; i < logoArtFile.size(); i++) {
        for (size_t j = 0; j < logoArtFile.at(i).size(); j++) {
            logoString.append(logoArtFile.at(i).at(j));
        }
        logoString.append("\n");
    }
    return logoString;
}