CC = g++-4.7
CFLAGS = -std=c++11 -Wall -Wextra -Wunused -c 
LDFLAGS = 

BUILD = build/

main.bin: main.o onewire.o
	$(CC) $(LDFLAGS) $(BUILD)main.o $(BUILD)onewire.o \
	    -o $(BUILD)main.bin

onewire.o: onewire.cpp onewire.h
	$(CC) $(CFLAGS) onewire.cpp -o $(BUILD)onewire.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(BUILD)main.o

dirs:
	mkdir -p $(BUILD)
