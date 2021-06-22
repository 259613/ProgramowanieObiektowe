#include "display.hpp"
#include "../utility/list.hpp"
#include <string>

Display::Display()
{
	display = initscr();
	keypad(stdscr, true);
	start_color();
	noecho();
	width = getmaxx(display);
	height = getmaxy(display);

	use_default_colors();
	init_pair(1, -1, -1);
	init_pair(2, COLOR_RED, 0);
}
void Display::refreshDisplay()
{
	refresh();
	if (is_term_resized(height, width))
	{

		width = getmaxx(display);
		height = getmaxy(display);
	}
}
int Display::simpleControl()
{
	int x = 0;
	while (true)
	{
		keypad(stdscr, true);
		switch (x = getch())
		{
			case KEY_UP:
				return 1;
			case KEY_DOWN:
				return -1;
			case 10:
				return 0;
			default:
				printf("%d",x);
		}
	}
}
int Display::simpleMenu()
{
	erase();
	List<std::string> options = {"Wczytaj arkusz","Utworz arkusz", "Wyjdz z programu"};
	auto window = newwin(10, 20, height / 2 - 5, width / 2 - 10);
	size_t selectorX{};

	while(true){
		box(window, 0, 0);
		int i = 0;
		for(auto element : options){
			if(selectorX==i){
				wattron(window, COLOR_PAIR(2));
			}
			mvwprintw(window, 2+2*i, 1, selectorX==i?"> ":"  ");
			mvwprintw(window, 2+2*i, 3, element.c_str());
			wattroff(window, COLOR_PAIR(2));
			i++;
		}
		wrefresh(window);
		refreshDisplay();
		switch(simpleControl()){
			case -1:{
				if(selectorX < 2){
					selectorX++;
				}
				break;
			}
			case 0:{
				return selectorX;
			}
			case 1:{
				if(selectorX > 0){
					selectorX--;
				}
				break;

			}
		}
	}

}
