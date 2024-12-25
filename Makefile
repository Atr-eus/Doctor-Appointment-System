CXX := g++
CXXFLAGS := -c -Wall -std=c++17 -Iinclude
LDFLAGS := 
SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=obj/%.o)
TARGET := program

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

obj/%.o: src/%.cpp | obj
	$(CXX) $(CXXFLAGS) $< -o $@

obj:
	mkdir -p obj

clean:
	rm -rf obj $(TARGET)
