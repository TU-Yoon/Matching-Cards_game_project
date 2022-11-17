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

Score scores[6];	//���� ��ü�迭 ����

void compareScore(int score) {	//�̸� �Է� �� ���� �� ����
	string name;	//�̸� ���ڿ�
	setColor(11);	//�Ķ������� gameclear�� ����
	gotoxy(25, 3);
	cout << "==========================================";
	gotoxy(25, 4);
	cout << "=========== G A M E C L E A R ============";
	gotoxy(25, 7);
	cout << "==========================================";
	gotoxy(39, 5);
	cout << "�̸� : ";
	getline(cin, name);	//�̸� �Է�
	setColor(7);	//�ٽ� ����������

	scores[5].score = score;	//��ü�� ������ score ����� ���� ���ھ� �� ����
	scores[5].name = name;		//��ü�� ������ name ����� �̸� �� ����
	Score tmp;	//���� �ӽ÷� �־�� tmp ��ü ����

	for (int i = 5; i > 0 ; i--) {	//5 -> 1�� ��ü�� score������� �ϳ��� ���ϴ� ����
		if (scores[i].score == scores[i - 1].score) break;
		else if (scores[i].score > scores[i - 1].score) {
			tmp = scores[i - 1];
			scores[i - 1] = scores[i];
			scores[i] = tmp;
		}
		else break;
	}
}

void scoreBoard() {	//������ ���
	gotoxy(28, 3); cout << "�������ְ�  ����������";
	gotoxy(28, 4); cout << "�� 1��.       " << setfill('0') << setw(4) << scores[0].score << "       " << setfill('X') << setw(3) << scores[0].name << "��";
	gotoxy(28, 5); cout << "�� 2��.       " << setfill('0') << setw(4) << scores[1].score << "       " << setfill('X') << setw(3) << scores[1].name << "��";
	gotoxy(28, 6); cout << "�� 3��.       " << setfill('0') << setw(4) << scores[2].score << "       " << setfill('X') << setw(3) << scores[2].name << "��";
	gotoxy(28, 7); cout << "�� 4��.       " << setfill('0') << setw(4) << scores[3].score << "       " << setfill('X') << setw(3) << scores[3].name << "��";
	gotoxy(28, 8); cout << "�� 5��.       " << setfill('0') << setw(4) << scores[4].score << "       " << setfill('X') << setw(3) << scores[4].name << "��";
	gotoxy(28, 9); cout << "����������������";
}