CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test_element.cpp ticket.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test5

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@