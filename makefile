CC=gcc
CFLAGS=-Wall

EXECUTABLE=game
SOURCES=main.c utils/*.c games/*.c 

all:
	$(CC) $(CFLAGS) $(SOURCES) -o $(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE)
