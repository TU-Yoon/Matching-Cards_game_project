/* 오류 수정한 것들
- 게임 실행화면 작게 맞추면 예쁠듯
- 게임 실행화면 위쪽에 공백 있으면 예쁠듯
- 3000점 너무 많은 감 있음 줄여봐도 괜찮을듯
ㄴ 2000점에 1단계 -50 2단계 -40 3단계 -30 으로 일단 수정
- 1단계 점수가 그대로 2단계로 가야하는데 2단계 넘어가면 기본점수부터 시작함
- 한번도 안틀리고 1단계로 넘어가면 클리어 화면에서 점수 0점으로 뜸
- while문 for문으로 바꿔야함 자동으로 단계 넘어가게
ㄴ 그냥 if문으로 해결함
- stop 눌러도 리플레이 됨
ㄴ 해도 해도 안되길래 키 입력 1,2번으로 바꿔서 쉽게 해결함 
- 0점되면 게임 오버 떠야함
- 2단계 카드 맞은 횟수 안올라감..
- 이미 뒤집힌 숫자 누르면 다시 뒤집힘
- 1장의 카드 두번 누르면 맞았다고 인식해버림




- 일시정지 하고 다시 플레이하면 예전에 맞췄던 카드 맞춘 카드로 인식 안됨 *******************277번줄 오류 수정해야함***********
*/
#include "game.h"
#include "system.h"
#include "scoreboard.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std; 
#define MAX_X 30
#define MAX_Y 9

const int jungdap1[3][4] = {//정답 배열
	{3,5,1,3},
	{6,1,2,4},
	{2,6,4,5},
	};

const int jungdap2[4][4] = {
	{5,4,6,3},
	{7,1,1,5},
	{3,2,7,2},
	{6,4,8,8}
};

const int jungdap3[4][5] = {
	{3,9,1,3,6},
	{8,5,1,0,2},
	{7,5,9,6,7},
	{0,8,2,4,4},
};

int stage = 1;	//스테이지 점수
int score1, score2, score3 = 0;	//게임 점수
int cardju[6] = { 10,10,10,10,10,10 };
int cardju2[8] = { 10,10,10,10,10,10,10,10 };
int cardju3[10] = { 10,10,10,10,10,10,10,10,10,10};
int* p;

void Game::MovePos() { //커서 위치 이동,키이벤트
	score1 = 2000;
	setColor(10);
	gotoxy(46, 5); printf("%d", score1);
	int X = 3;
	int Y = 3;
	int site;
	int CountX = 0, CountY = 0;
	FlipCard flip;
	flip.flipCount = 0;

	gotoxy(X, Y);
	printf(" ^");
	while (1) {
		site = _getch();
		switch (site) {
		case 72://up입력
			if (Y > 3) {
				gotoxy(X, Y);
				printf("  ");
				Y -= 3;
				gotoxy(X, Y);
				printf(" ^");
				CountY--;
			}break;
		case 75://left
			if (X > 3) {
				gotoxy(X, Y);
				printf("  ");
				X -= 9;
				gotoxy(X, Y);
				printf(" ^");
				CountX--;
			}break;
		case 77://right
			if (X != MAX_X) {
				gotoxy(X, Y);
				printf("  ");
				X += 9;
				gotoxy(X, Y);
				printf(" ^");
				CountX++;
			}break;
		case 80://down
			if (Y != MAX_Y) {
				gotoxy(X, Y);
				printf("  ");
				Y += 3;
				gotoxy(X, Y);
				printf(" ^");
				CountY++;
			}break;
		case 32: //space bar
			gotoxy(X, Y - 1);
			setColor(10);
			printf("[%d]", jungdap1[CountY][CountX]);
			flip.flipCount++; //스페이스 바 누를 때마다 카드 뒤집은 횟수 증가
			int n;
			n = flip.flipCount % 2; //n에 flipCount를 2로 나눈 나머지 값을 저장
			if (n == 0) { //나머지 값이 0일 때, 즉 스페이스 바가 2번 눌렸을때(카드가 2개 뒤집혔을때) 실행
				p = find(cardju, cardju + 6, jungdap1[CountY][CountX]);
				if (p != cardju + 6) {	//cardju 배열에 정답카드가 들어간 경우=이미 맞춰진 숫자인 경우
					flip.flipCount--;
				}
				else {
					flip.posx[1] = X;
					flip.posy[1] = Y - 1;
					flip.px[1] = CountX;
					flip.py[1] = CountY;
					flip.Filpcard();
					if (flip.matchedCardCount == 6) {
						system("cls");//화면 지우고
						gameclear(score1);//클리어 화면 출력
						gotoxy(24, 7); printf("                               ");
						Sleep(600);//잠시 기다렸다가
						system("cls"); //클리어 화면 지우고
						stage = 2;//stage 2로 수정
						score2 = score1;
						flip.matchedCardCount = 0;
						Init2(); //2단계 물음표맵 만들고
						printQuestion2();//2단계 물음표 맵 출력
						prinextra(40, 0); //옆에 부가적인 것들 출력
						MovePos2();
					}
				}
			}else {	//스페이스바가 홀수번 눌렸을때
				p = find(cardju, cardju + 6, jungdap1[CountY][CountX]);
				if (p != cardju + 6) {	//cardju 배열에 정답카드가 들어간 경우=이미 맞춰진 숫자인 경우
					flip.flipCount--;
				}else {//cardju 배열에 정답카드가 없는 경우=짝이 안맞춰진 숫자인 경우
					flip.posx[0] = X; //뒤집은 카드의 XY좌표를 flipPos에 각자 저장
					flip.posy[0] = Y - 1;
					flip.px[0] = CountX;
					flip.py[0] = CountY;
				}
			}break;
		case 27:
			stop();
			break;
		default:
			break;
		}
	}
}

