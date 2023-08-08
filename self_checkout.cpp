#include "UserInterface.h"

int main()
{
    ScoMachine s;
    UserInterface anInterface(&s);

    while (anInterface.isRunning())
    {
        anInterface.dayReset();
        anInterface.runTransactions();
        anInterface.displayDayResults();
        anInterface.askIfNewDay();
    }
    anInterface.displayGoodbye();
    return 0;
}