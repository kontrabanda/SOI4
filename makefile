CC=g++
CFLAGS=-Wall

all: clean main.o

main.o: src/main.cpp src/Buffer.h src/Producer.h src/Consumer.h
	$(CC) $(CFLAGS) src/main.cpp src/Buffer.cpp src/Consumer.cpp src/Producer.cpp -o bin/main.o -std=c++11

clean:
	rm -f *.o