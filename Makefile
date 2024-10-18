# Sciezka do kompilatora
CC ?= clang

CFLAGS= -Wall -Wextra

LIBS= -lncurses

TARGET=main

SRC = main.cpp

#BUILD TARGET
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LIBS)

#Clean target
.PHONY: clean 

clean:
	rm -f $(TARGET)

	
