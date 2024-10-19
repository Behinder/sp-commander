# compiler path
CC ?= clang++
CFLAGS= -Wall -Wextra -std=c++20
LIBS= -lncurses
TARGET=pscommander

SRC_DIR = src
BUILD_DIR = build


# cpp to obj
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)


# obj to executable
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC))

$(BUILD_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


# OUT DIR
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#Clean target
.PHONY: clean 

clean:
	rm -f $(BUILD_DIR)/*

	
