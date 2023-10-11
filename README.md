# SelfCheckout
Version 1.8.28
## Changelog
### 2.9.29
- SelfCheckout now supports multiple transactions per day and multiple days! Income and cash/change repositories will be tracked and updated.
### 1.9.17
- Refactored to optimize for encapsulation.
### 1.8.28
- Fixed issue of clearing the productMap, when constructing a new product, which also fixed the stod bug.
- Expanded Makefile for spike tests.
### 1.8.27
- Project restructed according to Hiltmon C++ Project Structure guide.
- product_list.csv reformatted to remove space padding. Space padding is now dynamically added in UserInterface::displayScannedItems() and UserInterface::displayReciept()
- Memory for the Transaction object is now dynamically stored in the heap and is freed upon destruction of the MachineController obejct.
- makeProductMap() and makeLogoArt() renamed to loadProductMap() and loadProductArt(), respectively.
- Test file created to test loadProductMap()
- Makefile reworked for scalability, project restructure, and addition of new test files. 'make main' to create the self_checkout executable. 'make test "{test-file root}"' to create a test-file executable from any test-file.cpp.
## Bugs
- Money not displaying two decimal places when hundredth's place ends in a 0
- Can enter in a cash amount that would require to put the change repository into the negative
## To-Do
- config.ini and ini reader function
- Fix bugs
- Create tests as needed for class files and functions
- Comment code throroughly
- GUI!!!
# Getting Started
SelfCheckout is a console application that emulates the functionality of a grocery store self-checkout machine. The project, as a whole, serves as a canvas for progressively and iteratively applying new software development concepts. Some examples of concepts applied to this project are:
- Version control with git
- Project structure
- Object oriented programming
- Naming conventions
- Makefiles
- Reading from a csv file
- README files!
There is no way to tell when the project will be retired as a learning tool, but it is likely to change dramatically while it still employed!
## Building and Running Your Executable
SelfCheckout is only available for UNIX console environments. When within the project directory and with gnu make install, enter to build the executable:
```
make main
```
Then to run the program:
```
/bin/./self_checkout
```
## Program Loop
SelfCheckout works by entering in available barcodes, one by one. As you scan your items, the ID, Name, and price are added to the display and the running total is updated. When you enter "done", the tax and final balance is calculated and displayed. 

You have the option to pay either with cash or card. If you pay with cash, you must enter the amount that you are inserting. The machine will then calculate and display the correct change in the minimum units of currency ($USD). If you choose to pay with card, you are given a randomized 7-digit credit authorization code.

You are then asked if you need a reciept. The reciept displays every product ID and product price, the calculate balance, tax, and final balance, and your inserted cash and recieved change (if cash is chosen) or your credit authorization code (if card is chosen). 

Afterwards, you will be asked if there are more customers for the day. This will create a new transaction and go back to the beginning. If there are no more customers for the day or there is not enough cash to continue the day, the machine will ask if you want to start a new day. The machine displays the cash deposited for the day, the change left for the day, the daily income, and the total income. If there is a new day, the repos will be reset (the total income tracker will remain) and a new transaction will begin.
## Available Products

| Product ID    | Product Name                        | Price  |
| ------------- | ----------------------------------- | ------ |
| Meat01        | T-Bone Steak                        |  $7.99 |
| Meat02        | Tyson Fresh Chicken Wings           | $10.00 |
| Icecream01    | Chocolate Ice Cream                 |  $2.50 |
| Iceceam02     | Vanilla Ice Cream                   |  $2.50 |
| Corn01        | Fresh Sweet Corn                    |  $2.00 |
| Casewater01   | 24 Bottles 16-Oz of Deer Park Water |  $4.99 |
| Potatochips01 | Plain Potato Chips                  |  $2.00 |
| Potatochips02 | Green Onion Potato Chips            |  $2.00 |
| Donuts01      | Glazed Donuts One-Doze              |  $4.99 |
| Saugage01     | 8-Sausage Pack                      |  $4.99 |
| Eggs01        | Dozen Eggs                          |  $3.00 |
| Milk01        | Gallon Milk                         |  $4.00 |

### Thank You!