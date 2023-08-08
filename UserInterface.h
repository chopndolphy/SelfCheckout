#pragma once

#include <iostream>
#include <string>
#include <limits>
#include "ScoMachine.h"
#include "Transaction.h"

class UserInterface
{
    private:
        ScoMachine *aScoMachine;
        Transaction *aTransaction;
        std::string barcodeString;
        std::string paymentType;
        std::string recieptAnswer;
        std::string moreCustomersAnswer;
        std::string newDayAnswer;
        double cashInserted {0};
        bool running {1};
        bool moreCustomers {1};
        bool success {0};
        std::vector<std::string> availableBarcodes;

    
    public:
        UserInterface ( ScoMachine *s );
        void readBarcode();
        void specifyPaymentType();
        void askIfRecieptNeeded();
        void askIfMoreCustomers();
        void insertCash();
        void askIfNewDay();
        void displayWelcomeMessage();
        void displayScannedItems();
        void displayBalances();
        void displayPaymentTypePrompt();
        void displayInsertCashPrompt();
        void displayChange();
        void displayCreditApproval();
        void displayRecieptPrompt();
        void displayReciept();
        void displayMoreCustomersPrompt();
        void displayDayResults();
        void displayGoodbye();
        void dayReset();
        void runTransactions();
        bool isRunning();
        double getCashInserted();
};