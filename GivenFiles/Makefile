# out: clean compile execute

# compile: main.cpp
# 	g++ -g -Wall -std=c++14 main.cpp -o mainexe

# execute: mainexe
# 	./mainexe

# clean:
# 	rm -f mainexe

CXX := g++
CXXFLAGS := -std=c++14 -Wall -g -Ih

BIN := mainexe
SRCS := $(wildcard cpp/*.cpp)
OBJS := $(SRCS:.cpp=.o)

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(OBJS) -o $@

cpp/%.o: cpp/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(BIN) cpp/*.o
