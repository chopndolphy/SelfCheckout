CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

BUILD=build

$(BUILD)/self_checkout:  $(BUILD)/self_checkout.o $(BUILD)/ScoMachine.o $(BUILD)/Transaction.o $(BUILD)/UserInterface.o $(BUILD)/MachineController.o $(BUILD)/Reader.o $(BUILD)/Product.o | $(BUILD)
	$(CC) $(CFLAGS) -o $@ $(BUILD)/self_checkout.o $(BUILD)/UserInterface.o $(BUILD)/ScoMachine.o $(BUILD)/Transaction.o $(BUILD)/MachineController.o $(BUILD)/Reader.o $(BUILD)/Product.o

$(BUILD)/self_checkout.o:  self_checkout.cpp MachineController.h | $(BUILD)
	$(CC) $(CFLAGS) -c self_checkout.cpp -o $(BUILD)/self_checkout.o

$(BUILD)/MachineController.o:  MachineController.cpp MachineController.h MachineState.h ScoMachine.h Transaction.h UserInterface.h | $(BUILD)
	$(CC) $(CFLAGS) -c MachineController.cpp -o $(BUILD)/MachineController.o

$(BUILD)/UserInterface.o:  UserInterface.cpp UserInterface.h Transaction.h Product.h | $(BUILD)
	$(CC) $(CFLAGS) -c UserInterface.cpp -o $(BUILD)/UserInterface.o

$(BUILD)/ScoMachine.o:  ScoMachine.cpp ScoMachine.h MachineState.h Product.h Reader.h | $(BUILD)
	$(CC) $(CFLAGS) -c ScoMachine.cpp -o $(BUILD)/ScoMachine.o

$(BUILD)/Transaction.o:  Transaction.cpp Transaction.h Product.h | $(BUILD)
	$(CC) $(CFLAGS) -c Transaction.cpp -o $(BUILD)/Transaction.o	

$(BUILD)/Product.o:  Product.cpp Product.h | $(BUILD)
	$(CC) $(CFLAGS) -c Product.cpp -o $(BUILD)/Product.o	

$(BUILD)/Reader.o:  Reader.cpp Reader.h Product.h| $(BUILD)
	$(CC) $(CFLAGS) -c Reader.cpp -o $(BUILD)/Reader.o	

$(BUILD):
	mkdir $(BUILD)

.phony: clean
clean:
	rm -rf $(BUILD)