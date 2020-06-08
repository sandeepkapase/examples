# Example for:
#            1) Duplicate symbol example
# We have passed macro parameter to avoid duplicate symbol error
# By default functions are global, hence external linkage used for
# referencing function from on compliation unit to another
# While liking object files, linker identifies duplicate symbol and
# gives error for linking operation.
# command to run example application
# make run "CFLAGS= -DRENAME_SUM"
CC = gcc
# append options to CFLAGS when passed from commandline
override CFLAGS += -g -Wall -O3 -I.
MAIN=main

MAIN=main
UNIT_ONE=unit_one
UNIT_TWO=unit_two

$(MAIN): $(UNIT_ONE) $(UNIT_TWO) $(MAIN).o
	$(CC) $(MAIN).o $(UNIT_ONE) $(UNIT_TWO) -o $(MAIN)

$(MAIN).o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(UNIT_ONE): unit_one.c
	$(CC) $(CFLAGS) -c $< -o $@

$(UNIT_TWO): unit_two.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
#	$(info rm -rf $(UNIT_ONE) $(UNIT_TWO) $(MAIN) $(MAIN).o)
	rm -rf $(UNIT_ONE) $(UNIT_TWO) $(MAIN) $(MAIN).o

.PHONY: run
run: clean $(MAIN)
	./$(MAIN)
