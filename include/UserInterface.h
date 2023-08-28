#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include "Product.h"
#include "Transaction.h"

class UserInterface {
    private:
        std::string paymentType;
        double cashInserted {0};
        std::vector<std::string> availableBarcodes;
    
    public:
        UserInterface (std::map<std::string, Product*> productMap);
        std::string readBarcode();
        bool askIfPayingCash();
        bool askIfRecieptNeeded();
        bool askIfMoreCustomers();
        double insertCash();
        bool askIfNewDay();
        void displayWelcomeMessage(std::string art);
        void displayScannedItems(std::vector<Product*> scannedProducts, double runningBalance);
        void displayBalances(double finalTax, double finalBill);
        void displayChange(double cash, double totalChange, std::vector<int> changeQuantities);
        void displayCreditApproval(int creditApprovalCode);
        void displayReciept(Transaction* aTransaction);
        void displayDayResults(double changeLeft, double cashBalance, double dayIncome, double totalIncome);
        void displayGoodbye();
};