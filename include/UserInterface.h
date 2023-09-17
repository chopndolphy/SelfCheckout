#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <map>
#include "Product.h"
#include "Transaction.h"

class UserInterface {
    public:
        std::string readBarcode();
        bool askIfPayingCash();
        bool askIfRecieptNeeded();
        bool askIfMoreCustomers();
        double insertCash();
        bool askIfNewDay();
        void displayWelcomeMessage(const std::string &art);
        void displayScannedItems(const std::vector<Product> &scannedProducts, const double &runningBalance);
        void displayBalances(const double &finalTax, const double &finalBill);
        void displayChange(const double &cash, const double &totalChange, const std::vector<int> &changeQuantities);
        void displayCreditApproval(const int &creditApprovalCode);
        void displayReciept(const Transaction &aTransaction);
        void displayDayResults(const double &changeLeft, const double &cashBalance, const double &dayIncome, const double &totalIncome);
        void displayGoodbye();
        void displayInputError();
};