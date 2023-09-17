#include "Reader.h"

 void Reader::readCSV(const std::string &fileName, std::vector<std::vector<std::string>> &container) {
    std::vector<std::string> row;
    std::string line, word;
    std::fstream file (fileName, std::ios::in);
    if (file.is_open()) {
        while(getline(file, line)) {
            row.clear();
            std::stringstream str(line);
            while(getline(str, word, ',')) {
                row.push_back(word);
            }
            container.push_back(row);
        }
    } else {
        std::cout << "Could not open the file" << std::endl;
    }
}