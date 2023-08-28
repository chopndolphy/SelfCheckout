#pragma once
#include <string>
class Product {
    public:
        Product(std::string id, std::string name, double price);
        std::string getProductID() {
            return productID;
        }
        std::string getProductName() {
            return productName;
        }
        double getProductPrice() {
            return productPrice;
        }
    private:
        std::string productID;
        std::string productName;
        double productPrice;
};