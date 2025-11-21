CXX = g++
TARGET = mygame
SRC = src/main.cpp src/game.cpp

CXXFLAGS = -Wall -std=c++17 -Iinclude
RAYLIB_CFLAGS := $(shell pkg-config --cflags raylib)
RAYLIB_LIBS   := $(shell pkg-config --libs raylib)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(RAYLIB_CFLAGS) -o $(TARGET) $(SRC) $(RAYLIB_LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

