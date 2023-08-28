#include "UserInterface.h"

UserInterface::UserInterface(std::map<std::string, Product*> productMap) {
    for (auto const& product : productMap) {
        availableBarcodes.push_back(product.first);
    }
    availableBarcodes.push_back("done");
}
std::string UserInterface::readBarcode() {
    std::string barcodeString;
    while (1) {
        std::cin >> barcodeString;
        if (std::find(std::begin(availableBarcodes), std::end(availableBarcodes), barcodeString) != std::end(availableBarcodes)) {
            return barcodeString;
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
        }
    }
}
bool UserInterface::askIfPayingCash() {
    std::cout << "\nHow would you like to pay? (cash/card) ";
    while (1) {
        std::cin >> paymentType;
        if (paymentType == "cash") {
            return 1;
        } else if (paymentType == "card") {
            return 0;
        } else {
            std::cout << "Invalide input. Try again." << std::endl;
        }
    }
}
bool UserInterface::askIfRecieptNeeded() {
    std::string recieptAnswer;
    std::cout << "\nWould you like a reciept? (yes/no) ";
    while (1) {
        std::cin >> recieptAnswer;
        if (recieptAnswer == "yes") {
            return 1;
        } else if (recieptAnswer == "no") {
            return 0;
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
        }
    }
}
bool UserInterface::askIfMoreCustomers() {
    std::string moreCustomersAnswer;
    std::cout << "\nAre there more customers for today? (yes/no) " << std::endl;
    while (1) {
        std::cin >> moreCustomersAnswer;
        if (moreCustomersAnswer == "yes") {
            return 1;
        } else if (moreCustomersAnswer == "no") {
            return 0;
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
        }
    }
}
 double UserInterface::insertCash() {
    std::cout << "Please insert your payment: $";
    while (1) {
        if (std::cin >> cashInserted) {
            return cashInserted;
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
bool UserInterface::askIfNewDay() {
    std::string newDayAnswer;
    std::cout << "\nBegin next day? (yes/no) ";
    while (1) {
        std::cin >> newDayAnswer;
        if (newDayAnswer == "no") {
            return 0;
        } else if (newDayAnswer == "yes") {
            return 1;
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
        }
    }
}
void UserInterface::displayWelcomeMessage(std::string art) {
    system("clear");
    std::cout << "Welcome to Self-Checkout at Chris' Gross Grocery Grove!" << std::endl;
    std::cout << art << std::endl;
    std::cout << "\nEnter barcode number to begin scanning" << std::endl;
}
void UserInterface::displayScannedItems(std::vector<Product*> scannedProducts, double runningBalance) {
    system("clear");
    for (size_t i = 0; i < scannedProducts.size(); i++) {
        std::cout << i+1 << " | " << scannedProducts.at(i)->getProductID().append(13-scannedProducts.at(i)->getProductID().length(), ' ') << " | " << scannedProducts.at(i)->getProductName().append(35-scannedProducts.at(i)->getProductName().length(), ' ') << " | $" << scannedProducts.at(i)->getProductPrice() << std::endl;
        }
    std::cout << "\n(Type 'done' to finish scanning.                 Balance: $" << runningBalance << std::endl;
}
void UserInterface::displayBalances(double finalTax, double finalBill) {
    std::cout << "\n                                                     Tax: $" << finalTax << std::endl;
    std::cout << "\n                                              Final Bill: $" << finalBill << std::endl;
}
void UserInterface::displayChange(double cash, double totalChange, std::vector<int> changeQuantities) {
    std::cout << "\nYou inserted: $" << cash << std::endl;
    std::cout << "Your change: $" << totalChange << std::endl;
    std::cout << "Dollars: " << changeQuantities.at(0) << std::endl;
    std::cout << "Quarters: " << changeQuantities.at(1) << std::endl;
    std::cout << "Dimes: " << changeQuantities.at(2) << std::endl;
    std::cout << "Nickels: " << changeQuantities.at(3) << std::endl;
    std::cout << "Pennies: " << changeQuantities.at(4) << std::endl;
}
void UserInterface::displayCreditApproval(int creditApprovalCode) {
    std::cout << "Your purchase was successful! (verification code: " << creditApprovalCode << ")" << std::endl;
}
void UserInterface::displayReciept(Transaction* aTransaction) {
    system("clear");
    std::cout << "Chris' Gross Grocery Grove" << std::endl;
    std::cout << "\nItems purchased:" << std::endl;
    for (size_t i = 0; i < aTransaction->getScannedProducts().size(); i++) {
        std::cout << aTransaction->getScannedProducts().at(i)->getProductID().append(13-aTransaction->getScannedProducts().at(i)->getProductID().length(), ' ') << "   $" << aTransaction->getScannedProducts().at(i)->getProductPrice() << std::endl;
    }
    std::cout << "\nItem Balance:   $" << aTransaction->getRunningBalance() << std::endl;
    std::cout << "Tax Total:      $" << aTransaction->getFinalTax() << std::endl;
    std::cout << "Final Bill:     $" << aTransaction->getFinalBill() << std::endl;
    if (paymentType == "card") {
        std::cout << "\nCard verification code: " << aTransaction->getCreditApprovalCode() << std::endl;
    } else {
        std::cout << "Cash inserted:  $" << aTransaction->getTransactionCashPayed() << std::endl;
        std::cout << "Change:         $" << aTransaction->getChangeOwed() << std::endl;
    }
    std::cout << "\nThank you for shopping!" << std::endl;
}
void UserInterface::displayDayResults(double changeLeft, double cashBalance, double dayIncome, double totalIncome) {
    system("clear");
    std::cout << "End of day results:" << std::endl;
    std::cout << "\nChange Repository Balance:        $" << changeLeft << std::endl;
    std::cout << "Cash Purchase Repository Balance: $" << cashBalance << std::endl;
    std::cout << "Today's Income:                   $" << dayIncome << std::endl;
    std::cout << "Total Income:                     $" << totalIncome << std::endl;
}
void UserInterface::displayGoodbye() {
            std::cout << "\nGoodbye!" << std::endl;
}