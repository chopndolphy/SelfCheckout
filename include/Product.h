#pragma once
#include <string>
class Product {
    public:
        Product(std::string id, std::string name, std::string price);
        std::string getProductID() {
            return productID;
        }
        std::string getProductName() {
            return productName;
        }
        std::string getProductPrice() {
            return productPrice;
        }
    private:
        std::string productID;
        std::string productName;
        std::string productPrice;
};