CXX = g++
CXXFLAGS = -Wall

proj3: LinkedList.o proj3.cpp
	$(CXX) $(CXXFLAGS) -g LinkedList.o proj3.cpp -o proj3

LinkedList.o: LinkedList.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -g -c LinkedList.cpp
clean:
	rm -rf *.o
	rm -f *# *h.gch *~
