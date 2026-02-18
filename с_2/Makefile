CC = gcc
CFLAGS = -Wall -Wextra

TARGET = c_2

BIN_DIR = bin

TARGET_PATH = $(BIN_DIR)/$(TARGET)

SRC_FILES = main_5.c

.PHONY: all clean

all: $(TARGET_PATH)
$(TARGET_PATH) : $(SRC_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -rf $(BIN_DIR)
