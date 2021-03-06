
CC=gcc
CFLAGS=-c -Wall
LDFLAGS=-Iinclude

SOURCES=src/al_file_handling.c src/al_observer_list.c src/al_temp.c src/ardu-logger.c
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=ardu-logger

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
