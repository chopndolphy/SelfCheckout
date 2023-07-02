#include "Transaction.h"

const double Transaction::tax_rate {.05};
const std::vector <std::vector<std::string>> Transaction::product_list
{
    {"Meat01       ", "T-Bone Steak                       ", "7.99"},
    {"Meat02       ", "Tyson Fresh Chicken Wings          ", "10.00"},
    {"Icecream01   ", "Chocolate Ice Cream                ", "2.50"},
    {"Iceceam02    ", "Vanilla Ice Cream                  ", "2.50"},
    {"Corn01       ", "Fresh Sweet Corn                   ", "2.00"},
    {"Casewater01  ", "24 Bottles 16-Oz of Deer Park Water", "4.99"},
    {"Potatochips01", "Plain Potato Chips                 ", "2.00"},
    {"Potatochips02", "Green Onion Potato Chips           ", "2.00"},
    {"Donuts01     ", "Glazed Donuts One-Dozen            ", "4.99"},
    {"Saugage01    ", "8-Sausage Pack                     ", "4.99"},
    {"Eggs01       ", "Dozen Eggs                         ", "3.00"},
    {"Milk01       ", "Gallon Milk                        ", "4.00"}
};
void Transaction::welcome_message()
{
    system("clear");
    std::cout << "Welcome to Self-Checkout at Chris' Gross Grocery Grove!" << std::endl;
    std::cout << "\nEnter barcode number to begin scanning" << std::endl;
}
void Transaction::scan_item()
{
    std::cin >> current_barcode_string;
    if (current_barcode_string == "done")
    {
        still_scanning = 0;
        return;
    }
    current_barcode = stoi(current_barcode_string);
    scanned_products.push_back(product_list.at(current_barcode));
    system("clear");
    for (size_t i = 0; i < scanned_products.size(); i++)
    {
        std::cout << i+1 << " | " << scanned_products.at(i).at(0) << " | " << scanned_products.at(i).at(1) << " | $" << scanned_products.at(i).at(2) << std::endl;;
    }
    running_balance += stod(scanned_products.at(current_barcode).at(2));
    std::cout << "\n(Type 'done' to finish scanning.                 Balance: $" << running_balance << std::endl;
}
void Transaction::display_balances()
{
    final_tax = tax_rate * running_balance;
    final_bill = final_tax + running_balance;
    std::cout << "                                                     Tax: $" << final_tax << std::endl;
    std::cout << "\n                                              Final Bill: $" << final_bill << std::endl;

}
void Transaction::pay_final_bill()
{
    std::cout << "\nHow would you like to pay? (cash/card) ";
    std::cin >> cash_or_card_answer;
    if (cash_or_card_answer == "cash")
    {
        std::cout << "Please insert your payment: $";
        std::cin >> cash_payed;
        change_owed = cash_payed - final_bill;
        cents_remaining = change_owed * 100;
        change_dollars = cents_remaining / 100;
        cents_remaining %= 100;
        change_quarters = cents_remaining / 25;
        cents_remaining %= 25;
        change_dimes = cents_remaining / 10;
        cents_remaining %= 10;
        change_nickels = cents_remaining / 5;
        cents_remaining %= 5;
        change_pennies = cents_remaining;
        std::cout << "\nYou inserted: $" << cash_payed << std::endl;
        std::cout << "Your change: $" << change_owed << std::endl;
        std::cout << "Dollars: " << change_dollars << std::endl;
        std::cout << "Quarters: " << change_quarters << std::endl;
        std::cout << "Dimes: " << change_dimes << std::endl;
        std::cout << "Nickels: " << change_nickels << std::endl;
        std::cout << "Pennies: " << change_pennies << std::endl;
    }
    else
    {
        srand (time(NULL));
        credit_approval_code = rand() % 8999999 + 1000000;
        std::cout << "Your purchase was successful! (verification code: " << credit_approval_code << ")" << std::endl;
    }
}
void Transaction::print_reciept()
{
    std::cout << "\nWould you like a reciept? (yes/no) ";
    std::cin >> reciept_answer;
    system("clear");
    if (reciept_answer == "yes")
    {
        std::cout << "Chris' Gross Grocery Grove" << std::endl;
        std::cout << "\nItems purchased:" << std::endl;
        for (int i = scanned_products.size(); i-->0;)
        {
            std::cout << scanned_products.at(i).at(0) << "   $" << scanned_products.at(i).at(2) << std::endl;;
        }
        std::cout << "\nItem Balance:   $" << running_balance << std::endl;
        std::cout << "Tax Total:      $" << final_tax << std::endl;
        std::cout << "Final Bill:     $" << final_bill << std::endl;
        if (cash_or_card_answer == "card")
        {
            std::cout << "\nCard verification code: " << credit_approval_code << std::endl;
        }
        else
        {
            std::cout << "Cash inserted:  $" << cash_payed << std::endl;
            std::cout << "Change:         $" << change_owed << std::endl;
        }
    }
    std::cout << "\nThank you for shopping!" << std::endl;
    std::cout << "\nAre there more customers for today? (yes/no) " << std::endl;
    std::cin >> more_customers_answer;
    if (more_customers_answer == "yes")
    {
        more_customers = 1;
        still_scanning = 1;
    }
}
double Transaction::get_change_given_amount()
{
    return change_owed;
}
double Transaction::get_final_bill()
{
    return final_bill;
}
bool Transaction::get_still_scanning()
{
    return still_scanning;
}
bool Transaction::get_more_customers()
{
    return more_customers;
}
bool Transaction::cash_purchase()
{
    if (cash_or_card_answer == "cash")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}