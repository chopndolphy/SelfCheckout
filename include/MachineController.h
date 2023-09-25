#pragma once
#include "ScoMachine.h"
#include "UserInterface.h"
#include "Transaction.h"
#include "MachineState.h"
#include "Reset.h"
#include "Scan.h"
#include "Payment.h"
#include "Results.h"
#include "Exit.h"

class MachineState;
class MachineController {
    public:
        MachineController(UserInterface* interface, ScoMachine* machine);
        ~MachineController();
        void resetAction();
        void scanAction();
        void paymentAction();
        void resultsAction();
        void exitAction();
        void createTransaction();
        void deleteTransaction();
        bool moreCustomers() const {
            return pInterface->askIfMoreCustomers();
        }
        bool newDay() const {
            return pInterface->askIfNewDay();
        }
        MachineState* getCurrentState() const {
            return currentState;
        }
        bool isScanning() const {
            return pTransaction->isScanning();
        }
        void setState(MachineState& newState);
        void toggle();
        const Transaction* getTransaction() const {
            return pTransaction;
        }
    private:
        UserInterface* pInterface;
        ScoMachine* pMachine;
        Transaction* pTransaction;
        MachineState* currentState;

        
};