FLAGS = -Wall -pedantic -std=c++20 -lncurses
CATALOG = ./ProgramowanieObiektowe

app.out : main.o tablica.o tablica_wysw.o menu.o menuCurses.o WyswietlaczArkusz.o
	g++ -lncurses -o $@ $^
	doxygen config
	make -C latex/ -f Makefile
	cp latex/refman.pdf dokumentacja.pdf 
	make -C latex/ -f Makefile clean
main.o : ${CATALOG}/main.cpp
	g++ -c ${FLAGS} -o $@ $^
tablica_wysw.o : ${CATALOG}/tablica/tablica_wysw.cpp
	g++ -c ${FLAGS} -o $@ $^
tablica.o : ${CATALOG}/tablica/tablica.cpp
	g++ -c ${FLAGS} -o $@ $^
menu.o : ${CATALOG}/menu/menu.cpp
	g++ -c ${FLAGS} -o $@ $^
WyswietlaczArkusz.o : ${CATALOG}/cursesUI/WyswietlaczArkusz.cpp
	g++ -c ${FLAGS} -o $@ $^
menuCurses.o : ${CATALOG}/cursesUI/menu.cpp
	g++ -c ${FLAGS} -o $@ $^
clean	:  
	echo "Czyszczenie katalogu"
	rm -rf latex html *.o *.pdf $@
