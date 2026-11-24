# Compilacao: make        |   Executar: ./lista (Linux/macOS) ou lista.exe (Windows)
CC      ?= gcc
CFLAGS  = -Wall -Wextra -std=c99 -g
SRC     = $(wildcard src/*.c)
TARGET  = lista

all: $(TARGET)

$(TARGET): $(SRC) $(wildcard src/*.h)
	$(CC) $(CFLAGS) -o $@ $(SRC)

clean:
	$(RM) $(TARGET) $(TARGET).exe

.PHONY: all clean
