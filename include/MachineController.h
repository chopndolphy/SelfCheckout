#pragma once
#include "ScoMachine.h"
#include "UserInterface.h"
#include "Transaction.h"
#include "MachineState.h"

class MachineController {
    public:
        MachineController(UserInterface* interface, ScoMachine* machine);
        ~MachineController();
        void executeAction();
        void exitAction();
        MachineState* getState() const {
            return pMachine->getCurrentState();
        }
    private:
        UserInterface* pInterface;
        ScoMachine* pMachine;
        Transaction* pTransaction;
        void resetAction();
        void scanAction();
        void paymentAction();
        void resultsAction();
};