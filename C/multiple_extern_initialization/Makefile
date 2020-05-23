# Example for: C programming translation unit
# We have created object file for two compilation/translation unit
# and then done linking to create main binary.
CC = gcc
# append options to CFLAGS when passed from commandline
override CFLAGS += -g -Wall -O3 -I.
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
	rm -rf $(UNIT_ONE) $(UNIT_TWO) $(MAIN) $(MAIN).o

.PHONY: run
run: clean $(MAIN)
	./$(MAIN)
