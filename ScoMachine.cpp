#include "ScoMachine.h"
#include "Transaction.h"


const double ScoMachine::change_refill_amount {200};
const double ScoMachine::change_emptied_amount {50};

void ScoMachine::day_reset()
{
    reset_repos();
        //sets cash purchase balance to 0 and change repo balance to change_refill_amount
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
            //calculates and displays item total, tax amount, and final balance
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
        //displays change repo balance, cash purchase balance, and total income
        //asks if new day
}
//define other functions