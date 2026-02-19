CC = gcc
CFLAGS = -std=c23 -pedantic -Wall -Wextra -Werror

TARGET = c_3

BIN_DIR = bin

TARGET_PATH = $(BIN_DIR)/$(TARGET)

SRC_FILES = main.c

.PHONY: all clean

all: $(TARGET_PATH)
$(TARGET_PATH) : $(SRC_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(BIN_DIR)
