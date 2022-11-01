#include <iostream>
#include <windows.h>
#include "system.h"
using namespace std;

void CursorView(char show) { //커서 설정
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) { //커서 위치 지정
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int color) {  //글씨 색 설정
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}