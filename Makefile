FLAGS = -Wall -pedantic -std=c++20
CATALOG = ./ProgramowanieObiektowe

app.out : main.o tablica.o tablica_wysw.o menu.o zapisOdczyt.o utility.o operacje.o column.o cell.o intCell.o stringCell.o
	g++ -o $@ $^
	doxygen config
	make -C latex/ -f Makefile
	cp latex/refman.pdf dokumentacja.pdf 
	make -C latex/ -f Makefile clean
main.o : ${CATALOG}/main.cpp
	g++ -c ${FLAGS} -o $@ $^
tablica_wysw.o : ${CATALOG}/arkusz/tablica/tablica_wysw.cpp
	g++ -c ${FLAGS} -o $@ $^
tablica.o : ${CATALOG}/arkusz/tablica/tablica.cpp
	g++ -c ${FLAGS} -o $@ $^
menu.o : ${CATALOG}/menu/menu.cpp
	g++ -c ${FLAGS} -o $@ $^
zapisOdczyt.o : ${CATALOG}/io/zapisOdczyt.cpp
	g++ -c ${FLAGS} -o $@ $^
utility.o : ${CATALOG}/utility/utility.cpp
	g++ -c ${FLAGS} -o $@ $^
operacje.o : ${CATALOG}/operacje/operacje.cpp
	g++ -c ${FLAGS} -o $@ $^
column.o : ${CATALOG}/arkusz/kolumna/column.cpp
	g++ -c ${FLAGS} -o $@ $^
cell.o : ${CATALOG}/arkusz/komorka/cell.cpp
	g++ -c ${FLAGS} -o $@ $^
intCell.o : ${CATALOG}/arkusz/komorka/intCell.cpp
	g++ -c ${FLAGS} -o $@ $^
stringCell.o : ${CATALOG}/arkusz/komorka/stringCell.cpp
	g++ -c ${FLAGS} -o $@ $^
clean	:  
	echo "Czyszczenie katalogu"
	rm -rf latex html *.o *.pdf $@
