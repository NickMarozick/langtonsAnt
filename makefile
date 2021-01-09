
output: main.o ant.o 
	g++ -std=c++11 main.o ant.o -o AntGo

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

ant.o: ant.cpp ant.hpp
	g++ -std=c++11 -c ant.cpp

clean:
	rm *.o output

