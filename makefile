CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Wunused -c  -fPIC -c
LDFLAGS = 

BUILD = build/

install: libonewire.so
	$(shell ./install.sh)

libonewire.so: onewire.o
	$(CC) $(LDFLAGS) -shared -Wl,-soname,onewirelib.so \
	    $(BUILD)onewire.o \
	    -o $(BUILD)libonewire.so

onewire.o: onewire.cpp onewire.h
	$(CC) $(CFLAGS) onewire.cpp -o $(BUILD)onewire.o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -o $(BUILD)main.o

dirs:
	mkdir -p $(BUILD)
