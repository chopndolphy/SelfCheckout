#pragma once
#include <string>
#include <vector>

class Transaction
{
    public:
        void welcome_message();
        void scan_item();
        void print_reciept();
        void pay_final_balance();
        void display_balances();
        double calculate_running_total();
        double calculate_tax();
        double calculate_final_balance();
        double get_cash_purchase_amount();
        double get_change_given_amount();
        bool get_still_scanning();
        bool get_more_customers();
        

    public:
        const static double tax_rate;
        const static std::vector <std::vector<std::string>> product_list;

    private:
        double running_balance {0};
        double tax_amount {0};
        double final_bill {0};
        double cash_payed {0};
        double change_owed {0};
        int change_total_cents {0};
        int change_dollars {0};
        int change_quarters {0};
        int change_dimes {0};
        int change_nickels {0};
        int change_pennies {0};
        int credit_approval_code {0};
        std::vector <std::vector<std::string>> scanned_products;
        bool still_scanning {1};
};