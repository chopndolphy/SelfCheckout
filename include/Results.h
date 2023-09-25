#pragma once
#include "MachineState.h"
#include "MachineController.h"

class Results : public MachineState {
    public:
        void enter(MachineController* controller);
        void toggle(MachineController* controller);
        void exit(MachineController* controller);
        static MachineState& getInstance();
    private:
        Results() {}
        Results(const Results& other);
        Results& operator=(const Results& other);
};