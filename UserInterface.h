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
        std::string cashOrCardAnswer;
        std::string recieptAnswer;
        std::string moreCustomersAnswer;
        std::string newDayAnswer;
        double cashInserted;

    
    public:
        UserInterface ( ScoMachine *s, Transaction *t );
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
        void dayReset();
};