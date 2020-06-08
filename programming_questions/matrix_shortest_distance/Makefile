CC=g++
CFLAGS = -g -Wall -O3 -I../../../includes

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
LIBSRC = ../../../libsrc
OBJS = $(OBJ_DIR)/shortest_distance_between_two_element.o

MAIN=$(BIN_DIR)/shortest_distance
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@
	@echo "\nRun application:\n\t" $(@) \< input.txt

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/shortest_distance_between_two_element.o: shortest_distance_between_two_element.cpp
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(info rm -rf $(BUILD_DIR))
	$(shell rm -rf $(BUILD_DIR))

.PHONY: run
run: $(MAIN)
	$(MAIN) < input.txt
