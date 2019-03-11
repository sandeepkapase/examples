CC=gcc
LDFLAGS = -lm
CFLAGS = -g -Wall -O3 -I../../../includes

BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objs
BIN_DIR = $(BUILD_DIR)/bin
LIBSRC = ../../../libsrc
OBJS = $(OBJ_DIR)/LL_one_gap_pair_swap.o $(OBJ_DIR)/ll_helper.o

MAIN=$(BIN_DIR)/LL_one_gap_pair_swap
$(MAIN): PREP $(OBJS)
	$(CC) $(OBJS) -o $@

.PHONY: PREP
PREP:
	$(info mkdir -p $(OBJ_DIR) $(BIN_DIR))
	$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

$(OBJ_DIR)/ll_helper.o: $(LIBSRC)/ll_helper/ll_helper.c
	$(CC) $(LDFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/LL_one_gap_pair_swap.o: LL_one_gap_pair_swap.c
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
