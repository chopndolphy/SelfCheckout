#pragma once
#include <string>
class Product {
    public:
        Product(const std::string &id, const std::string &name, const double &price);
        const std::string& getProductID() const {
            return productID;
        }
        const std::string& getProductName() const {
            return productName;
        }
        const double& getProductPrice() const {
            return productPrice;
        }
    private:
        std::string productID;
        std::string productName;
        double productPrice;
};