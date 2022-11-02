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

void printCard(int x, int y) {	//���� ���
	gotoxy(x, y);   printf("  ���      ���    ����    ����  ");
	gotoxy(x, y+1); printf("��    ��  ��    ��  ��    ��  ��    ��");
	gotoxy(x, y+2); printf("��        ��    ��  ��    ��  ��    ��");
	gotoxy(x, y+3); printf("��        �����  ����    ��    ��");
	gotoxy(x, y+4); printf("��    ��  ��    ��  ��    ��  ��    ��");
	gotoxy(x, y+5); printf("  ���    ��    ��  ��    ��  ����  ");
}

void printMatching(int x, int y) {
	gotoxy(x, y);     printf("��      ��    �â�   �ââââ�    �â�    ��    ��  �ââ�  ��    ��    �â�  ");
	gotoxy(x, y + 1); printf("�â�  �â�  ��    ��     ��      ��    ��  ��    ��    ��    ��    ��  ��    ��");
	gotoxy(x, y + 2); printf("��  ��  ��  ��    ��     ��      ��        �âââ�    ��    �â�  ��  ��      ");
	gotoxy(x, y + 3); printf("��      ��  �âââ�     ��      ��        ��    ��    ��    ��  �â�  ��  �â�");
	gotoxy(x, y + 4); printf("��      ��  ��    ��     ��      ��    ��  ��    ��    ��    ��    ��  ��    ��");
	gotoxy(x, y + 5); printf("��      ��  ��    ��     ��        �â�    ��    ��  �ââ�  ��    ��    �â�  ");
}


//����ȭ�� ���
int Screen::MainMenu() {
	cout << "\n\n\n\n";
	setColor(12);	//���������� ���ڻ� ��ȯ
	printCard(15, 6);
	setColor(11);	//�Ķ������� ���ڻ� ��ȯ
	printMatching(37, 14);
	cout << "\n";

	setColor(7);	//���������� ���ڻ� �ٽ� ��ȯ
	if (sel == 1) {	//���ӽ��� ����
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t  " << "> Game Start\n";
		cout << "\n\n\t\t\t\t\t\t\t  " << "Exit\n";
	}
	else if (sel == 2) {	//�������� ����
		cout << "\n\n\n\n\n\t\t\t\t\t\t\t  " << "Game Start\n";
		cout << "\n\n\t\t\t\t\t\t\t  " << "> Exit\n";
	}
	

	if (enter == 1) {	//������ �޴��� ����
		system("cls");
		return sel;
	}
	else {
		SelectMenu();	//���Ʒ��� �����̸鼭 �޴��� ����
		system("cls");
		return 0;
	}
}

	//Ű���带 �̿��� �޴� ����
	void Screen::SelectMenu() {
		char c;

		c = _getch(); //Ű���� �Է� �޾Ƽ� �ش� ��ġ�� �̵� ������
		if (c == 80) {	//Ű���� downŰ �Է°��� 80
			if (sel < 3)
				sel += 1;
		}
		else if (c == 72) {	//Ű���� upŰ �Է°��� 72
			if (sel > 1)
				sel -= 1;
		}
		if (c == 13) {		//Ű���� enterŰ �Է°��� 13
			enter = 1;
		}
	}

	/*����Ű �Է°� ����
	<- ��������Ű(75)  ->��������Ű(77)  �� ����Ű(72) �Ʒ�����Ű (80) 
	enterŰ(13)
	*/