void FlipCard::Filpcard() { //뒤집은 카드의 숫자가 같은지 다른지 비교하고 연산
	Game over;
		if (jungdap1[py[0]][px[0]] == jungdap1[py[1]][px[1]]) {//뒤집은 카드가 같을때
			gotoxy(posx[0], posy[0]); //첫번째 xy좌표 위치로 가서
			printf("[%d]", jungdap1[py[0]][px[0]]);//그 위치에 있는 정답 숫자 출력
			gotoxy(posx[1], posy[1]);
			printf("[%d]", jungdap1[py[1]][px[1]]);
			for (int i = 0; i < 6; i++) {
				if (cardju[i] == 10) {	//cardju 주머니 인덱스가 비어있는 경우
					cardju[i] = jungdap1[py[1]][px[1]];	//짝맞춰진 숫자 카드를 넣는다
					break;
				}
			}
			++matchedCardCount; //맞춘 카드 수 증가
			gotoxy(40, 6); cout << "맞춘 카드" << matchedCardCount;
			return;
		}else { //카드가 서로 다를땐 뒤집었던 두개의 카드를 다시 물음표로 바꿔준다.그리고 점수 감소.
			setColor(15);
			Sleep(600);
			gotoxy(posx[0], posy[0]); printf("[?]");//첫번째로 뒤집은 카드의 좌표로 이동하고, 물음표 출력
			gotoxy(posx[1], posy[1]); printf("[?]");//두번째로 뒤집은 카드의 좌표로 이동하고,  물음표 출력
			if (i <= 41) {
				score1 = score1 - 50;
				if (score1 <= 0)
					over.gameover();
				setColor(10);
				gotoxy(46, 5); printf("%d", score1); printf("               ");
			}    i++;
		}
	}

void Game::Init1() { //맵 초기화
	cout << "\n\n";
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			questionMap1[y][x] = '?';
		}
	}
}
void Game::Init2(){
	cout << "\n\n";
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				questionMap2[y][x] = '?';
			}
		}
	}
void Game::Init3(){
	cout << "\n\n";
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 4; x++) {
				questionMap3[y][x] = '?';
			}
		}
	}

void Game::printQuestion1() {	//물음표 카드들 출력 1단계
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 4; i++) {
			printf("   [%c]   ", questionMap1[i][j]);
		}printf("\n\n\n");
	}
}
void Game::printQuestion2() {	//물음표 카드들 출력 2단계
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("   [%c]   ", questionMap2[i][j]);
		}printf("\n\n\n");
	}
}
void Game::printQuestion3() {	//물음표 카드들 출력 3단계
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 5; i++) {
			printf("   [%c]   ", questionMap3[i][j]);
		}printf("\n\n\n");
	}
}

void Game::prinextra(int x, int y) {	//조작방법, 스코어 등 부가적인 것들 출력
	setColor(11); gotoxy(x, y + 2); 	cout << "STAGE-";	cout<< stage;
	setColor(10);
	gotoxy(x, y+5);  printf("SCORE-"); 
	setColor(12);
	gotoxy(x, y+9);   printf("이동: → ← ↑ ↓ ");
	gotoxy(x, y+11);   printf("뒤집기: space bar");
	setColor(7);
	gotoxy(x+17, y+2);   printf("▶일시정지:ESC");//27 -> esc아스키 코드 값 32->스페이스 아스키 코드 값
}

