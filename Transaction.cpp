#include "Transaction.h"

const double Transaction::tax_rate {.05};
const std::vector <std::vector<std::string>> Transaction::product_list
{
    {"00", "Meat01", "T-Bone Steak", "7.99"},
    {"01", "Meat02", "Tyson Fresh Chicken Wings", "10.00"},
    {"02", "Icecream01", "Chocolate Ice Cream", "2.50"},
    {"03", "Iceceam02", "Vanilla Ice Cream", "2.50"},
    {"04", "Corn01 Fresh", "Sweet Corn", "2.00"},
    {"05", "Casewater01", "24 Bottles 16-Oz of Deer Park Water", "4.99"},
    {"06", "Potatochips01", "Plain Potato Chips", "2.00"},
    {"07", "Potatochips02", "Green Onion Potato Chips", "2.00"},
    {"08", "Donuts01", "Glazed Donuts One-Dozen", "4.99"},
    {"09", "Saugage01", "8-Sausage Pack", "4.99"},
    {"10", "Eggs01", "Dozen Eggs", "3.00"},
    {"11", "Milk01", "Gallon Milk", "4.00"}
};
//define functions