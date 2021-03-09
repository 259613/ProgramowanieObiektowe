FLAGS = -Wall -pedantic -std=c++17

./app : main.o tablica.o tablica_wysw.o menu.o 
	g++ -o app.out main.o tablica.o tablica_wysw.cpp menu.o

main.o : main.cpp
	g++ -c ${FLAGS} -o main.o main.cpp
tablica_wysw.o : tablica_wysw.cpp tablica.h
	g++ -c ${flags} -o tablica_wysw.o tablica_wysw.cpp

tablica.o : tablica.cpp tablica.h
	g++ -c ${FLAGS} -o tablica.o tablica.cpp

menu.o : menu.cpp menu.h
	g++ -c ${FLAGS} -o menu.o menu.cpp
