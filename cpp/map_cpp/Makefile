CC=g++
CFLAGS = -g -Wall -O3 

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
OBJS = $(OBJ_DIR)/map.o

MAIN=$(BIN_DIR)/map
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@
	@echo "\nRun application:\n\t" $(@) \< input.txt

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/map.o: map.cpp
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(info rm -rf $(BUILD_DIR))
	$(shell rm -rf $(BUILD_DIR))
.PHONY: run
run: $(MAIN)
	$(MAIN)
