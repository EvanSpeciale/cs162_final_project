main: main.o Space.o Map.o Game.o
	g++ -std=c++11 main.o Space.o Map.o Game.o -o main

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++11 -c Space.cpp

Map.o: Map.cpp Map.hpp
	g++ -std=c++11 -c Map.cpp

Game.o: Game.cpp Game.hpp
	g++ -std=c++11 -c Game.cpp

clean:
	rm *.o main
