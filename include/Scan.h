#pragma once
#include "MachineState.h"
#include "MachineController.h"

class Scan : public MachineState {
    public:
        void enter(MachineController* controller);
        void toggle(MachineController* controller);
        void exit(MachineController* controller);
        static MachineState& getInstance();
    private:
        Scan() {}
        Scan(const Scan& other);
        Scan& operator=(const Scan& other);
};