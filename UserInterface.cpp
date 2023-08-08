#include "UserInterface.h"

UserInterface::UserInterface(ScoMachine *s)
{
    aScoMachine = s;
    for (size_t i = 0; i < Transaction::productList.size(); i++)
    {
        availableBarcodes.push_back(std::to_string(i));
    }
    availableBarcodes.push_back("done");
}
void UserInterface::readBarcode()
{
    std::cin >> barcodeString;
    if (std::find(std::begin(availableBarcodes), std::end(availableBarcodes), barcodeString) != std::end(availableBarcodes))
    {
        success = 1;
    }
    else
    {
        std::cout << "Invalid input. Try again." << std::endl;
    }
}
void UserInterface::specifyPaymentType()
{
    std::cin >> paymentType;
    if (paymentType == "cash" || "card")
    {
        success = 1;
    }
    else
    {
        std::cout << "Invalide input. Try again." << std::endl;
    }
}
void UserInterface::askIfRecieptNeeded()
{
    std::cin >> recieptAnswer;
    if (recieptAnswer == "yes" || "no")
    {
        success = 1;
    }
    else
    {
        std::cout << "Invalid input. Try again." << std::endl;
    }
}
void UserInterface::askIfMoreCustomers()
{
    std::cin >> moreCustomersAnswer;
    if (moreCustomersAnswer == "yes")
    {
        moreCustomers = 1;
        success = 1;
    }
    else if (moreCustomersAnswer == "no")
    {
        moreCustomers = 0;
        success = 1;
    }
    else
    {
        std::cout << "Invalid input. Try again." << std::endl;
    }
}
void UserInterface::insertCash()
{
    if (std::cin >> cashInserted)
    {
        success = 1;
    }
    else
    {
        std::cout << "Invalid input. Try again." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
void UserInterface::askIfNewDay()
{
    std::cin >> newDayAnswer;
    if (newDayAnswer == "no")
    {
        running = 0;
        success = 1;
    }
    else if (newDayAnswer == "yes")
    {
        running = 1;
        success = 1;
    }
    else
    {
        std::cout << "Invalid input. Try again." << std::endl;
    }
}
void UserInterface::displayWelcomeMessage()
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
void UserInterface::displayScannedItems()
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
void UserInterface::displayBalances()
{
    std::cout << "\n                                                     Tax: $" << aTransaction->getFinalTax() << std::endl;
    std::cout << "\n                                              Final Bill: $" << aTransaction->getFinalBill() << std::endl;
}
void UserInterface::displayPaymentTypePrompt()
{
    std::cout << "\nHow would you like to pay? (cash/card) ";
}
void UserInterface::displayInsertCashPrompt()
{
    std::cout << "Please insert your payment: $";
}
void UserInterface::displayChange()
{
    std::cout << "\nYou inserted: $" << cashInserted << std::endl;
    std::cout << "Your change: $" << aTransaction->getChangeOwed() << std::endl;
    std::cout << "Dollars: " << aTransaction->getChangeDollars() << std::endl;
    std::cout << "Quarters: " << aTransaction->getChangeQuarters() << std::endl;
    std::cout << "Dimes: " << aTransaction->getChangeDimes() << std::endl;
    std::cout << "Nickels: " << aTransaction->getChangeNickels() << std::endl;
    std::cout << "Pennies: " << aTransaction->getChangePennies() << std::endl;
}
void UserInterface::displayCreditApproval()
{
    std::cout << "Your purchase was successful! (verification code: " << aTransaction->getCreditApprovalCode() << ")" << std::endl;
}
void UserInterface::displayRecieptPrompt()
{
    std::cout << "\nWould you like a reciept? (yes/no) ";
}
void UserInterface::displayReciept()
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
void UserInterface::displayMoreCustomersPrompt()
{
    std::cout << "\nAre there more customers for today? (yes/no) " << std::endl;
}
void UserInterface::displayDayResults()
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
}
void UserInterface::runTransactions()
{
    while (aScoMachine->isAvailable())
    {
        Transaction t;
        aTransaction = &t;
        displayWelcomeMessage();
        while(aTransaction->isScanning())
            {
                success = 0;
                while (!success)
                {
                    readBarcode();
                }
                aTransaction->scanItem(barcodeString);
                displayScannedItems();
            }
        aTransaction->calculateBalances();
        displayBalances();
        displayPaymentTypePrompt();
        success = 0;
        while (!success)
        {
            specifyPaymentType();
        }
        if (paymentType == "cash")
        {
            displayInsertCashPrompt();
            success = 0;
            while (!success)
            {
                insertCash();
            }
            aTransaction->calculateChange(cashInserted);
            displayChange();
        }
        else
        {
            aTransaction->approveCredit();
            displayCreditApproval();
        }
        displayRecieptPrompt();
        success = 0;
        while (!success)
        {
            askIfRecieptNeeded();
        }
        if (recieptAnswer == "yes")
        {
            displayReciept();
        }
        displayMoreCustomersPrompt();
        success = 0;
        while (!success)
        {
            askIfMoreCustomers();
        }
        aScoMachine->updateMachine(cashInserted, aTransaction->getChangeOwed(), aTransaction->getFinalBill(), moreCustomers);
    }
}
bool UserInterface::isRunning()
{
    return running;
}
void UserInterface::displayGoodbye()
{
    std::cout << "\nGoodbye!" << std::endl;
}