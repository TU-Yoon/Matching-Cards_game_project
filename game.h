#pragma once
using namespace std;

class Game {
public:
	void gameclear(int j);
	void stop();
	void restart();
	void gameover();
	void MovePos(); //�������� 1������ Ŀ�� ����
	void MovePos2();
	void MovePos3();
	char questionMap1[3][4]; // ī�� ���� �Ȱ��� ����ǥ ���� ������ �迭�� ����
	char questionMap2[4][4]; 
	char questionMap3[5][4];
	
	void printQuestion1();//����ǥ �� ���
	void printQuestion2();
	void printQuestion3();
	void prinextra(int x, int y);//ī��Ʈ�� ���������� ǥ���ϴ� �Լ� , xy�� ����� ��ġ����

	void Init1();//����ǥ�� �ʱ�ȭ
	void Init2();
	void Init3();
};

class FlipCard {
public:
	int px[2];
	int py[2];
	int posx[2];
	int posy[2];
	int flipCount;//������ ī�� ����
	int matchedCardCount=0;
    void Filpcard(); //ī�� ���������� ���� ī��� ����, �ٸ��� �ٽ� ����ǥ�� �ٲ�
	void Filpcard2();
	void Filpcard3();
	int i = 1;
};


