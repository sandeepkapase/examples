5CC=gcc
LDFLAGS = -lm
CFLAGS = -g -Wall -O3 -I../../../includes -I.

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
LIBSRC = .
OBJS = $(OBJ_DIR)/fun_ptr_example_1.o $(OBJ_DIR)/lib_a.o

MAIN=$(BIN_DIR)/fun_ptr_example_1
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/lib_a.o: $(LIBSRC)/lib_a.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/fun_ptr_example_1.o: fun_ptr_example_1.c
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
