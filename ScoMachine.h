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
        std::map<std::string, Product*> makeProductMap(std::string fileName);
        std::string makeLogoArt(std::string fileName);

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
        double getDayIncome() {
            return dayIncome;
        }
        std::string getLogoArt() {
            return logoArt;
        }
        std::map<std::string, Product*> getProductMap() {
            return machineProductMap;
        }
    public:
        
        const static double changeRefillAmount;
        const static double changeEmptiedAmount;
    
    private:
        Reader* pReader;
        std::map<std::string, Product*> machineProductMap;
        std::string logoArt;
        double totalIncome {0};
        double changeRepoBalance {changeRefillAmount};
        double cashPurchaseRepoBalance {0};
        double dayIncome {0};
        State machineState;
};