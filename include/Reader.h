#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class Reader {
    public:
        static std::vector<std::vector<std::string>> readCSV(std::string fileName);
};