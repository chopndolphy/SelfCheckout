#pragma once
#include <string>
#include <vector>
#include <algorithm>
class Transaction
{
    public:
        Transaction();
        void scanItem();
        void resetTransaction();
        void calculateChange();
        void calculateBalances();
        double getFinalBill();
        bool getStillScanning();
        bool getMoreCustomers();
        bool cashPurchase();
        std::vector <std::vector<std::string>> getScannedProducts();
        double getRunningBalance();
        double getFinalTax();
        double getFinalBill();
        int getChangeDollars();
        int getChangeQuarters();
        int getChangeDimes();
        int getChangeNickels();
        int getChangePennies();
        double getCashPayed();
        double getChangeOwed();
        int getCreditApprovalCode();
        void approveCredit();
        // auto getOutput(std::string outputType);
        

    public:
        const static double taxRate;
        const static std::vector <std::vector<std::string>> productList;

    private:
        double runningBalance {0};
        double cashPayed {0};
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
        std::vector <std::vector<std::string>> scannedProducts;
        bool stillScanning {1};
        bool moreCustomers {0};
        std::string currentBarcodeString {""};
        std::string cashOrCardAnswer {""};
        std::string moreCustomersAnswer {""};
};