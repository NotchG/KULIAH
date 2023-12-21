#include <stdio.h>
#include <windows.h>
#include <unistd.h>

int main(){
	HANDLE console = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	
	GetConsoleMode(console, &mode);
	SetConsoleMode(console, ENABLE_EXTENDED_FLAGS | ENABLE_MOUSE_INPUT);
	
	INPUT_RECORD ir;
	DWORD count;
	COORD mousePos = {0, 0};

	
	while(1){
		ReadConsoleInput(console, &ir, 1, &count);
		
		if(ir.EventType == MOUSE_EVENT){
			if(ir.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED){
				printf("Mouse clicked at (%d, %d)\n", mousePos.X, mousePos.Y);
				
			}
			
			mousePos.X = ir.Event.MouseEvent.dwMousePosition.X;
			mousePos.Y = ir.Event.MouseEvent.dwMousePosition.Y;
		}
	}
}
