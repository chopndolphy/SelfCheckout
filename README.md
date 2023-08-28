# SelfCheckout
Version 1.8.27
## Changelog
### 1.8.27
- Project restructed according to Hiltmon C++ Project Structure guide.
- product_list.csv reformatted to remove space padding. Space padding is now dynamically added in UserInterface::displayScannedItems() and UserInterface::displayReciept()
- Memory for the Transaction object is now dynamically stored in the heap and is freed upon destruction of the MachineController obejct.
- makeProductMap() and makeLogoArt() renamed to loadProductMap() and loadProductArt(), respectively.
- Test file created to test loadProductMap()
- Makefile reworked for scalability, project restructure, and addition of new test files. 'make main' to create the self_checkout executable. 'make test "{test-file root}"' to create a test-file executable from any test-file.cpp.
## Bugs
- Money not displaying two decimal places when hundredth's place ends in a 0
- Adding to products vector wipes value data in productMap
- Invalid argument for stod when inputting a barcode
## To-Do
- Fix bugs
- Create tests as needed for class files and functions