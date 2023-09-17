#pragma once
#include <vector>
#include "Product.h"
class Transaction {
    public:
        Transaction();
        void addItem(const Product &product);
        void setScanning(const bool &scanValue) {
            scanning = scanValue;
        }
        void setFinalTax(const double &tax) {
            finalTax = tax;
        }
        void setFinalBill(const double &bill){
            finalBill = bill;
        }
        void setCashPayed(const double &cashInserted) {
            cashPayed = cashInserted;
        }
        void setChangeOwed(const double &change) {
            changeOwed = change;
        }
        void setChangeQuantities(const std::vector<int> &changeVec) {
            changeQuantities = changeVec;
        }
        void setCreditApprovalCode(const int &approvalCode) {
            creditApprovalCode = approvalCode;
        }
        const bool& isScanning() const {
            return scanning;
        }
        const double& getFinalTax() const {
            return finalTax;
        }
        const double& getFinalBill() const {
            return finalBill;
        }
        const double& getCashPayed() const {
            return cashPayed;
        }
        const double& getChangeOwed() const {
            return changeOwed;
        }
        const std::vector<int>& getChangeQuantities() const {
            return changeQuantities;
        }
        const int& getCreditApprovalCode() const {
            return creditApprovalCode;
        }
        const std::vector<Product>& getScannedProducts() const {
            return scannedProducts;
        }
        const double& getRunningBalance() const {
            return runningBalance;
        }
    private:
        std::vector<Product> scannedProducts;
        std::vector<int> changeQuantities;
        bool scanning {1};
        double runningBalance {0};
        double finalTax {0};
        double finalBill {0};
        double cashPayed {0};
        double changeOwed {0};
        int creditApprovalCode {0};
};