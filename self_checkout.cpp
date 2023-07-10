#include "UserInterface.h"

int main()
{
    ScoMachine s;
    UserInterface anInterface(&s);

    while (anInterface.getNewDay())
    {
        anInterface.dayReset();
    }
    anInterface.oGoodbye();
    return 0;
}