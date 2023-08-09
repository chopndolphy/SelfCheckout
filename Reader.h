#pragma once
#include <map>
#include <string>

#include "Product.h"

class Reader {
    public:
        Reader();
        std::map<std::string, Product*> readProductList();
        std::string readLogoArt();
    private:

};