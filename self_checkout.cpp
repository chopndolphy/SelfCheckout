#include "ScoMachine.h"

int main()
{
    ScoMachine scomachine;
    while(scomachine.get_new_day())
    {
        scomachine.day_reset();
    }
    return 0;
}

/*
vector of item vectors of details
vector of bill list
adds vector of item details




product id
description
unit price

item count

running total
total price 
sales tax percent 5%
sales tax total 
final bill

pay function
print reciept

cash
    amount given
    amount owed
    calculate correct change
    
    change repository
        beginning of the day, refilled $200
        if falls below $50, done for the day (send message to control center)

    cash repository
        emptied once per day 
        out of service when being emptied
            start empty 
            end empty

credit/debit 
    verify payment
    return numeric approval code
        displayed on screen and reciept

Meat01 T-Bone Steak 7.99
Meat02 Tyson Fresh Chicken Wings 10.00
Icecream01 Chocolate Ice Cream 2.50
Iceceam02 Vanilla Ice Cream 2.50
Corn01 Fresh Sweet Corn 2.00
Casewater01 24 Bottles 16-Oz of Deer Park Water 4.99
Potatochips01 Plain Potato Chips 2.00
Potatochips02 Green Onion Potato Chips 2.00
Donuts01 Glazed Donuts One-Dozen 4.99
Saugage01 8-Sausage Pack 4.99
Eggs01 Dozen Eggs 3.00
Milk01 Gallon Milk 4.00
*/
   