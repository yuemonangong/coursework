#pragma once

#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
#include<utility>
#include "card.h"
#include "area.h"
#include "seqList.h"
using namespace std;

class game
{
private:
	int **gameMatrix;
	area **areas;
	int areaSize;
	bool currentplayer; //��ǰ�����ˣ�trueΪ���1��falseΪ���2
public:
	game();
	~game();
	void display() const;
	string getCurrentPlayer() const;
	area *visitArea(int i) const { return areas[i]; }
	void lowPreparation();
	void highPreparation();
	bool lowJumpAction(const card &c);
	bool lowNormalActionI(const card &c, int x, int y, int *A, int *B);
	int lowNormalActionII(int sx, int sy, int dx, int dy, int *A, int *B);		//0Ϊ���Ϸ���1Ϊ�Ϸ���2Ϊ�Ϸ��ҷֳ�ʤ����
	bool midJumpAction(const card &c);
	bool midNormalActionI(const card &c, int x, int y, int *A, int *B);
	int midNormalActionII(const card &c, int sx, int sy, int dx, int dy, int *A, int *B);
	bool lowAction(int player);	//����0������ʤ��������1����ǰ���ʤ����
	bool midAction(int player);
	bool highAction(int player);
	void lowPlay();
	void midPlay();
	void highPlay();
private:
	void getAccessPlaces(int x, int y, int player, card c, int *A, int *B) const;
	void dognextstep(int x, int y, int player, int* A, int* B)const;               //1
	void monkeynextstep(int x, int y, int player, int* A, int* B)const;                 //2
	void tigernextstep(int x, int y, int player, int* A, int* B)const;                 //3
	void roosternextstep(int x, int y, int player, int* A, int* B)const;           //4
	void dragonnextstep(int x, int y, int player, int* A, int* B)const;              //5
	void horsenextstep(int x, int y, int player, int* A, int* B)const;               //6
	void oxnextstep(int x, int y, int player, int* A, int* B)const;                  //7
	void snakenextstep(int x, int y, int player, int* A, int* B)const;               //8
	void mousenextstep(int x, int y, int player, int* A, int* B)const;               //9
	void rabbitnextstep(int x, int y, int player, int* A, int* B)const;              //10
	void sheepnextstep(int x, int y, int player, int* A, int* B)const;              //11
	void boarnextstep(int x, int y, int player, int* A, int* B)const;                //12
	void turtlenextstep(int x, int y, int player, int* A, int* B)const;                 //13
	void ostrichnextstep(int x, int y, int player, int* A, int* B)const;                 //14
	void frognextstep(int x, int y, int player, int* A, int* B)const;                 //15
	bool moveChessCheckWin(int sx, int sy, int dx, int dy, int player); //�ƶ����Ӳ����ʤ����trueΪ��ǰ��ɫʤ����falseΪδʤ��
	card chooseCard(int index) const;		//index��area�ı�ţ��Ӹ�area��ѡ��card;
	pair<int, int> choosePos() const;
	int chooseDeck(int index) const;		//indexΪ0�����ѡ������ѡ��deck��1�������������
	bool jumpAction() const;
	void printMatrix() const;
	void printDeck() const;
	bool posContained(int x, int y, int * A, int * B) const;
	void highlight(int x, int y, int *A, int *B) const; //������ѡ�������ѡ�ƶ�λ�á�
};

