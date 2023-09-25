#pragma once
#include "MachineState.h"
#include "MachineController.h"

class Reset : public MachineState {
    public:
        void enter(MachineController* controller);
        void toggle(MachineController* controller);
        void exit(MachineController* controller);
        static MachineState& getInstance();
    private:
        Reset() {}
        Reset(const Reset& other);
        Reset& operator=(const Reset& other);
};