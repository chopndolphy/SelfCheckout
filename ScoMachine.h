#pragma once
class ScoMachine
{
    public:
        ScoMachine ();
        void resetMachine();
        double getTotalIncome();
        double getDayIncome();
        double getChangeRepoBalance();
        double getCashPurchaseRepoBalance();
        bool isAvailable();
        void updateMachine(double cashInserted, double changeGiven, double finalBill, bool moreCustomers);
    
    public:
        
        const static double changeRefillAmount;
        const static double changeEmptiedAmount;
        

    private:
        double totalIncome {0};
        double changeRepoBalance {changeRefillAmount};
        double cashPurchaseRepoBalance {0};
        bool machineRunning {1};
        double dayIncome {0};
};