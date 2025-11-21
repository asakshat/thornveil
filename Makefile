CXX = g++
TARGET = thornveil

SRC = $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)

INCLUDE = -Iinclude

CXXFLAGS = -Wall -std=c++17 $(INCLUDE)

RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib)
RAYLIB_LIBS   := $(shell pkg-config --libs raylib)

all: $(TARGET)

#  linking object files and building it
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) $(RAYLIB_CFLAGS) $(RAYLIB_LIBS) -o $(TARGET)

#  compile to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(RAYLIB_CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJ) $(TARGET)

