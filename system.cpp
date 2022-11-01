#include <iostream>
#include <windows.h>
#include "system.h"
using namespace std;

void CursorView(char show) { //Ŀ�� ����
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) { //Ŀ�� ��ġ ����
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(int color) {  //�۾� �� ����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}