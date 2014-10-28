
CC=gcc
CFLAGS=-c -Wall
LDFLAGS=

SOURCES=src/ardu-logger.c
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=ardu-logger

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
