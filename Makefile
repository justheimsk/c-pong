CC = cc
LDFLAGS = -lSDL2 -lSDL2_ttf
CFLAGS = -O3 -Wall -Wextra -march=native -I./include
TARGET = main
BUILD_DIR = build
SRC = $(shell find src -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(BUILD_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BUILD_DIR)/$(TARGET) $(OBJ)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run:
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(OBJ)
