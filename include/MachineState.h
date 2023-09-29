#pragma once

class MachineController;
class MachineState {
    public:
        virtual void enter(MachineController* controller) = 0;
        virtual void toggle(MachineController* controller) = 0;
        virtual void exit(MachineController* controller) = 0;
        virtual ~MachineState() {}
};