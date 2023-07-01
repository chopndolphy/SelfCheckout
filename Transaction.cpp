#include "Transaction.h"

const double Transaction::tax_rate {.05};
const std::vector <std::vector<std::string>> Transaction::product_list
{
    {"Meat01       ", "T-Bone Steak                       ", "7.99"},
    {"Meat02       ", "Tyson Fresh Chicken Wings          ", "10.00"},
    {"Icecream01   ", "Chocolate Ice Cream                ", "2.50"},
    {"Iceceam02    ", "Vanilla Ice Cream                  ", "2.50"},
    {"Corn01 Fresh ", "Sweet Corn                         ", "2.00"},
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
    std::cout << "Welcome to Self-Checkout at Chris' Gross Grocery Grove!" << std::endl;
    std::cout << "Enter barcode number to begin scanning" << std::endl;
}
void Transaction::scan_item()
{
    std::cin >> current_barcode;
    scanned_products.push_back(product_list[current_barcode]);
    system("clear");
    for (int i = scanned_products.size(); i-->0;)
    {
        std::cout << i+1 << " | " << scanned_products[i][0] << " | " << scanned_products[i][1] << " | $" << scanned_products[i][2] << std::endl;;
    }
    running_balance += stod(scanned_products[current_barcode][2]);
    std::cout << "\nBalance: $" << running_balance << std::endl;
    std::cout << "\nFinished scanning? (yes/no) ";
    std::cin >> stilling_scanning_answer;
    if (stilling_scanning_answer != "yes")
    {
        still_scanning = 0;
    }
}