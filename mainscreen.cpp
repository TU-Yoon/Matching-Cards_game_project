#include "screen.h"
#include "system.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
using namespace std;

Screen::Screen() {
	sel = 1;
	enter = 0;
}

void printCard(int x, int y) {	//제목 출력
	gotoxy(x, y);   printf("  ■■      ■■    ■■■    ■■■  ");
	gotoxy(x, y+1); printf("■    ■  ■    ■  ■    ■  ■    ■");
	gotoxy(x, y+2); printf("■        ■    ■  ■    ■  ■    ■");
	gotoxy(x, y+3); printf("■        ■■■■  ■■■    ■    ■");
	gotoxy(x, y+4); printf("■    ■  ■    ■  ■    ■  ■    ■");
	gotoxy(x, y+5); printf("  ■■    ■    ■  ■    ■  ■■■  ");
}

void printMatching(int x, int y) {
	gotoxy(x, y);     printf("▣      ▣    ▣▣   ▣▣▣▣▣    ▣▣    ▣    ▣  ▣▣▣  ▣    ▣    ▣▣  ");
	gotoxy(x, y + 1); printf("▣▣  ▣▣  ▣    ▣     ▣      ▣    ▣  ▣    ▣    ▣    ▣    ▣  ▣    ▣");
	gotoxy(x, y + 2); printf("▣  ▣  ▣  ▣    ▣     ▣      ▣        ▣▣▣▣    ▣    ▣▣  ▣  ▣      ");
	gotoxy(x, y + 3); printf("▣      ▣  ▣▣▣▣     ▣      ▣        ▣    ▣    ▣    ▣  ▣▣  ▣  ▣▣");
	gotoxy(x, y + 4); printf("▣      ▣  ▣    ▣     ▣      ▣    ▣  ▣    ▣    ▣    ▣    ▣  ▣    ▣");
	gotoxy(x, y + 5); printf("▣      ▣  ▣    ▣     ▣        ▣▣    ▣    ▣  ▣▣▣  ▣    ▣    ▣▣  ");
}


//메인화면 출력
int Screen::MainMenu() {
	cout << "\n\n\n\n";
	setColor(12);	//빨간색으로 글자색 변환
	printCard(15, 6);
	setColor(11);	//파란색으로 글자색 변환
	printMatching(37, 14);
	cout << "\n";

	setColor(7);	//검정색으로 글자색 다시 변환
	if (sel == 1) {	//게임시작 선택
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t  " << "> Game Start\n";
		cout << "\n\n\t\t\t\t\t\t\t  " << "Exit\n";
	}
	else if (sel == 2) {	//게임종료 선택
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t  " << "Game Start\n";
		cout << "\n\n\t\t\t\t\t\t\t  " << "> Exit\n";
	}
	

	if (enter == 1) {	//선택한 메뉴를 실행
		system("cls");
		return sel;
	}
	else {
		SelectMenu();	//위아래로 움직이면서 메뉴를 선택
		system("cls");
		return 0;
	}
}

	//키보드를 이용해 메뉴 선택
	void Screen::SelectMenu() {
		char c;

		c = _getch(); //키보드 입력 받아서 해당 위치로 이동 시켜줌
		if (c == 80) {	//키보드 down키 입력값이 80
			if (sel < 3)
				sel += 1;
		}
		else if (c == 72) {	//키보드 up키 입력값이 72
			if (sel > 1)
				sel -= 1;
		}
		if (c == 13) {		//키보드 enter키 입력값이 13
			enter = 1;
		}
	}

	/*방향키 입력값 참고
	<- 좌측방향키(75)  ->우측방향키(77)  위 방향키(72) 아래방향키 (80) 
	enter키(13)
	*/
