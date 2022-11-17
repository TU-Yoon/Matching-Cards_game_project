#pragma once
using namespace std;

class Game {
public:
	void gameclear(int j);
	void stop();
	void restart();
	void gameover();
	void MovePos(); //스테이지 1에서의 커서 조작
	void MovePos2();
	void MovePos3();
	char questionMap1[3][4]; // 카드 수와 똑같은 물음표 수를 문자형 배열에 저장
	char questionMap2[4][4]; 
	char questionMap3[5][4];
	
	void printQuestion1();//물음표 맵 출력
	void printQuestion2();
	void printQuestion3();
	void prinextra(int x, int y);//카운트랑 스테이지를 표시하는 함수 , xy는 출력할 위치지정

	void Init1();//물음표로 초기화
	void Init2();
	void Init3();
};

class FlipCard {
public:
	int px[2];
	int py[2];
	int posx[2];
	int posy[2];
	int flipCount;//뒤집은 카드 개수
	int matchedCardCount=0;
    void Filpcard(); //카드 뒤집었을때 같은 카드면 유지, 다르면 다시 물음표로 바꿈
	void Filpcard2();
	void Filpcard3();
	int i = 1;
};


