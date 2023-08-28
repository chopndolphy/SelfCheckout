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
        std::map<std::string, int> loadProductMap(std::string fileName, std::vector<Product>* products);
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
        std::map<std::string, int>* getProductMap() {
            return &machineProductMap;
        }
        std::vector<Product>* getProductsVec() {
            return &productsVec;
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
        std::map<std::string, int> machineProductMap;
        std::vector<Product> productsVec;
        std::map<State, State> stateTransitions = {
        {State::Reset, State::Scan},
        {State::Scan, State::Payment},
        {State::Payment, State::Results},
        {State::Results, State::Exit}
        };
};