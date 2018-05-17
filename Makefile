CC=g++
CFLAGS=-c -std=c++11
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lpthread
SOURCES=main.cpp Logic/WorkWithPairs.cpp Resources/Dot.cpp Resources/Components.cpp Resources/GameObject.cpp Logic/IsIn.cpp Resources/resources.cpp Logic/Extractors.cpp Physics/AnaliticGeometry.cpp Physics/Physics.cpp Drawing/Rendering.cpp Drawing/drawAll.cpp Resources/simpleFactory.cpp Drawing/drawLines.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o main
