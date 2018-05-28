#ifndef LOWGAME_H  
#define LOWGAME_H  

#include <QWidget>
#include <cstring>
#include <QPushButton>
#include "area.h"
#include "card.h"
#include "game.h"
using namespace std;


namespace Ui {
	class LowGame;
}

class LowGame : public QWidget
{
	Q_OBJECT

public:
	explicit LowGame(QWidget *parent = 0);
	~LowGame();

signals:
	void display(int number);

	private slots:
	void on_pushButton_to_start_clicked();
	void on_pushButton_1_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_7_clicked();
	void on_pushButton_8_clicked();
	void on_pushButton_9_clicked();
	void on_pushButton_10_clicked();
	void on_pushButton_11_clicked();
	void on_pushButton_12_clicked();
	void on_pushButton_13_clicked();
	void on_pushButton_14_clicked();
	void on_pushButton_15_clicked();
	void on_pushButton_16_clicked();
	void on_pushButton_17_clicked();
	void on_pushButton_18_clicked();
	void on_pushButton_19_clicked();
	void on_pushButton_20_clicked();
	void on_pushButton_21_clicked();
	void on_pushButton_22_clicked();
	void on_pushButton_23_clicked();
	void on_pushButton_24_clicked();
	void on_pushButton_25_clicked();
	void on_omiuji_1_clicked();
	void on_omiuji_2_clicked();
	void on_ghost_1_1_clicked();
	void on_ghost_1_2_clicked();
	void on_ghost_1_3_clicked();
	void on_ghost_1_4_clicked();
	void on_ghost_2_1_clicked();
	void on_ghost_2_2_clicked();
	void on_ghost_2_3_clicked();
	void on_ghost_2_4_clicked();
	void on_card_1_clicked();
	void on_card_2_clicked();
	void on_card_3_clicked();
	void on_card_4_clicked();
	void on_pushButton_skip_clicked();


private:
	Ui::LowGame *ui;
	string choosed_card;
	string backup_card;
	QPushButton *choosed_btn;
	QPushButton *moving_btn;
	//string cards[15] = {"dog","boar","dragon","frog","horse","monkey","mouse","ostrich","ox","rabbit","rooster","sheep","snake","tiger","turtle"};
	int chess_pos[2];
	int destination[2];
	void cardset(string card, QPushButton *btn);
	void cardarrange(); //同步area
	void dropchess(int x, int y);
	QPushButton* findpos(int pos);
	bool flag;
	game lgame;
	int *A;
	int *B;
	int lock; //0:只能点击卡片 1：只能点击棋子 2：只能点击棋格
};

#endif // THREE_H 