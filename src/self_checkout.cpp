#include "MachineController.h"
#include "ScoMachine.h"
#include "UserInterface.h"
#include "MachineState.h"

int main() {
    ScoMachine s;
    UserInterface i;
    MachineController controller(&i, &s);

    controller.executeAction();
    controller.exitAction();
    return 0;
}