void Game::stop() {
	FlipCard flip;
	setColor(14);
	gotoxy(25, 3);
	cout << "========================================";
	gotoxy(25, 4);
	cout << "============== 일 시 정 지 =============";
	gotoxy(25, 5);
	cout << "                1 REPLAY                ";
	gotoxy(25, 6);
	cout << "                2 EXIT                  ";
	gotoxy(25, 7);
	cout << "========================================";
	setColor(7);    //다시 검은색으로
	char c;
	c = _getch();

	if (c == 49) { //replay
		for (int i = 0; i < 6; i++) {
			if (cardju[i] != 10)
				cardju[i] = 10;
		}
		for (int i = 0; i < 8; i++) {
			if (cardju2[i] != 10)
				cardju2[i] = 10;
		}
		for (int i = 0; i < 10; i++) {
			if (cardju3[i] != 10)
				cardju3[i] = 10;
		}
		system("cls");//화면 지우고
		Sleep(200);
		stage = 1;//stage 1로 수정
		Init1(); //1단계 물음표맵 만들고
		printQuestion1();//1단계 물음표 맵 출력
		prinextra(40, 0); //옆에 부가적인 것들 출력
		MovePos();
	}else if (c == 50) {	//exit
		system("cls");//화면 지우고
		Sleep(200);
		exit(0);
	}
}

void Game::restart() {	//점수판 공개 후 게임 재시작하는 창 출력
	FlipCard flip;
	setColor(14);
	gotoxy(28, 11); cout << "    1 Restart      2 Exit";
	setColor(7);    //다시 검은색으로
	char c;
	c = _getch();

	if (c == 49) { //replay
		for (int i = 0; i < 6; i++) {
			if (cardju[i] != 10)
				cardju[i] = 10;
		}
		for (int i = 0; i < 8; i++) {
			if (cardju2[i] != 10)
				cardju2[i] = 10;
		}
		for (int i = 0; i < 10; i++) {
			if (cardju3[i] != 10)
				cardju3[i] = 10;
		}
		system("cls");//화면 지우고
		Sleep(200);
		stage = 1;//stage 1로 수정
		Init1(); //1단계 물음표맵 만들고
		printQuestion1();//1단계 물음표 맵 출력
		prinextra(40, 0); //옆에 부가적인 것들 출력
		MovePos();
	}
	else if (c == 50) {	//exit
		system("cls");//화면 지우고
		Sleep(200);
		exit(0);
	}
}


void Game::gameover() {
	Game rank;
	system("cls");//화면 지우고
	setColor(12);
	gotoxy(20, 3);
	cout << "========================================";
	gotoxy(20, 4);
	cout << "============ G A M E O V E R ===========";
	gotoxy(20, 5);
	cout << "                  점수: 0         ";
	gotoxy(20, 6);
	cout << "        > 스페이스바를 누르세요!";        
	gotoxy(20, 7);
	cout << "========================================";
	setColor(7);    //다시 검은색으로
	char input;
	input = _getch();
	if (input == 32) {
		system("cls");
		compareScore(0);
		scoreBoard();
	}
}

void Game::gameclear(int score) {
	setColor(11);
	gotoxy(25, 3);
	cout << "==========================================";
	gotoxy(25, 4);
	cout << "=========== G A M E C L E A R ============";
	gotoxy(39, 5);
    printf("점수: %d ", score);
	gotoxy(25, 7);
	cout << "==========================================";
	setColor(7);	//다시 검은색으로
	Sleep(5000);
	system("cls");
}

