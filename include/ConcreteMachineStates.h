#pragma once
#include "MachineState.h"
#include "ScoMachine.h"

class Reset : public MachineState {
    public:
        void enter(ScoMachine* machine) {}
        void toggle(ScoMachine* machine);
        void exit(ScoMachine* machine) {}
        static MachineState& getInstance();
    private:
        Reset() {}
        Reset(const Reset& other);
        Reset& operator=(const Reset& other);
};
class Scan : public MachineState {
    public:
        void enter(ScoMachine* machine) {}
        void toggle(ScoMachine* machine);
        void exit(ScoMachine* machine) {}
        static MachineState& getInstance();
    private:
        Scan() {}
        Scan(const Scan& other);
        Scan& operator=(const Scan& other);
};
class Payment : public MachineState {
    public:
        void enter(ScoMachine* machine) {}
        void toggle(ScoMachine* machine);
        void exit(ScoMachine* machine) {}
        static MachineState& getInstance();
    private:
        Payment() {}
        Payment(const Payment& other);
        Payment& operator=(const Payment& other);
};
class Results : public MachineState {
    public:
        void enter(ScoMachine* machine) {}
        void toggle(ScoMachine* machine);
        void exit(ScoMachine* machine) {}
        static MachineState& getInstance();
    private:
        Results() {}
        Results(const Results& other);
        Results& operator=(const Results& other);
};
class Exit : public MachineState {
    public:
        void enter(ScoMachine* machine) {}
        void toggle(ScoMachine* machine);
        void exit(ScoMachine* machine) {}
        static MachineState& getInstance();
    private:
        Exit() {}
        Exit(const Exit& other);
        Exit& operator=(const Exit& other);
};