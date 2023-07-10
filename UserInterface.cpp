#include "UserInterface.h"

UserInterface::UserInterface(ScoMachine *s)
{
    aScoMachine = s;
}
void UserInterface::iBarcode()
{
    std::cin >> barcodeString;
}
void UserInterface::iPaymentType()
{
    std::cin >> paymentType;
}
void UserInterface::iReciept()
{
    std::cin >> recieptAnswer;
}
void UserInterface::iMoreCustomers()
{
    std::cin >> moreCustomersAnswer;
    if (moreCustomersAnswer == "yes")
    {
        moreCustomers = 1;
    }
    else
    {
        moreCustomers = 0;
    }
}
void UserInterface::iCashInserted()
{
    std::cin >> cashInserted;
}
void UserInterface::iNewDay()
{
    std::cin >> newDayAnswer;
    if (newDayAnswer == "no")
    {
        newDay = 0;
    }
    else
    {
        newDay = 1;
    }
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
    for (auto product : aTransaction->getScannedProducts())
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
    std::cout << "\n(Type 'done' to finish scanning.                 Balance: $" << aTransaction->getRunningBalance() << std::endl;
}
void UserInterface::oBalances()
{
    std::cout << "\n                                                     Tax: $" << aTransaction->getFinalTax() << std::endl;
    std::cout << "\n                                              Final Bill: $" << aTransaction->getFinalBill() << std::endl;
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
    std::cout << "\nYou inserted: $" << cashInserted << std::endl;
    std::cout << "Your change: $" << aTransaction->getChangeOwed() << std::endl;
    std::cout << "Dollars: " << aTransaction->getChangeDollars() << std::endl;
    std::cout << "Quarters: " << aTransaction->getChangeQuarters() << std::endl;
    std::cout << "Dimes: " << aTransaction->getChangeDimes() << std::endl;
    std::cout << "Nickels: " << aTransaction->getChangeNickels() << std::endl;
    std::cout << "Pennies: " << aTransaction->getChangePennies() << std::endl;
}
void UserInterface::oCreditApproval()
{
    std::cout << "Your purchase was successful! (verification code: " << aTransaction->getCreditApprovalCode() << ")" << std::endl;
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
        for (auto product : aTransaction->getScannedProducts())
        {
            std::cout << product.at(0) << "   $" << product.at(2) << std::endl;;
        }
        std::cout << "\nItem Balance:   $" << aTransaction->getRunningBalance() << std::endl;
        std::cout << "Tax Total:      $" << aTransaction->getFinalTax() << std::endl;
        std::cout << "Final Bill:     $" << aTransaction->getFinalBill() << std::endl;
        if (paymentType == "card")
        {
            std::cout << "\nCard verification code: " << aTransaction->getCreditApprovalCode() << std::endl;
        }
        else
        {
            std::cout << "Cash inserted:  $" << cashInserted << std::endl;
            std::cout << "Change:         $" << aTransaction->getChangeOwed() << std::endl;
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
    std::cout << "Today's Income:                   $" << aScoMachine->getDayIncome() << std::endl;
    std::cout << "Total Income:                     $" << aScoMachine->getTotalIncome() << std::endl;
    std::cout << "\nBegin next day? (yes/no) ";
}
void UserInterface::dayReset()
{
    aScoMachine->resetMachine();
    while (aScoMachine->getMachineRunning())
    {
        transaction();
    }
    oDayResults();
    iNewDay();
}
void UserInterface::transaction()
{
    Transaction t;
    aTransaction = &t;
    oWelcomeMessage();
    while(aTransaction->getStillScanning())
        {
            iBarcode();
            aTransaction->scanItem(barcodeString);
            oScannedItems();
        }
        aTransaction->calculateBalances();
        oBalances();
        oPaymentTypePrompt();
        iPaymentType();
        if (paymentType == "cash")
        {
            oInsertCashPrompt();
            iCashInserted();
            aTransaction->calculateChange(cashInserted);
            oChange();
        }
        else
        {
            aTransaction->approveCredit();
            oCreditApproval();
        }
        oRecieptPrompt();
        iReciept();
        if (recieptAnswer == "yes")
        {
            oReciept();
        }
        oMoreCustomersPrompt();
        iMoreCustomers();
        aScoMachine->updateMachine(cashInserted, aTransaction->getChangeOwed(), aTransaction->getFinalBill(), moreCustomers);
}
bool UserInterface::getNewDay()
{
    return newDay;
}
void UserInterface::oGoodbye()
{
    std::cout << "\nGoodbye!" << std::endl;
}