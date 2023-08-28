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
        void updateMachine(double cashInserted, double changeGiven, double finalBill);
        void advanceState();
        std::map<std::string, Product*> loadProductMap(std::string fileName);
        std::string loadLogoArt(std::string fileName);
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
        double totalIncome {0};
        double changeRepoBalance {changeRefillAmount};
        double cashPurchaseRepoBalance {0};
        double dayIncome {0};
        std::string logoArt;
        State machineState;
        std::map<std::string, Product*> machineProductMap;
        std::map<State, State> stateTransitions = {
        {State::Reset, State::Scan},
        {State::Scan, State::Payment},
        {State::Payment, State::Results},
        {State::Results, State::Exit}
        };
};