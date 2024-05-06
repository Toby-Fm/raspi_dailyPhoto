CXX=g++
CXXFLAGS=-std=c++17 `pkg-config --cflags opencv4`
LDFLAGS=`pkg-config --libs opencv4`

TARGET=main
SRC_DIR=src/cpp
SRCS=$(SRC_DIR)/main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(SRC_DIR)%.o: $(SRC_DIR)/%.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf main src/cpp/main.o


.PHONY: all clean
