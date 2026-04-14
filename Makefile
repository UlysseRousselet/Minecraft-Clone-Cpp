CXX := g++
CC := gcc

TARGET := minecraft_clone
BUILD_DIR := build

SRC_CPP := $(wildcard src/*.cpp)
SRC_C := $(wildcard src/*.c)
OBJ_CPP := $(patsubst src/%.cpp,$(BUILD_DIR)/%.o,$(SRC_CPP))
OBJ_C := $(patsubst src/%.c,$(BUILD_DIR)/%.o,$(SRC_C))
OBJ := $(OBJ_CPP) $(OBJ_C)

CXXFLAGS := -std=c++17 -O2 -g -Wall -Wextra -Iinclude
CFLAGS := -O2 -g -Wall -Wextra -Iinclude
LDFLAGS :=
LDLIBS := -lglfw -lGL -ldl -lpthread -lm

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(LDFLAGS) $(LDLIBS)

$(BUILD_DIR)/%.o: src/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
