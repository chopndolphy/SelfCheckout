CC=g++
CFLAGS=-std=c++11 -pedantic -Wall -Wextra

BUILD=build

$(BUILD)/self_checkout:  $(BUILD)/self_checkout.o $(BUILD)/ScoMachine.o $(BUILD)/Transaction.o | $(BUILD)
	$(CC) $(CFLAGS) -o $@ $(BUILD)/self_checkout.o $(BUILD)/ScoMachine.o $(BUILD)/Transaction.o

$(BUILD)/self_checkout.o:  self_checkout.cpp ScoMachine.h | $(BUILD)
	$(CC) $(CFLAGS) -c self_checkout.cpp -o $(BUILD)/self_checkout.o

$(BUILD)/ScoMachine.o:  ScoMachine.cpp ScoMachine.h Transaction.h| $(BUILD)
	$(CC) $(CFLAGS) -c ScoMachine.cpp -o $(BUILD)/ScoMachine.o

$(BUILD)/Transaction.o:  Transaction.cpp Transaction.h| $(BUILD)
	$(CC) $(CFLAGS) -c Transaction.cpp -o $(BUILD)/Transaction.o	

$(BUILD):
	mkdir $(BUILD)

.phony: clean
clean:
	rm -rf $(BUILD)