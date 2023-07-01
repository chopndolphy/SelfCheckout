#pragma once
#include <string>

class ScoMachine
{
    public:
        
        void day_reset();
        void reset_repos();
        void display_day_results();
        bool get_new_day();
    
    public:
        
        const static double change_refill_amount;
        const static double change_emptied_amount;
        

    private:

        double total_income {0};
        double change_repo_balance {change_refill_amount};
        double cash_purchase_repo_balance {0};
        bool machine_running {1};
        int transaction_counter {0};
        bool new_day {1};
        std::string new_day_answer;
};