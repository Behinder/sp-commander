# Sciezka do kompilatora
CC ?= clang

CFLAGS= -Wall -Wextra

LIBS= -lncurses

TARGET=main

SRC = main.cpp

# Build directory
BUILD_DIR = build

#BUILD TARGET for final executable
$(BUILD_DIR)/$(TARGET): $(BUILD_DIR)/$(SRC:.cpp=.o)
	$(CC) $(CFLAGS) $(SRC) -o $^ $(LIBS)

# Rule to compile .cpp files into .o (object files)
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

#Clean target
.PHONY: clean 

clean:
	rm -f $(TARGET)

	
