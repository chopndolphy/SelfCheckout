#include "Transaction.h"

Transaction::Transaction() {
    scanning = 1;
    runningBalance = 0.0;
}
void Transaction::addItem(const Product &product) {
    scannedProducts.push_back(product);
    runningBalance += scannedProducts.back().getProductPrice();
}