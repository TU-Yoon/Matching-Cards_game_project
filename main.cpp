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
	Game game;	//���ӿ� �ʿ��� ��� ����
	
	while (sel != 1) {
		sel = screen.MainMenu();
		if (sel == 2) {
			exit(0); //���� ���� ��ư ������ ���� ����
		}
	}
	while (sel == 1) {
		game.gamescreen();	//���� ���� ��ư ������ ���� ȭ�� ǥ��
	}
	return 0;
}