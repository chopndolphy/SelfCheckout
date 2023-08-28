#include "Transaction.h"

const double Transaction::taxRate {.05};

Transaction::Transaction(std::map<std::string, int>* productMap, std::vector<Product>* productList) {
    scanning = 1;
    runningBalance = 0.0;
    transactionProductMap = productMap;
    transactionProductList = productList;
}
void Transaction::scanItem(std::string barcode) {
    if (barcode == "done") {
        scanning = 0;
        return;
    }
    scannedProducts.push_back(&transactionProductList->at(transactionProductMap->at(barcode)));
    runningBalance += scannedProducts.back()->getProductPrice();
}
void Transaction::calculateBalances() {
    runningBalancePennies = runningBalance * 100;
    finalTaxPennies = round(taxRate * runningBalancePennies);
    finalTax = finalTaxPennies / 100.00;
    finalBill = finalTax + runningBalance;
}
void Transaction::calculateChange(double cashPayed) {
    transactionCashPayed = cashPayed;
    changeOwed = transactionCashPayed - finalBill;
    centsRemaining = changeOwed * 100;
    transactionChangeQuantities.push_back(floor(centsRemaining / 100));
    centsRemaining %= 100;
    transactionChangeQuantities.push_back(floor(centsRemaining / 25));
    centsRemaining %= 25;
    transactionChangeQuantities.push_back(floor(centsRemaining / 10));
    centsRemaining %= 10;
    transactionChangeQuantities.push_back(floor(centsRemaining / 5));
    centsRemaining %= 5;
    transactionChangeQuantities.push_back(centsRemaining);
}
void Transaction::approveCredit() {
    srand (time(NULL));
    creditApprovalCode = rand() % 8999999 + 1000000;
}