void FlipCard::Filpcard2() { //뒤집은 카드의 숫자가 같은지 다른지 비교하고 연산
	Game over2;
	if (jungdap2[py[0]][px[0]] == jungdap2[py[1]][px[1]]) {//뒤집은 카드가 같을때**여기 조건문 오류*...였는데 해결!
		gotoxy(posx[0], posy[0]); //첫번째 xy좌표 위치로 가서
		printf("[%d]", jungdap2[py[0]][px[0]]);//그 위치에 있는 정답 숫자 출력
		gotoxy(posx[1], posy[1]);
		printf("[%d]", jungdap2[py[1]][px[1]]);
		for (int i = 0; i < 8; i++) {
			if (cardju2[i] == 10) {	//cardju 주머니 인덱스가 비어있는 경우
				cardju2[i] = jungdap2[py[1]][px[1]];	//짝맞춰진 숫자 카드를 넣는다
				break;
			}
		}
		matchedCardCount++;
		gotoxy(40, 6); cout << "맞춘 카드" << matchedCardCount;
		return;
	}
	else { //카드가 서로 다를땐 뒤집었던 두개의 카드를 다시 물음표로 바꿔준다.
		setColor(15);
		Sleep(600);
		gotoxy(posx[0], posy[0]); printf("[?]");//첫번째로 뒤집은 카드의 좌표로 이동하고, 물음표 출력
		gotoxy(posx[1], posy[1]); printf("[?]");//두번째로 뒤집은 카드의 좌표로 이동하고,  물음표 출력
		if (i <= 41) {
			score2 = score2 - 40;
			if (score2 <= 0)
				over2.gameover();
			setColor(10);
			gotoxy(46, 5); printf("%d", score2); printf("               ");
		}    i++;
	}
	
}
void Game::MovePos2() {//2단계 커서 움직임
	setColor(10);
	gotoxy(46, 5); printf("%d", score2);
	int X = 3;
	int Y = 3;
	int site;
	int CountX = 0, CountY = 0;
	FlipCard flip;
	flip.flipCount = 0;
	gotoxy(X, Y);
	printf(" ^");
	while (1) {
		site = _getch();
		switch (site) {
		case 72://up입력
			if (Y > 3) {
				gotoxy(X, Y);
				printf("  ");
				Y -= 3;
				gotoxy(X, Y);
				printf(" ^");
				CountY--;
			}break;
		case 75://left
			if (X > 3) {
				gotoxy(X, Y);
				printf("  ");
				X -= 9;
				gotoxy(X, Y);
				printf(" ^");
				CountX--;
			}break;
		case 77://right
			if (X != MAX_X) {
				gotoxy(X, Y);
				printf("  ");
				X += 9;
				gotoxy(X, Y);
				printf(" ^");
				CountX++;
			}break;
		case 80://down
			if (Y != 12) {
				gotoxy(X, Y);
				printf("  ");
				Y += 3;
				gotoxy(X, Y);
				printf(" ^");
				CountY++;
			}break;
		case 32: //space bar
			gotoxy(X, Y - 1);
			setColor(10);
			printf("[%d]", jungdap2[CountY][CountX]);
			flip.flipCount++; //스페이스 바 누를 때마다 카드 뒤집은 횟수 증가

			int n;
			n = flip.flipCount % 2; //n에 flipCount를 2로 나눈 나머지 값을 저장. 

			if (n == 0) {//나머지 값이 0일 때, 즉 스페이스 바가 2번 눌렸을때(카드가 2개 뒤집혔을때) 실행
				p = find(cardju2, cardju2 + 8, jungdap2[CountY][CountX]);
				if (p != cardju2 + 8) {	//cardju 배열에 정답카드가 들어간 경우=이미 맞춰진 숫자인 경우
					flip.flipCount--;
				}
				else {
					flip.posx[1] = X;
					flip.posy[1] = Y - 1;
					flip.px[1] = CountX;
					flip.py[1] = CountY;
					flip.Filpcard2();
					if (flip.matchedCardCount == 8) {
						system("cls");//화면 지우고
						gameclear(score2);//클리어 화면 출력
						gotoxy(24, 7); printf("                               ");
						Sleep(600);//잠시 기다렸다가
						system("cls"); //클리어 화면 지우고
						stage = 3;//stage 2로 수정
						flip.matchedCardCount = 0;
						score3 = score2;
						Init3(); //3단계 물음표맵 만들고
						printQuestion3();//3단계 물음표 맵 출력
						prinextra(50, 0); //옆에 부가적인 것들 출력
						MovePos3();
					}
				}
			}
			else //스페이스바가 홀수번 눌렸을때
			{
				p = find(cardju2, cardju2 + 8, jungdap2[CountY][CountX]);
				if (p != cardju2 + 8) {	//cardju 배열에 정답카드가 들어간 경우=이미 맞춰진 숫자인 경우
					flip.flipCount--;
				}
				else {
					flip.posx[0] = X; //뒤집은 카드의 XY좌표를 flipPos에 각자 저장
					flip.posy[0] = Y - 1;
					flip.px[0] = CountX;
					flip.py[0] = CountY;
				}
			}break;
		case 27:
			stop();
			break;
		default:
			break;
		}
	}
}

