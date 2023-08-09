#pragma once
#include <string>
#include <map>

#include "MachineState.h"
#include "Product.h"
#include "Reader.h"
class ScoMachine {
    public:
        ScoMachine ();
        
        void resetMachine();
        void advanceState();
        double getDayIncome();
        void updateMachine(double cashInserted, double changeGiven, double finalBill, bool moreCustomers);
        
        State getState() {
            return machineState;
        }
        double getTotalIncome() {
            return totalIncome;
        }
        double getChangeRepoBalance() {
            return changeRepoBalance;
        }
        double getCashPurchaseRepoBalance() {
            return cashPurchaseRepoBalance;
        }
        bool isAvailable() {
            return machineRunning;
        }
        double getDayIncome() {
            return dayIncome;
        }
    public:
        
        const static double changeRefillAmount;
        const static double changeEmptiedAmount;
    
    private:
        Reader* pReader;
        std::map<std::string, Product*> productList;
        std::string logoArt;
        double totalIncome {0};
        double changeRepoBalance {changeRefillAmount};
        double cashPurchaseRepoBalance {0};
        double dayIncome {0};
        State machineState;
};