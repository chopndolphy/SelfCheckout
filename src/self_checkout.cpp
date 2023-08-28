#include "MachineController.h"

int main() {
    ScoMachine s;
    UserInterface i(s.getProductMap());
    MachineController controller(&i, &s);

    while (controller.getState() != State::Exit) {
        controller.executeAction();
    }
    controller.exitAction();
    return 0;
}