# Makefile pro projekt simulace výtahu

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic
LDFLAGS =

# Cíle
TARGET = elevator_simulation
SRCS = main.cpp ElevatorSystem.cpp
OBJS = $(SRCS:.cpp=.o)

# Pravidla
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET) input.txt

# Závislosti
main.o: main.cpp ElevatorSystem.h
ElevatorSystem.o: ElevatorSystem.cpp ElevatorSystem.h

.PHONY: all clean run
