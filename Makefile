# Compiler and flags
CC = g++
CFLAGS = -Wall -std=c++11 -g
STRUCT = structures
SRCS = main.cpp $(STRUCT)/triey.cpp
OBJS = main.o triey.o
TARGET = main

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

triey.o: $(STRUCT)/triey.cpp
	$(CC) $(CFLAGS) -c $(STRUCT)/triey.cpp

clean:
	rm -f $(OBJS) $(TARGET)