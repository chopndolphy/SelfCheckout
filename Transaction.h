#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

class Transaction
{
    public:
        void welcome_message();
        void scan_item();
        void print_reciept();
        void pay_final_bill();
        void display_balances();
        double get_final_bill();
        double get_cash_purchase_amount();
        double get_change_given_amount();
        bool get_still_scanning();
        bool get_more_customers();
        bool cash_purchase();
        

    public:
        const static double tax_rate;
        const static std::vector <std::vector<std::string>> product_list;

    private:
        double running_balance {0};
        double cash_payed {0};
        int cents_remaining {0};
        double change_owed {0};
        double final_tax {0};
        double final_bill {0};
        int scanned_products_size {0};
        int change_total_cents {0};
        int change_dollars {0};
        int change_quarters {0};
        int change_dimes {0};
        int change_nickels {0};
        int change_pennies {0};
        int credit_approval_code {0};
        int current_barcode {0};
        std::vector <std::vector<std::string>> scanned_products;
        bool still_scanning {1};
        bool more_customers {0};
        std::string stilling_scanning_answer {""};
        std::string current_barcode_string {""};
        std::string cash_or_card_answer {""};
        std::string reciept_answer{""};
        std::string more_customers_answer {""};
};