#pragma once
#include <string>

class Product {
    public:
        Product(std::string id, std::string name, std::string price);
    
    private:
        std::string productID;
        std::string productName;
        std::string productPrice;
};