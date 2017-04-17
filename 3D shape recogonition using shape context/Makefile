CXXFLAGS:= $(shell pkg-config --cflags opencv)

LDLIBS:= $(shell pkg-config --libs opencv)

test1: main.o
	g++ -o test1 main.o $(LDLIBS)
#$(CXXFLAGS) $(LDLIBS)
main.o: main.cpp
	g++ -c main.cpp $(CXXFLAGS)
clean: 
	rm -f *.o
