#include "UserInterface.h"

std::string UserInterface::readBarcode() {
    std::string currentBarcode;
    std::cin >> currentBarcode;
    return currentBarcode;
}
bool UserInterface::askIfPayingCash() {
    std::string paymentType;
    std::cout << "\nHow would you like to pay? (cash/card) ";
    while (true) {
        std::cin >> paymentType;
        if (paymentType == "cash") {
            return true;
        } else if (paymentType == "card") {
            return false;
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
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
    double cashInserted;
    std::cout << "Please insert your payment: $";
    while (1) {
        if (std::cin >> cashInserted) {
            return cashInserted;
        } else {
            std::cout << "Invalid input. Try again." << std::endl;
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
void UserInterface::displayWelcomeMessage(const std::string &art) {
    system("clear");
    std::cout << "Welcome to Self-Checkout at Chris' Gross Grocery Grove!" << std::endl;
    std::cout << art << std::endl;
    std::cout << "\nEnter barcode number to begin scanning" << std::endl;
}
void UserInterface::displayScannedItems(const std::vector<Product> &scannedProducts, const double &runningBalance) {
    system("clear");
    for (size_t i = 0; i < scannedProducts.size(); i++) {
        std::string fillerSpace1;
        std::string fillerSpace2;
        std::cout << i+1 << " | " << scannedProducts.at(i).getProductID() << fillerSpace1.append(13-scannedProducts.at(i).getProductID().length(), ' ') << " | " << scannedProducts.at(i).getProductName() << fillerSpace2.append(35-scannedProducts.at(i).getProductName().length(), ' ') << " | $" << scannedProducts.at(i).getProductPrice() << std::endl;
        }
    std::cout << "\n(Type 'done' to finish scanning.                 Balance: $" << runningBalance << std::endl;
}
void UserInterface::displayBalances(const double &finalTax, const double &finalBill) {
    std::cout << "\n                                                     Tax: $" << finalTax << std::endl;
    std::cout << "\n                                              Final Bill: $" << finalBill << std::endl;
}
void UserInterface::displayChange(const double &cash, const double &totalChange, const std::vector<int> &changeQuantities) {
    std::cout << "\nYou inserted: $" << cash << std::endl;
    std::cout << "Your change: $" << totalChange << std::endl;
    std::cout << "Dollars: " << changeQuantities.at(0) << std::endl;
    std::cout << "Quarters: " << changeQuantities.at(1) << std::endl;
    std::cout << "Dimes: " << changeQuantities.at(2) << std::endl;
    std::cout << "Nickels: " << changeQuantities.at(3) << std::endl;
    std::cout << "Pennies: " << changeQuantities.at(4) << std::endl;
}
void UserInterface::displayCreditApproval(const int &creditApprovalCode) {
    std::cout << "Your purchase was successful! (verification code: " << creditApprovalCode << ")" << std::endl;
}
void UserInterface::displayReciept(const Transaction &aTransaction) {
    system("clear");
    std::cout << "Chris' Gross Grocery Grove" << std::endl;
    std::cout << "\nItems purchased:" << std::endl;
    for (size_t i = 0; i < aTransaction.getScannedProducts().size(); i++) {
        std::string fillerSpace;
        std::cout << aTransaction.getScannedProducts().at(i).getProductID() << fillerSpace.append(13-aTransaction.getScannedProducts().at(i).getProductID().length(), ' ') << "   $" << aTransaction.getScannedProducts().at(i).getProductPrice() << std::endl;
    }
    std::cout << "\nItem Balance:   $" << aTransaction.getRunningBalance() << std::endl;
    std::cout << "Tax Total:      $" << aTransaction.getFinalTax() << std::endl;
    std::cout << "Final Bill:     $" << aTransaction.getFinalBill() << std::endl;
    if (aTransaction.getCreditApprovalCode() > 0) {
        std::cout << "\nCard verification code: " << aTransaction.getCreditApprovalCode() << std::endl;
    } else {
        std::cout << "Cash inserted:  $" << aTransaction.getCashPayed() << std::endl;
        std::cout << "Change:         $" << aTransaction.getChangeOwed() << std::endl;
    }
    std::cout << "\nThank you for shopping!" << std::endl;
}
void UserInterface::displayDayResults(const double &changeLeft, const double &cashBalance, const double &dayIncome, const double &totalIncome) {
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
void UserInterface::displayInputError() {
    std::cout << "Invalid input. Try again." << std::endl;
}