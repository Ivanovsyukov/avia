CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test_element.cpp ticket.cpp utils.cpp array.cpp database.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test6

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@