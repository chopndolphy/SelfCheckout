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
        std::string barcodeString;
        std::string paymentType;
        std::string recieptAnswer;
        std::string moreCustomersAnswer;
        std::string newDayAnswer;
        double cashInserted {0};
        bool running {1};
        bool moreCustomers {1};
        std::vector<std::string> availableBarcodes;

    
    public:
        UserInterface ();
        std::string readBarcode();
        bool askIfPayingCash();
        bool askIfRecieptNeeded();
        bool askIfMoreCustomers();
        double insertCash();
        bool askIfNewDay();
        void displayWelcomeMessage(std::string art);
        void displayScannedItems(std::vector<Product*> scannedProducts, size_t scannedProductsSize, double runningBalance);
        void displayBalances();
        void displayPaymentTypePrompt();
        void displayInsertCashPrompt();
        void displayChange();
        void displayCreditApproval();
        void displayRecieptPrompt();
        void displayReciept();
        void displayMoreCustomersPrompt();
        void displayDayResults();
        void dayReset();
        void runTransactions();
        void displayGoodbye();
        
        bool isRunning() {
            return running;
        }   
};