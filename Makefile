CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=test_element.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=test2

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@