void FlipCard::Filpcard3() {
	Game over3;
	if (jungdap3[py[0]][px[0]] == jungdap3[py[1]][px[1]]) {//뒤집은 카드가 같을때
		gotoxy(posx[0], posy[0]); //첫번째 xy좌표 위치로 가서
		printf("[%d]", jungdap3[py[0]][px[0]]);//그 위치에 있는 정답 숫자 출력
		gotoxy(posx[1], posy[1]);
		printf("[%d]", jungdap3[py[1]][px[1]]);
		for (int i = 0; i < 10; i++) {
			if (cardju3[i] == 10) {	//cardju 주머니 인덱스가 비어있는 경우
				cardju3[i] = jungdap3[py[1]][px[1]];	//짝맞춰진 숫자 카드를 넣는다
				break;
			}
		}
		++matchedCardCount;
		gotoxy(50, 6); cout << "맞춘 카드" << matchedCardCount;
		return;
	}
	else { //카드가 서로 다를땐 뒤집었던 두개의 카드를 다시 물음표로 바꿔준다.
		setColor(15);
		Sleep(600);
		gotoxy(posx[0], posy[0]); printf("[?]");//첫번째로 뒤집은 카드의 좌표로 이동하고, 물음표 출력
		gotoxy(posx[1], posy[1]); printf("[?]");//두번째로 뒤집은 카드의 좌표로 이동하고,  물음표 출력
		if (i <= 41) {
			score3 = score3 - 30;
			if (score3 <= 0)
				over3.gameover();
			setColor(10);
			gotoxy(56, 5); printf("%d", score3); printf("               ");
		}    i++;
	}
}

void Game::MovePos3() {
	setColor(10);
	gotoxy(56, 5); printf("%d", score3);
	int X = 3;
	int Y = 3;
	int site;
	int CountX = 0, CountY = 0;
	FlipCard flip;
	flip.flipCount = 0;
	gotoxy(X, Y);
	printf(" ^");
	while (1) {
		site = _getch();
		switch (site) {
		case 72://up입력
			if (Y > 3) {
				gotoxy(X, Y);
				printf("  ");
				Y -= 3;
				gotoxy(X, Y);
				printf(" ^");
				CountY--;
			}break;
		case 75://left
			if (X > 3) {
				gotoxy(X, Y);
				printf("  ");
				X -= 9;
				gotoxy(X, Y);
				printf(" ^");
				CountX--;
			}break;
		case 77://right
			if (X != 39) {
				gotoxy(X, Y);
				printf("  ");
				X += 9;
				gotoxy(X, Y);
				printf(" ^");
				CountX++;
			}break;
		case 80://down
			if (Y != 12) {
				gotoxy(X, Y);
				printf("  ");
				Y += 3;
				gotoxy(X, Y);
				printf(" ^");
				CountY++;
			}break;
		case 32: //space bar
			gotoxy(X, Y - 1);
			setColor(10);
			printf("[%d]", jungdap3[CountY][CountX]);
			flip.flipCount++; //스페이스 바 누를 때마다 카드 뒤집은 횟수 증가

			int n;
			n = flip.flipCount % 2; //n에 flipCount를 2로 나눈 나머지 값을 저장. 

			if (n == 0) {//나머지 값이 0일 때, 즉 스페이스 바가 2번 눌렸을때(카드가 2개 뒤집혔을때) 실행
				p = find(cardju3, cardju3 + 10, jungdap3[CountY][CountX]);
				if (p != cardju3 + 10) {	//cardju 배열에 정답카드가 들어간 경우=이미 맞춰진 숫자인 경우
					flip.flipCount--;
				}
				else {
				flip.posx[1] = X;
				flip.posy[1] = Y - 1;
				flip.px[1] = CountX;
				flip.py[1] = CountY;
				flip.Filpcard3();
				if (flip.matchedCardCount == 10) {
					system("cls");//화면 지우고
					gameclear(score3);//클리어 화면 출력
					Sleep(800);//잠시 기다렸다가
					compareScore(score3);
					system("cls");
					scoreBoard();
					Sleep(3000);
					restart();
				}
				}
			}else //스페이스바가 홀수번 눌렸을때
			{
				p = find(cardju3, cardju3 + 10, jungdap3[CountY][CountX]);
				if (p != cardju3 + 10) {	//cardju 배열에 정답카드가 들어간 경우=이미 맞춰진 숫자인 경우
					flip.flipCount--;
				}
				else {
					flip.posx[0] = X; //뒤집은 카드의 XY좌표를 flipPos에 각자 저장
					flip.posy[0] = Y - 1;
					flip.px[0] = CountX;
					flip.py[0] = CountY;
				}
			}break;
		case 27:
			stop();
			break;
		default:
			break;
		}
	}
}