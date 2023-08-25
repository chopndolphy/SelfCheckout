#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

#include "Product.h"

class Reader {
    public:
        Reader();
        static std::vector<std::vector<std::string>> readCSV(std::string fileName);
    private:

};