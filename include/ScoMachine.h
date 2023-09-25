#pragma once
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include "Product.h"
#include "Reader.h"
#include "Transaction.h"



class ScoMachine {
    public:
        ScoMachine ();
        void resetMachine();
        void updateMachine(const double &cashInserted, const double &changeGiven, const double &finalBill);
        void loadProductMap(const std::string &fileName, std::map<std::string, Product> &productMap);
        void loadLogoArt(const std::string &fileName, std::string &logoString);
        double calculateChangeOwed(const double &cashPayed, const double &finalBill);
        std::vector<int> calculateChange(const double &changeOwed);
        double calculateTax(const double &runningBalance);
        double calculateFinalBill(const double &runningBalance);
        int approveCredit();
        Transaction* createTransaction();
        void deleteTransaction();
        bool setCurrentBarcode(const std::string &barcode);
        Product getItem(const std::string &barcode);
        
        const double& getTotalIncome() const {
            return totalIncome;
        }
        const double& getChangeRepoBalance() const {
            return changeRepoBalance;
        }
        const double& getCashPurchaseRepoBalance() const {
            return cashPurchaseRepoBalance;
        }
        const double& getDayIncome() const {
            return dayIncome;
        }
        const std::string& getLogoArt() const {
            return logoArt;
        }
        const std::map<std::string, Product>& getProductMap() const {
            return machineProductMap;
        }
        const std::string& getCurrentBarcode() const {
            return currentBarcode;
        }
    public:
        const static double changeRefillAmount;
        const static double changeEmptiedAmount;
        const static double taxRate;
    private:
        Transaction* currentTransaction;
        double totalIncome {0};
        double changeRepoBalance {changeRefillAmount};
        double cashPurchaseRepoBalance {0};
        double dayIncome {0};
        std::string currentBarcode;
        std::string logoArt;
        std::map<std::string, Product> machineProductMap;
     
};