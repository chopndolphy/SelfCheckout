#pragma once
#include "ScoMachine.h"

class ScoMachine;
class MachineState {
    public:
        virtual void enter(ScoMachine* machine) = 0;
        virtual void toggle(ScoMachine* machine) = 0;
        virtual void exit(ScoMachine* machine) = 0;
        virtual ~MachineState() {}
};