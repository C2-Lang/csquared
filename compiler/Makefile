CC      := cc
CFLAGS  := -Wall -Wextra -std=c99 -Iinclude -MMD -MP
LDFLAGS :=

SRC_DIR   := src
BUILD_DIR := build
TARGET    := $(BUILD_DIR)/compiler

SRC := $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))
DEP := $(OBJ:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
	rm -rf compile_commands.json

run:
	$(TARGET)

.PHONY: all clean

-include $(DEP)


