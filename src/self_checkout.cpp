#include "MachineController.h"
#include "ScoMachine.h"
#include "UserInterface.h"
#include "MachineState.h"

int main() {
    ScoMachine s;
    UserInterface i;
    MachineController controller(&i, &s);

    while (controller.getState() != State::Exit) {
        controller.executeAction();
    }
    controller.exitAction();
    return 0;
}