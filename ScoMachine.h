#pragma once
#include "Transaction.h"


class ScoMachine
{
    public:
        ScoMachine ( Transaction *t );
        void transaction();
        void resetRepos();
        void display_day_results();
        bool get_new_day();
        std::vector <std::vector<std::string>> getScannedProducts();
        double getFinalTax();
        double getRunningBalance();
        double getFinalBill();
        int getChangeDollars();
        int getChangeQuarters();
        int getChangeDimes();
        int getChangeNickels();
        int getChangePennies();
        double getCashPayed();
        double getChangeOwed();
        double getTotalIncome();
        int getCreditApprovalCode();
        double getChangeRepoBalance();
        double getCashPurchaseRepoBalance();
        bool getMachineRunning();

    
    public:
        
        const static double change_refill_amount;
        const static double change_emptied_amount;
        

    private:
        Transaction *aTransaction;
        double total_income {0};
        double change_repo_balance {change_refill_amount};
        double cash_purchase_repo_balance {0};
        bool machineRunning {1};
        bool new_day {1};
        std::string new_day_answer;
};