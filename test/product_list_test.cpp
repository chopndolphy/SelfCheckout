#include "MachineController.h"

int main() {
    ScoMachine s;
    std::map<std::string, Product*> productMap = s.getProductMap();
    std::map<std::string, Product*>::iterator it = productMap.begin();
    while (it != productMap.end()) {
        std::cout << it->second->getProductID() << " " << it->second->getProductName() << " " << it->second->getProductPrice() << std::endl;
        ++it;
    }
    return 0;
}