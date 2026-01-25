CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

SRC = ToDoList/ToDolist.cpp SignUpIn/signUp.cpp
OUT = app

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	rm -f $(OUT)
