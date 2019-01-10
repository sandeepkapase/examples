5CC=gcc
LDFLAGS = -lm
CFLAGS = -g -Wall -O3 -I../../../includes -I.

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
LIBSRC = .
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/lib_a.o $(OBJ_DIR)/lib_b.o

MAIN=$(BIN_DIR)/main
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/lib_a.o: $(LIBSRC)/lib_a.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/lib_b.o: $(LIBSRC)/lib_b.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/main.o: main.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

#$(info    myobj is is $(myobj))
#$(info    TARGET is is $(TARGET))
#-rm -rf $(BUILD_DIR)
.PHONY: clean
clean:
	$(info rm -rf $(BUILD_DIR))
	$(shell rm -rf $(BUILD_DIR))

.PHONY: run
run: $(MAIN)
	$(MAIN) < input.txt
