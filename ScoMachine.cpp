#include "ScoMachine.h"
#include "Transaction.h"


const double ScoMachine::change_refill_amount {200};
const double ScoMachine::change_emptied_amount {50};

void ScoMachine::day_reset()
{
    reset_repos();
    while (machine_running)
    {
        //transaction_counter++;
            //how to loop creating new iterations of class with incrementing name?
        Transaction transaction;
        transaction.welcome_message();
        while(transaction.get_still_scanning())
        {
            transaction.scan_item();
                //takes barcode input and displays corresponding info with incrementing item counter
                //updates and displays running total
                //option to stop scanning
        }
        transaction.display_balances();
            //calculates and displays tax amount, and final balance
        transaction.pay_final_balance();
            //choose a payment type, displays verification code if card, calculates and displays correct change if cash
        change_repo_balance -= transaction.get_change_given_amount();
        cash_purchase_repo_balance += transaction.get_cash_purchase_amount();
        total_income += transaction.calculate_final_balance();
        transaction.print_reciept();
            //displays all item ids and prices, item total, tax amount, final balance
            //displays card verification code if card or displays cash recieved and change given if cash
        if (change_repo_balance < change_emptied_amount || !transaction.get_more_customers())
        {
            machine_running = 0;
        }
    }
    display_day_results();
}
void ScoMachine::reset_repos()
{
    cash_purchase_repo_balance = 0;
    change_repo_balance = change_refill_amount;
}
void ScoMachine::display_day_results()
{
    std::cout << "End of day results" << std::endl;
    std::cout << "Change Repository Balance: $" << change_repo_balance << std::endl;
    std::cout << "Cash Purchase Repository Balance: $" << cash_purchase_repo_balance << std::endl;
    std::cout << "Total Income For Today: $" << total_income << std::endl;
    std::cout << "\n Begin next day? (yes/no) ";
    std::cin >> new_day_answer;
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