//https://blockdmask.tistory.com/400 (c++ ¦���߱� ����)
//https://velog.io/@pwy9679/CPPTetris2 (c++ ��Ʈ���� ����)���� ����, ���۹� �����Ͽ����ϴ�.

#include <iostream>
#include <conio.h>
#include <windows.h>
#include "system.h"
#include "screen.h"
#include "game.h"

int main() {
	int sel = 0;
	CursorView(false);	//Ŀ�� �� ���̰� �ϱ�
	system("mode con cols=130 lines=40 | title Card Matching Game(��������)");	//�ܼ� â ũ��� ����
	Screen screen;	//����ȭ�� ����
	Game game;	//���� ��ü ����

	while (sel != 1) {
		sel = screen.MainMenu();
		if (sel == 2) {
			exit(0); //���� ���� ��ư ������ ���� ����
		}
	}
	while (sel == 1) {
		system("mode con cols=90 lines=20 | title Card Matching Game(��������)");	//�ܼ� â ũ��� ����
		game.Init1();
		game.printQuestion1(); //����ǥ ��
		game.prinextra(40, 0);//ī��Ʈ, �������� ǥ��
		game.MovePos();//����Ű�� Ŀ�� �̵�
	}
}


