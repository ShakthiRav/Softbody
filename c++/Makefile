game: game.o point.o spring.o shape.o vector.o
	g++ -Wall -std=c++17 -O3 game.cpp -o game -lsfml-graphics -lsfml-window -lsfml-system

game.o: game.cpp
	g++ -Wall -std=c++17 -O3 -c -o game.o game.cpp

point.o: point.cpp point.hpp
	g++ -Wall -std=c++17 -O3 -c -o point.o point.cpp

spring.o: spring.cpp spring.hpp point.hpp vector.hpp
	g++ -Wall -std=c++17 -O3 -c -o spring.o spring.cpp

shape.o: shape.cpp shape.hpp point.hpp spring.hpp
	g++ -Wall -std=c++17 -O3 -c -o shape.o shape.cpp

vector.o: vector.cpp vector.hpp
	g++ -Wall -std=c++17 -O3 -c -o vector.o vector.cpp
