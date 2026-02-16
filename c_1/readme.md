# задание 1

* Задача - вывод текста в консоль: "Hello world!"

создать:

    - main.c — файл с кодом;

    - Makefile — файл для сборки.

Запустить сборку:
    - команда в консоли make

Файл программы c_1.exe создатся в директории bin

Запустить программу:
./bin/c_1.exe

в консоли должна появиться строка - Hello world!

---

Пример организации файловой структуры программы:

с_1/
├── Makefile
├── main.c
└── bin/
    └── c_1.exe

---
Файл Makefile пример:

  CC = gcc
  CFLAGS = -Wall -Wextra

  TARGET = c_1

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
---
