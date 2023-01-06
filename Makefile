SRC_DIR = ./src
SRCS := $(shell find . -type f -name "*.cpp")

BUILD_DIR := ./build
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

CC := /usr/bin/g++
LIBS := glfw3 glew
CFLAGS := -O2 -Wall -Wextra -Wno-unused -Wno-unused-result -std=c++17 -pedantic -ggdb `pkg-config --cflags $(LIBS)`
LDFLAGS := `pkg-config --libs --static $(LIBS)`

ELF := main

all: $(ELF)
	./$<

$(ELF): $(OBJS)
	$(CC) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)/* $(ELF)

.PHONY: all clean