#include "UserInterface.h"

UserInterface::UserInterface(ScoMachine *s, Transaction *t)
{
    aScoMachine = s;
    aTransaction = t;
}
void UserInterface::iBarcode()
{
    std::cin >> barcodeString;
}
void UserInterface::iPaymentType()
{
    std::cin >> cashOrCardAnswer;
}
void UserInterface::iReciept()
{
    std::cin >> recieptAnswer;
}
void UserInterface::iMoreCustomers()
{
    std::cin >> moreCustomersAnswer;
}
void UserInterface::iCashInserted()
{
    std::cin >> cashInserted;
}
void UserInterface::iNewDay()
{
    std::cin >> newDayAnswer;
}
void UserInterface::oWelcomeMessage()
{
    system("clear");
    std::cout << "Welcome to Self-Checkout at Chris' Gross Grocery Grove!" << std::endl;
    std::cout << R"(
          .
        ('
        '|
        |'
       [::]
       [::]   _......_
       [::].-'      _.-`.
       [:.'    .-. '-._.-`.
       [/ /\   |  \        `-..
       / / |   `-.'      .-.   `-.
      /  `-'            (   `.    `.
     |           /\      `-._/      \
     '    .'\   /  `.           _.-'|
    /    /  /   \_.-'        _.':;:/
  .'     \_/             _.-':;_.-'
 /   .-.             _.-' \;.-'
/   (   \       _..-'     |
\    `._/  _..-'    .--.  |
 `-.....-'/  _ _  .'    '.|
          | |_|_| |      | \  (o)
     (o)  | |_|_| |      | | (\'/)
    (\'/)/  ''''' |     o|  \;:;
     :;  |        |      |  |/)
      ;: `-.._    /__..--'\.' ;
    )" << std::endl;
    std::cout << "\nEnter barcode number to begin scanning" << std::endl;
}
void UserInterface::oScannedItems()
{
    system("clear");
    int i = 1;
    for (auto product : aScoMachine->getScannedProducts())
    {
        std::cout << i << " | ";
        for (auto info : product)
        {
            if (info != product.back())
            {
                std::cout << info << " | ";
            }
            else
            {
                std::cout << "$" << info << std::endl;
            }
            
        }
        ++i;
    }
    std::cout << "\n(Type 'done' to finish scanning.                 Balance: $" << aScoMachine->getRunningBalance() << std::endl;
}
void UserInterface::oBalances()
{
    std::cout << "                                                     Tax: $" << aScoMachine->getFinalTax() << std::endl;
    std::cout << "\n                                              Final Bill: $" << aScoMachine->getFinalBill() << std::endl;
}
void UserInterface::oPaymentTypePrompt()
{
    std::cout << "\nHow would you like to pay? (cash/card) ";
}
void UserInterface::oInsertCashPrompt()
{
    std::cout << "Please insert your payment: $";
}
void UserInterface::oChange()
{
    std::cout << "\nYou inserted: $" << aScoMachine->getCashPayed() << std::endl;
    std::cout << "Your change: $" << aScoMachine->getChangeOwed() << std::endl;
    std::cout << "Dollars: " << aScoMachine->getChangeDollars() << std::endl;
    std::cout << "Quarters: " << aScoMachine->getChangeQuarters() << std::endl;
    std::cout << "Dimes: " << aScoMachine->getChangeDimes() << std::endl;
    std::cout << "Nickels: " << aScoMachine->getChangeNickels() << std::endl;
    std::cout << "Pennies: " << aScoMachine->getChangePennies() << std::endl;
}
void UserInterface::oCreditApproval()
{
    std::cout << "Your purchase was successful! (verification code: " << aScoMachine->getCreditApprovalCode() << ")" << std::endl;
}
void UserInterface::oRecieptPrompt()
{
    std::cout << "\nWould you like a reciept? (yes/no) ";
}
void UserInterface::oReciept()
{
    system("clear");
    if (recieptAnswer == "yes")
    {
        std::cout << "Chris' Gross Grocery Grove" << std::endl;
        std::cout << "\nItems purchased:" << std::endl;
        for (auto product : aScoMachine->getScannedProducts())
        {
            std::cout << product.at(0) << "   $" << product.at(2) << std::endl;;
        }
        std::cout << "\nItem Balance:   $" << aScoMachine->getRunningBalance() << std::endl;
        std::cout << "Tax Total:      $" << aScoMachine->getFinalTax() << std::endl;
        std::cout << "Final Bill:     $" << aScoMachine->getFinalBill() << std::endl;
        if (cashOrCardAnswer == "card")
        {
            std::cout << "\nCard verification code: " << aScoMachine->getCreditApprovalCode() << std::endl;
        }
        else
        {
            std::cout << "Cash inserted:  $" << aScoMachine->getCashPayed() << std::endl;
            std::cout << "Change:         $" << aScoMachine->getChangeOwed() << std::endl;
        }
    }
    std::cout << "\nThank you for shopping!" << std::endl;
}
void UserInterface::oMoreCustomersPrompt()
{
    std::cout << "\nAre there more customers for today? (yes/no) " << std::endl;
}
void UserInterface::oDayResults()
{
    system("clear");
    std::cout << "End of day results:" << std::endl;
    std::cout << "\nChange Repository Balance:        $" << aScoMachine->getChangeRepoBalance() << std::endl;
    std::cout << "Cash Purchase Repository Balance: $" << aScoMachine->getCashPurchaseRepoBalance() << std::endl;
    std::cout << "Total Income For Today:           $" << aScoMachine->getTotalIncome() << std::endl;
    std::cout << "\nBegin next day? (yes/no) ";
}
void UserInterface::dayReset()
{
    aScoMachine->resetRepos();
    while (aScoMachine->getMachineRunning())
    {
        while(aTransaction->getStillScanning())
        {
            aTransaction->scanItem();
        }
        oBalances();
        oPaymentTypePrompt();
        iPaymentType();
        transaction.pay_final_bill();
        if (transaction.cash_purchase())
        {
            change_repo_balance -= transaction.get_change_given_amount();
            cash_purchase_repo_balance += transaction.get_final_bill();
        }
        total_income += transaction.get_final_bill();
        transaction.print_reciept();
        if (change_repo_balance < change_emptied_amount || !transaction.get_more_customers())
        {
            machine_running = 0;
        }
    }
    display_day_results();
}