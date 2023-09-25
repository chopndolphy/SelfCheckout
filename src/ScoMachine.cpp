#include "ScoMachine.h"

const double ScoMachine::changeRefillAmount {200};
const double ScoMachine::changeEmptiedAmount {50};
const double ScoMachine::taxRate {.05};

ScoMachine::ScoMachine() {
    loadProductMap("CSV_Files/product_list.csv", machineProductMap);
    loadLogoArt("CSV_Files/logo_art.csv", logoArt);
}
void ScoMachine::resetMachine() {
    cashPurchaseRepoBalance = 0;
    changeRepoBalance = changeRefillAmount;
    dayIncome = 0;
}
void ScoMachine::updateMachine(const double &cashInserted, const double &changeGiven, const double &finalBill) {
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

void ScoMachine::loadProductMap(const std::string &fileName, std::map<std::string, Product> &productMap) {
    std::vector<std::vector<std::string>> productMapFile;
    Reader::readCSV(fileName, productMapFile);
    for (size_t i = 0; i < productMapFile.size(); i++) {
        productMap.emplace(productMapFile.at(i).at(0), Product(productMapFile.at(i).at(0), productMapFile.at(i).at(1), stod(productMapFile.at(i).at(2))));
    }
}
void ScoMachine::loadLogoArt(const std::string &fileName, std::string &logoString) {
    std::vector<std::vector<std::string>> logoArtFile;
    Reader::readCSV(fileName, logoArtFile);
    for (size_t i = 0; i < logoArtFile.size(); i++) {
        for (size_t j = 0; j < logoArtFile.at(i).size(); j++) {
            logoString.append(logoArtFile.at(i).at(j));
        }
        logoString.append("\n");
    }
}
double ScoMachine::calculateTax(const double &runningBalance) {
    int runningBalancePennies = runningBalance * 100;
    int finalTaxPennies = round(taxRate * runningBalancePennies);
    return finalTaxPennies / 100.00;
}
double ScoMachine::calculateFinalBill(const double &runningBalance) {
    int runningBalancePennies = runningBalance * 100;
    int finalTaxPennies = round(taxRate * runningBalancePennies);
    int finalTax = finalTaxPennies / 100.00;
    return finalTax + runningBalance;
}
std::vector<int> ScoMachine::calculateChange(const double &changeOwed) {
    std::vector<int> transactionChangeQuantities;
    int centsRemaining = changeOwed * 100;
    transactionChangeQuantities.push_back(floor(centsRemaining / 100));
    centsRemaining %= 100;
    transactionChangeQuantities.push_back(floor(centsRemaining / 25));
    centsRemaining %= 25;
    transactionChangeQuantities.push_back(floor(centsRemaining / 10));
    centsRemaining %= 10;
    transactionChangeQuantities.push_back(floor(centsRemaining / 5));
    centsRemaining %= 5;
    transactionChangeQuantities.push_back(centsRemaining);
    return transactionChangeQuantities;
}
int ScoMachine::approveCredit() {
    srand (time(NULL));
    return rand() % 8999999 + 1000000;
}
bool ScoMachine::setCurrentBarcode(const std::string &barcode) {
    if (barcode == "done") {
        currentBarcode = barcode;
        return true;
    } else if (machineProductMap.count(barcode) == 0) {
        return false;
    } else {
        currentBarcode = barcode;
        return true;
    }
}
Product ScoMachine::getItem(const std::string &barcode) {
    return machineProductMap.at(barcode);
}
Transaction* ScoMachine::createTransaction() {
    currentTransaction = new Transaction;
    return currentTransaction;
}
void ScoMachine::deleteTransaction() {
    delete currentTransaction;
}