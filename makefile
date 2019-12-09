CXX = g++
CXXFLAGS = -g -std=c++11 

OBJS = final_main.o menu.o space.o empty.o gameboard.o

SRCS = final_main.cpp menu.cpp space.cpp empty.cpp gameboard.cpp

HEADERS = menu.hpp space.hpp empty.hpp gameboard.hpp

final_main: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o final_main 

$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean: 
	rm final_main $(OBJS)

