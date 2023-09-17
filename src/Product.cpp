#include "Product.h"

Product::Product(const std::string &id, const std::string &name, const double &price) {
    productID = id;
    productName = name;
    productPrice = price;
}