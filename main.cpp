//https://blockdmask.tistory.com/400 (c++ 짝맞추기 게임)
//https://velog.io/@pwy9679/CPPTetris2 (c++ 테트리스 게임)에서 메인, 조작법 참고하였습니다.

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "system.h"
#include "screen.h"
#include "game.h"

int main() {
	int sel = 0;
	CursorView(false);	//커서 안 보이게 하기
	system("mode con cols=130 lines=40 | title Card Matching Game(무지개조)");	//콘솔 창 크기와 제목
	Screen screen;	//메인화면 설정
	Game game;	//게임 객체 생성

	while (sel != 1) {
		sel = screen.MainMenu();
		if (sel == 2) {
			exit(0); //게임 종료 버튼 누르면 게임 종료
		}
	}
	while (sel == 1) {
		system("mode con cols=90 lines=20 | title Card Matching Game(무지개조)");	//콘솔 창 크기와 제목
		game.Init1();
		game.printQuestion1(); //물음표 맵
		game.prinextra(40, 0);//카운트, 스테이지 표시
		game.MovePos();//방향키로 커서 이동
	}
}


