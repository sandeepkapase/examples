CC=g++
LDFLAGS = -lm
CFLAGS = -g -Wall -O3 -I../../../includes

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
LIBSRC = ../../../libsrc
OBJS = $(OBJ_DIR)/array_to_bst.o $(OBJ_DIR)/bstHelper.o $(OBJ_DIR)/libasciibst.o $(OBJ_DIR)/mischelper.o

MAIN=$(BIN_DIR)/array_to_bst
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/bstHelper.o: $(LIBSRC)/bsthelper/bstHelper.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/libasciibst.o:$(LIBSRC)/libasciibst/libasciibst.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/mischelper.o: $(LIBSRC)/mischelper/miscHelper.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/array_to_bst.o: array_to_bst.cpp
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
