#include "game.h"
#include "system.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
using namespace std;


Game::Game() {

}

void Game::gamescreen() {
	system("cls");
	cout << "카드게임화면";
}


//그냥 툴만 만들어 둔 것들
void Game::stop(){
	int pas = 1;
	int enter2 = 0;
	setColor(14);
	gotoxy(10, 3);
	cout << "==========================================";
	gotoxy(10, 4);
	cout << "=============== 일 시 정 지 ==============";
	gotoxy(17, 6);
	cout << "REPLAY ";
	gotoxy(38, 6);
	cout << "EXIT ";
	gotoxy(10, 8);
	cout << "==========================================";
	setColor(7);	//다시 검은색으로
}

void Game::gameover() {
	setColor(12);
	gotoxy(10, 3);
	cout << "==========================================";
	gotoxy(10, 4);
	cout << "============= G A M E O V E R ============";
	gotoxy(28, 6);
	cout << "점수: 0\n ";
	gotoxy(19, 7);
	cout << "> 스페이스바를 누르세요!\n";
	gotoxy(10, 9);
	cout << "==========================================";
	setColor(7);	//다시 검은색으로
}

void Game::gameclear() {
	setColor(11);
	gotoxy(10, 3);
	cout << "==========================================";
	gotoxy(10, 4);
	cout << "=========== G A M E C L E A R ============";
	gotoxy(24, 6);
	cout << "점수: 990\n ";
	gotoxy(24, 7);
	cout << "이름:_______ \n";
	gotoxy(10, 9);
	cout << "==========================================";
	setColor(7);	//다시 검은색으로
}