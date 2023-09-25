#pragma once
#include "MachineState.h"
#include "MachineController.h"

class Exit : public MachineState {
    public:
        void enter(MachineController* controller);
        void toggle(MachineController* controller);
        void exit(MachineController* controller);
        static MachineState& getInstance();
    private:
        Exit() {}
        Exit(const Exit& other);
        Exit& operator=(const Exit& other);
};