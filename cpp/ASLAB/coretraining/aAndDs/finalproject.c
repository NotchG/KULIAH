#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <unistd.h>
#include <ncurses/ncurses.h>

void draw_button(WINDOW *win, const char *label, int starty, int startx) {
    int length = strlen(label) + 2;
    wattron(win, A_BOLD);
    box(win, 0, 0);
    mvwprintw(win, starty, startx-length, "%s", label);
    wattroff(win, A_BOLD);
    wrefresh(win);
}

int main(){
	initscr(); // Initialize the library
    cbreak(); // Disable line buffering
    noecho(); // Don't display typed characters
	HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	
	GetConsoleMode(console, &mode);
	SetConsoleMode(console, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
	
	INPUT_RECORD ir;
	DWORD count;
	COORD mousePos = {0, 0};

	int height = 3;
    int width = 50;
    int starty = (LINES - height * height) / 2; // Center vertically
    int startx = (COLS - width) / 2;   // Center horizontally

    WINDOW *win = newwin(height, width, starty, startx);
	WINDOW *win2 = newwin(height, width, (LINES - height + height * height) / 2, startx);
    refresh();

	draw_button(win, "Play", height / 2, width / 2);

	draw_button(win2, "Exit", height / 2, width / 2);
	
	while(1){
		ReadConsoleInput(console, &ir, 1, &count);
		
		if(ir.EventType == MOUSE_EVENT){
			if(ir.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED){
				if (mousePos.X >= 35 && mousePos.X <= 84) {
					if (mousePos.Y >= 10 && mousePos.Y <= 12) {
						draw_button(win, "Play Clicked!", height / 2, width / 2);
					}
					if (mousePos.Y >= 18 && mousePos.Y <= 20) {
						break;
					}
				}
			}
			
			mousePos.X = ir.Event.MouseEvent.dwMousePosition.X;
			mousePos.Y = ir.Event.MouseEvent.dwMousePosition.Y;
		}
	}
}
