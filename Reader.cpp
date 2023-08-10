#include "Reader.h"

Reader::Reader() {

}
std::vector<std::vector<std::string>> Reader::readCSV(std::string fileName) {
    std::vector<std::vector<std::string>> content;
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
            content.push_back(row);
        }
    }
    else {
        std::cout << "Could not open the file" << std::endl;
    }
    return content;
}