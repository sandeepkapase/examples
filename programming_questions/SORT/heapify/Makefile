CC=gcc
CFLAGS = -g -Wall -O3 -I../../../includes

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
LIBSRC = ../../../libsrc
OBJS = $(OBJ_DIR)/heapify.o $(OBJ_DIR)/mischelper.o

MAIN=$(BIN_DIR)/heapify
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/mischelper.o: $(LIBSRC)/mischelper/miscHelper.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/heapify.o: heapify.c
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
	$(MAIN)
#	$(MAIN) < input.txt
