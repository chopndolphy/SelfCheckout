#pragma once
#include <map>

enum class State {
    Reset = 1,
    Scan = 2,
    Payment = 3,
    Results = 4,
    Exit = 5
};

std::map<State, State> stateTransitions = {
    {State::Reset, State::Scan},
    {State::Scan, State::Payment},
    {State::Payment, State::Results},
    {State::Results, State::Exit}
};