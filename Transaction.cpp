#include "Transaction.h"

const double Transaction::taxRate {.05};
const std::vector <std::vector<std::string>> Transaction::productList {
    {"Meat01       ", "T-Bone Steak                       ", "7.99"},
    {"Meat02       ", "Tyson Fresh Chicken Wings          ", "10.00"},
    {"Icecream01   ", "Chocolate Ice Cream                ", "2.50"},
    {"Iceceam02    ", "Vanilla Ice Cream                  ", "2.50"},
    {"Corn01       ", "Fresh Sweet Corn                   ", "2.00"},
    {"Casewater01  ", "24 Bottles 16-Oz of Deer Park Water", "4.99"},
    {"Potatochips01", "Plain Potato Chips                 ", "2.00"},
    {"Potatochips02", "Green Onion Potato Chips           ", "2.00"},
    {"Donuts01     ", "Glazed Donuts One-Dozen            ", "4.99"},
    {"Saugage01    ", "8-Sausage Pack                     ", "4.99"},
    {"Eggs01       ", "Dozen Eggs                         ", "3.00"},
    {"Milk01       ", "Gallon Milk                        ", "4.00"}
};
Transaction::Transaction() {
    scanning = 1;
}
void Transaction::scanItem(std::string barcode) {
    if (barcode == "done") {
        scanning = 0;
        return;
    }
    scannedProducts.push_back(productList.at(stoi(barcode)));
    runningBalance += stod(scannedProducts.back().at(2));
}
void Transaction::calculateBalances() {
    runningBalancePennies = runningBalance * 100;
    finalTaxPennies = round(taxRate * runningBalancePennies);
    finalTax = finalTaxPennies / 100.00;
    finalBill = finalTax + runningBalance;
}
void Transaction::calculateChange(double cashPayed) {
    changeOwed = cashPayed - finalBill;
    centsRemaining = changeOwed * 100;
    changeDollars = floor(centsRemaining / 100);
    centsRemaining %= 100;
    changeQuarters = floor(centsRemaining / 25);
    centsRemaining %= 25;
    changeDimes = floor(centsRemaining / 10);
    centsRemaining %= 10;
    changeNickels = floor(centsRemaining / 5);
    centsRemaining %= 5;
    changePennies = centsRemaining;
}
void Transaction::approveCredit() {
    srand (time(NULL));
    creditApprovalCode = rand() % 8999999 + 1000000;
}