#pragma once
#include <map>

enum class State {
    Reset = 1,
    Scan = 2,
    Payment = 3,
    Results = 4,
    Exit = 5
};