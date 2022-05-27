NULL =
TAB  = $(NULL)    $(NULL)

# aliased options
all: b db
o: options
d: debug
db: debug_build
b: build
r: run
c: clean
cf: cleanf
t: test
tb: test_build

# options for make
options:
	$(info USAGE:)
	$(info $(TAB)make  o | options)
	$(info $(TAB)make  d | debug)
	$(info $(TAB)make db | debug_build)
	$(info $(TAB)make  b | build)
	$(info $(TAB)make  r | run arg="[argument]")
	$(info $(TAB)make  c | clean)
	$(info $(TAB)make cf | cleanf)
	$(info $(TAB)make  t | test)
	$(info $(TAB)make tb | test_build)
	@exit

# required stuff
CC        = gcc
DBG       = gdb -q
DBG_FLAGS = -Wall -D DEBUG="(1)" -g3 -ggdb
REL_FLAGS = -Wall -Ofast
TST_FLAGS = -Wall -D TEST="(1)" -g3 -ggdb

SRC_DIR   = ./src
BIN_DIR   = ./bin

LIB_PATH  = $(SRC_DIR)/lib/*.c
SRC_PATH  = $(LIB_PATH) $(SRC_DIR)/main.c
DBG_PATH  = $(BIN_DIR)/dbg-creeve
REL_PATH  = $(BIN_DIR)/creeve

GOTO_HELL = 2> /dev/null

# clear screen
clscr:
	clear

debug_build:
	@mkdir -p $(BIN_DIR)
	$(CC) $(DBG_FLAGS) $(SRC_PATH) -o $(DBG_PATH)

# creates debug build and launches in gdb
debug: clscr debug_build
	$(DBG) $(DBG_PATH)

# compile source to bin path
build:
	@mkdir -p $(BIN_DIR)
	$(CC) $(REL_FLAGS) $(SRC_PATH) -o $(REL_PATH)

argument_provided:
ifndef arg
	$(info run argument arg= not provided)
	$(error failed)
endif

# run source
run: argument_provided
	@$(REL_PATH) $(arg)

test_build:
	@mkdir -p $(SRC_DIR)/testing
	@$(CC) $(TST_FLAGS) $(LIB_PATH) $(SRC_DIR)/tests.c -o $(SRC_DIR)/test.elf

test: test_build
	@$(SRC_DIR)/test.elf
	@rm $(SRC_DIR)/test.elf
	@rm -rf $(SRC_DIR)/testing

# clear binaries
clean:
	@if [ "`git status --porcelain=v1 2> /dev/null | wc -l`" -gt 0 ]; then echo 'error: please commit changes before cleaning'; exit 1; fi
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(SRC_DIR)/testing
	@touch $(SRC_DIR)/test.elf
	rm -r $(BIN_DIR)
	rm -r $(SRC_DIR)/testing
	rm -r $(SRC_DIR)/test.elf

# force clear binaries
cleanf:
	@if [ "`git status --porcelain=v1 2> /dev/null | wc -l`" -gt 0 ]; then echo 'error: please commit changes before cleaning'; exit 1; fi
	rm -rf $(BIN_DIR)
	rm -rf $(SRC_DIR)/testing
	rm -f $(SRC_DIR)/test.elf
