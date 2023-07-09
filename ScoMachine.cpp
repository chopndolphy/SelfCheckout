#include "ScoMachine.h"


const double ScoMachine::change_refill_amount {200};
const double ScoMachine::change_emptied_amount {50};

ScoMachine::ScoMachine( Transaction *t)
{
    aTransaction = t;
    machineRunning = 0;
}

// void ScoMachine::day_reset()
// {
//     reset_repos();
//     while (machine_running)
//     {
//         while(aTransaction->getStillScanning())
//         {
//             aTransaction->scan_item();
//         }
//         transactiondisplay_balances();
//         transaction.pay_final_bill();
//         if (transaction.cash_purchase())
//         {
//             change_repo_balance -= transaction.get_change_given_amount();
//             cash_purchase_repo_balance += transaction.get_final_bill();
//         }
//         total_income += transaction.get_final_bill();
//         transaction.print_reciept();
//         if (change_repo_balance < change_emptied_amount || !transaction.get_more_customers())
//         {
//             machine_running = 0;
//         }
//     }
//     display_day_results();
// }
void ScoMachine::resetRepos()
{
    cash_purchase_repo_balance = 0;
    change_repo_balance = change_refill_amount;
}
void ScoMachine::display_day_results()
{
    if (new_day_answer != "yes") 
    {
        new_day = 0;
    }
}
bool ScoMachine::get_new_day()
{
    if (new_day)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
std::vector <std::vector<std::string>> ScoMachine::getScannedProducts()
{

}
double ScoMachine::getRunningBalance()
{

}
double ScoMachine::getFinalTax()
{
    
}
double ScoMachine::getFinalBill()
{
    
}
int ScoMachine::getChangeDollars()
{
    
}
int ScoMachine::getChangeQuarters()
{
    
}
int ScoMachine::getChangeDimes()
{
    
}
int ScoMachine::getChangeNickels()
{
    
}
int ScoMachine::getChangePennies()
{
    
}
double ScoMachine::getCashPayed()
{
    
}
double ScoMachine::getChangeOwed()
{
    
}
double ScoMachine::getTotalIncome()
{

}
int ScoMachine::getCreditApprovalCode()
{
    
}
double ScoMachine::getChangeRepoBalance()
{

}
double ScoMachine::getCashPurchaseRepoBalance()
{

}
bool ScoMachine::getMachineRunning()
{
    return machineRunning;
}