#include "ScoMachine.h"

int main()
{
    ScoMachine scomachine;
    while(scomachine.get_new_day())
    {
        scomachine.day_reset();
    }
    return 0;
}