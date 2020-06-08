CC=g++
CFLAGS = -g -Wall -O3 

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
OBJS = $(OBJ_DIR)/dynamic_cast.o

MAIN=$(BIN_DIR)/dynamic_cast
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@
	@echo "\nRun application:\n\t" $(@) \< input.txt

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/dynamic_cast.o: dynamic_cast.cpp
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(info rm -rf $(BUILD_DIR))
	$(shell rm -rf $(BUILD_DIR))
.PHONY: run
run: $(MAIN)
	$(MAIN)
