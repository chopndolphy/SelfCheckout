#pragma once
#include "MachineState.h"
#include "MachineController.h"

class Payment : public MachineState {
    public:
        void enter(MachineController* controller);
        void toggle(MachineController* controller);
        void exit(MachineController* controller);
        static MachineState& getInstance();
    private:
        Payment() {}
        Payment(const Payment& other);
        Payment& operator=(const Payment& other);
};