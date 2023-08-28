#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include "Product.h"
class Transaction {
    public:
        Transaction(std::map<std::string, int>* productMap, std::vector<Product>* productList);
        void scanItem(std::string barcode);
        void calculateChange(double cashPayed);
        void calculateBalances();
        void approveCredit();
        
        double getFinalBill(){
            return finalBill;
        }
        bool isScanning() {
            return scanning;
        }
        std::vector<Product*> getScannedProducts() {
            return scannedProducts;
        }
        double getRunningBalance() {
            return runningBalance;
        }
        double getFinalTax() {
            return finalTax;
        }
        double getTransactionCashPayed() {
            return transactionCashPayed;
        }
        double getChangeOwed() {
            return changeOwed;
        }
        int getCreditApprovalCode() {
            return creditApprovalCode;
        }
        std::vector<int> getTransactionChangeQuantities() {
            return transactionChangeQuantities;
        }

    public:
        const static double taxRate;

    private:
        double runningBalance {0};
        int centsRemaining {0};
        double transactionCashPayed {0};
        double changeOwed {0};
        double finalTax {0};
        double finalBill {0};
        int runningBalancePennies {0};
        int finalTaxPennies {0};
        std::vector<int> transactionChangeQuantities;
        int creditApprovalCode {0};
        std::vector<Product*> scannedProducts;
        bool scanning {1};
        std::map<std::string, int>* transactionProductMap;
        std::vector<Product>* transactionProductList;
};