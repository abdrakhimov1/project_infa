CC=g++
CFLAGS=-c -std=c++11
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SOURCES=main.cpp WorkWithPairs.cpp Dot.cpp Components.cpp GameObject.cpp IsIn.cpp resources.cpp Extractors.cpp AnaliticGeometry.cpp Physics.cpp Rendering.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o main
