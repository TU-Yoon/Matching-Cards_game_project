#include "game.h"
#include "scoreboard.h"
#include "system.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

Score scores[6];	//순위 객체배열 생성

void compareScore(int score) {	//이름 입력 및 점수 비교 연산
	string name;	//이름 문자열
	setColor(11);	//파란색으로 gameclear와 같게
	gotoxy(25, 3);
	cout << "==========================================";
	gotoxy(25, 4);
	cout << "=========== G A M E C L E A R ============";
	gotoxy(25, 7);
	cout << "==========================================";
	gotoxy(39, 5);
	cout << "이름 : ";
	getline(cin, name);	//이름 입력
	setColor(7);	//다시 검은색으로

	scores[5].score = score;	//객체의 마지막 score 멤버에 최종 스코어 값 대입
	scores[5].name = name;		//객체의 마지막 name 멤버에 이름 값 대입
	Score tmp;	//값을 임시로 넣어둘 tmp 객체 생성

	for (int i = 5; i > 0 ; i--) {	//5 -> 1로 객체의 score멤버값을 하나씩 비교하는 연산
		if (scores[i].score == scores[i - 1].score) break;
		else if (scores[i].score > scores[i - 1].score) {
			tmp = scores[i - 1];
			scores[i - 1] = scores[i];
			scores[i] = tmp;
		}
		else break;
	}
}

void scoreBoard() {	//점수판 출력
	gotoxy(28, 3); cout << "■□■□■최고  점수□■□■□";
	gotoxy(28, 4); cout << "□ 1등.       " << setfill('0') << setw(4) << scores[0].score << "       " << setfill('X') << setw(3) << scores[0].name << "■";
	gotoxy(28, 5); cout << "■ 2등.       " << setfill('0') << setw(4) << scores[1].score << "       " << setfill('X') << setw(3) << scores[1].name << "□";
	gotoxy(28, 6); cout << "□ 3등.       " << setfill('0') << setw(4) << scores[2].score << "       " << setfill('X') << setw(3) << scores[2].name << "■";
	gotoxy(28, 7); cout << "■ 4등.       " << setfill('0') << setw(4) << scores[3].score << "       " << setfill('X') << setw(3) << scores[3].name << "□";
	gotoxy(28, 8); cout << "□ 5등.       " << setfill('0') << setw(4) << scores[4].score << "       " << setfill('X') << setw(3) << scores[4].name << "■";
	gotoxy(28, 9); cout << "■□■□■□■□■□■□■□■";
}