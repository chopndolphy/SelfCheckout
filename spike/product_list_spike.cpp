#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class Product {
    private:
        std::string productID;
        std::string productName;
        double productPrice;
    public:
        Product(std::string id, std::string name, double price) {
            productID = id;
            productName = name;
            productPrice = price;
        }
        std::string getProductID() {
            return productID;
        }
        std::string getProductName() {
            return productName;
        }
        double getProductPrice() {
            return productPrice;
        }
};
class Reader {
    public:
        static std::vector<std::vector<std::string>> readCSV(std::string fileName) {
            std::vector<std::vector<std::string>> content;
            std::vector<std::string> row;
            std::string line, word;
            std::fstream file (fileName, std::ios::in);
            if (file.is_open()) {
                while (getline(file, line)) {
                    row.clear();
                    std::stringstream str(line);
                    while(getline(str, word, ',')) {
                        row.push_back(word);
                    }
                    content.push_back(row);
                }
            } else {
                std::cout << "Could not open the file" << std::endl;
            }
            return content;
        }
};
std::map<std::string, int> loadProductMap(std::string fileName, std::vector<Product>* products) {
    std::vector<std::vector<std::string>> productMapFile = Reader::readCSV(fileName);
    products->reserve(productMapFile.size());
    std::map<std::string, int> productMap;
    for (size_t i = 0; i < productMapFile.size(); i++) {
        products->emplace_back(productMapFile.at(i).at(0), productMapFile.at(i).at(1), stod(productMapFile.at(i).at(2)));
        productMap.emplace(products->at(i).getProductID(), i);
    }
    return productMap;
}
int main() {
    std::vector<Product> productList;
    std::map<std::string, int> productMap = loadProductMap("CSV_Files/product_list.csv", &productList);
    for (auto const& pair : productMap) {
        std::cout << productList.at(pair.second).getProductID() << " " << productList.at(pair.second).getProductName() << " " << productList.at(pair.second).getProductPrice() << std::endl;
    }
    return 0;
}