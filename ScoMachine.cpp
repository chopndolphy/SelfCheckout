#include "ScoMachine.h"


const double ScoMachine::changeRefillAmount {200};
const double ScoMachine::changeEmptiedAmount {50};

ScoMachine::ScoMachine()
{
    machineRunning = 1;
}
void ScoMachine::resetMachine()
{
    cashPurchaseRepoBalance = 0;
    changeRepoBalance = changeRefillAmount;
    machineRunning = 1;
    dayIncome = 0;
}
double ScoMachine::getTotalIncome()
{
    return totalIncome;
}
double ScoMachine::getChangeRepoBalance()
{
    return changeRepoBalance;
}
double ScoMachine::getCashPurchaseRepoBalance()
{
    return cashPurchaseRepoBalance;
}
bool ScoMachine::getMachineRunning()
{
    return machineRunning;
}
void ScoMachine::updateMachine(double cashInserted, double changeGiven, double finalBill, bool moreCustomers)
{
    cashPurchaseRepoBalance += cashInserted;
    changeRepoBalance -= changeGiven;
    dayIncome += finalBill;
    totalIncome += finalBill;
    if (changeRepoBalance < changeEmptiedAmount || !moreCustomers)
    {
        machineRunning = 0;
    }
    else
    {
        machineRunning = 1;
    }
}
double ScoMachine::getDayIncome()
{
    return dayIncome;
}