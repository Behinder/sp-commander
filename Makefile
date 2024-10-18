# compiler path
CC ?= clang
CFLAGS= -Wall -Wextra
LIBS= -lncurses
TARGET=pscommander

SRC = $(wildcard *.cpp)

BUILD_DIR = build

# OBJECT FILES
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS)  $< -o $@  $(LIBS)
	
# OUTPUT EXECUTABLE
OBJ = $(patsubst %.cpp, $(BUILD_DIR)/%.o, $(SRC))
$(BUILD_DIR)/$(TARGET): $(OBJ)
	$(CC) $(CFLAGS)  -o $(BUILD_DIR)/$(TARGET) $(SRC) $(LIBS)

# OUT DIR
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#Clean target
.PHONY: clean 

clean:
	rm -f $(BUILD_DIR)/*

	
