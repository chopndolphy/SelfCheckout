#pragma once

#include <iostream>
#include <string>
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
        bool newDay {1};
        bool moreCustomers {1};

    
    public:
        UserInterface ( ScoMachine *s );
        void iBarcode();
        void iPaymentType();
        void iReciept();
        void iMoreCustomers();
        void iCashInserted();
        void iNewDay();
        void oWelcomeMessage();
        void oScannedItems();
        void oBalances();
        void oPaymentTypePrompt();
        void oInsertCashPrompt();
        void oChange();
        void oCreditApproval();
        void oRecieptPrompt();
        void oReciept();
        void oMoreCustomersPrompt();
        void oDayResults();
        void oGoodbye();
        void dayReset();
        void transaction();
        bool getNewDay();
        double getCashInserted();
};