CXX=g++
CXXFLAGS=-std=c++17 `pkg-config --cflags opencv4`
LDFLAGS=`pkg-config --libs opencv4`

TARGET=main
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) -c $< $(CXXFLAGS)

clean:
	rm -rf main main.o


.PHONY: all clean
