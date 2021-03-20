FLAGS = -Wall -pedantic -std=c++20 -lncurses

app.out : main.o tablica.o tablica_wysw.o menu.o 
	g++ -o $@ $^
	doxygen config
	make -C latex/ -f Makefile
	cp latex/refman.pdf dokumentacja.pdf 
	make -C latex/ -f Makefile clean
main.o : main.cpp
	g++ -c ${FLAGS} -o $@ $^
tablica_wysw.o : tablica_wysw.cpp
	g++ -c ${FLAGS} -o $@ $^

tablica.o : tablica.cpp
	g++ -c ${FLAGS} -o $@ $^

menu.o : menu.cpp
	g++ -c ${FLAGS} -o $@ $^
