#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>

class Reader {
    public:
        static void readCSV(const std::string &fileName, std::vector<std::vector<std::string>> &container);
};