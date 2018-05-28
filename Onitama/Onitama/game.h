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
	bool currentplayer; //当前操作人，true为玩家1，false为玩家2
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
	int lowNormalActionII(int sx, int sy, int dx, int dy, int *A, int *B);		//0为不合法，1为合法，2为合法且分出胜负。
	bool midJumpAction(const card &c);
	bool midNormalActionI(const card &c, int x, int y, int *A, int *B);
	int midNormalActionII(const card &c, int sx, int sy, int dx, int dy, int *A, int *B);
	bool lowAction(int player);	//返回0，无人胜出，返回1，当前玩家胜出；
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
	bool moveChessCheckWin(int sx, int sy, int dx, int dy, int player); //移动棋子并检测胜负，true为当前角色胜利，false为未胜利
	card chooseCard(int index) const;		//index是area的编号，从该area中选择card;
	pair<int, int> choosePos() const;
	int chooseDeck(int index) const;		//index为0代表从选牌区域选择deck，1代表从弃牌区域。
	bool jumpAction() const;
	void printMatrix() const;
	void printDeck() const;
	bool posContained(int x, int y, int * A, int * B) const;
	void highlight(int x, int y, int *A, int *B) const; //高亮已选棋子与可选移动位置。
};

