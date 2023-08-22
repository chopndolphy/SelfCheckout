#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include "Product.h"
class Transaction {
    public:
        Transaction(std::map<std::string, Product*> productList);
        void scanItem(std::string barcode);
        void calculateChange(double cashPayed);
        void calculateBalances();
        void approveCredit();
        
        double Transaction::getFinalBill(){
            return finalBill;
        }
        bool Transaction::isScanning() {
            return scanning;
        }
        std::vector<Product*> Transaction::getScannedProducts() {
            return scannedProducts;
        }
        double Transaction::getRunningBalance() {
            return runningBalance;
        }
        double Transaction::getFinalTax() {
            return finalTax;
        }
        int Transaction::getChangeDollars() {
            return changeDollars;
        }
        int Transaction::getChangeQuarters() {
            return changeQuarters;
        }
        int Transaction::getChangeDimes() {
            return changeDimes;
        }
        int Transaction::getChangeNickels() {
            return changeNickels;
        }
        int Transaction::getChangePennies() {
            return changePennies;
        }
        double Transaction::getChangeOwed() {
            return changeOwed;
        }
        int Transaction::getCreditApprovalCode() {
            return creditApprovalCode;
        }
        

    public:
        const static double taxRate;
        // const static std::vector <std::vector<std::string>> productList;

    private:
        double runningBalance {0};
        int centsRemaining {0};
        double changeOwed {0};
        double finalTax {0};
        double finalBill {0};
        int runningBalancePennies {0};
        int finalTaxPennies {0};
        int changeTotalCents {0};
        int changeDollars {0};
        int changeQuarters {0};
        int changeDimes {0};
        int changeNickels {0};
        int changePennies {0};
        int creditApprovalCode {0};
        int currentBarcode {0};
        std::vector<Product*> scannedProducts;
        bool scanning {1};
        std::string cashOrCardAnswer {""};
        std::string moreCustomersAnswer {""};
        std::map<std::string, Product*> transactionProductMap;
};