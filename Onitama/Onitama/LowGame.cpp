#include "LowGame.h"  
#include "ui_LowGame.h" 


string cards[15] = { "Dog", "Turtle", "Monkey", "Tiger", "Rooster", "Dragon", "Horse", "Ox", "Snake", "Mouse", "Rabbit", "Ostrich", "Frog", "Sheep", "Boar" };

LowGame::LowGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::LowGame)
{
	ui->setupUi(this);
	lgame.lowPreparation();
	cardarrange();
	backup_card = ui->card_5->whatsThis().toStdString();
	flag = false;
	A = new int[5];
	B = new int[5];
	lock = 0;
	if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
	else ui->label->setText({ "player2 playing..." });
}

LowGame::~LowGame()
{
	delete ui;
}

void LowGame::on_pushButton_to_start_clicked()
{
	emit display(0);
}

void LowGame::cardarrange()
{
	string cardname;
	cardname= lgame.visitArea(1)->visitCardName(0);
	cardset(cardname, ui->card_1);
	cardname = lgame.visitArea(1)->visitCardName(1);
	cardset(cardname, ui->card_2);
	cardname = lgame.visitArea(2)->visitCardName(0);
	cardset(cardname, ui->card_3);
	cardname = lgame.visitArea(2)->visitCardName(1);
	cardset(cardname, ui->card_4);
	cardname = lgame.visitArea(3)->visitCardName(0);
	cardset(cardname, ui->card_5);
}

void LowGame::cardset(string card, QPushButton *btn)
{
	int n;
	for (int i = 0; i < 15; i++) {
		if (card == cards[i]) { n = i; break; }
	}
	switch (n)
	{
	case 0:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Dog1.jpg)" });
		btn->setWhatsThis({ "Dog" });
		break;
	case 14:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Boar1.jpg)" });
		btn->setWhatsThis({ "Boar" });
		break;
	case 5:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Dragon1.jpg)" });
		btn->setWhatsThis({ "Dragon" });
		break;
	case 12:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Frog1.jpg)" });
		btn->setWhatsThis({ "Frog" });
		break;
	case 6:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Horse1.jpg)" });
		btn->setWhatsThis({ "Horse" });
		break;
	case 2:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Monkey1.jpg)" });
		btn->setWhatsThis({ "Monkey" });
		break;
	case 9:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Mouse1.jpg)" });
		btn->setWhatsThis({ "Mouse" });
		break;
	case 11:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Ostrich1.jpg)" });
		btn->setWhatsThis({ "Ostrich" });
		break;
	case 7:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Ox1.jpg)" });
		btn->setWhatsThis({ "Ox" });
		break;
	case 10:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Rabbit1.jpg)" });
		btn->setWhatsThis({ "Rabbit" });
		break;
	case 4:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Rooster1.jpg)" });
		btn->setWhatsThis({ "Rooster" });
		break;
	case 13:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Sheep1.jpg)" });
		btn->setWhatsThis({ "Sheep" });
		break;
	case 8:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Snake1.jpg)" });
		btn->setWhatsThis({ "Snake" });
		break;
	case 3:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Tiger1.jpg)" });
		btn->setWhatsThis({ "Tiger" });
		break;
	case 1:
		btn->setStyleSheet({ "border-image:url(:/Onitama/Resources/Turtle1.jpg)" });
		btn->setWhatsThis({ "Turtle" });
		break;
	default:
		break;
	}
}

QPushButton* LowGame::findpos(int pos)
{
	switch (pos)
	{
	case 1:return ui->pushButton_1;
	case 2:return ui->pushButton_2;
	case 3:return ui->pushButton_3;
	case 4:return ui->pushButton_4;
	case 5:return ui->pushButton_5;
	case 6:return ui->pushButton_6;
	case 7:return ui->pushButton_7;
	case 8:return ui->pushButton_8;
	case 9:return ui->pushButton_9;
	case 10:return ui->pushButton_10;
	case 11:return ui->pushButton_11;
	case 12:return ui->pushButton_12;
	case 13:return ui->pushButton_13;
	case 14:return ui->pushButton_14;
	case 15:return ui->pushButton_15;
	case 16:return ui->pushButton_16;
	case 17:return ui->pushButton_17;
	case 18:return ui->pushButton_18;
	case 19:return ui->pushButton_19;
	case 20:return ui->pushButton_20;
	case 21:return ui->pushButton_21;
	case 22:return ui->pushButton_22;
	case 23:return ui->pushButton_23;
	case 24:return ui->pushButton_24;
	case 25:return ui->pushButton_25;
	default:
		break;
	}
}

void LowGame::dropchess(int x, int y)
{
	if (ui->omiuji_1->geometry().x() == x && ui->omiuji_1->geometry().y() == y) 
		ui->omiuji_1->setGeometry(-25, -25, 0, 0);
	if (ui->omiuji_2->geometry().x() == x && ui->omiuji_2->geometry().y() == y)
		ui->omiuji_2->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_1_1->geometry().x() == x && ui->ghost_1_1->geometry().y() == y)
		ui->ghost_1_1->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_1_2->geometry().x() == x && ui->ghost_1_2->geometry().y() == y)
		ui->ghost_1_2->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_1_3->geometry().x() == x && ui->ghost_1_3->geometry().y() == y)
		ui->ghost_1_3->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_1_4->geometry().x() == x && ui->ghost_1_4->geometry().y() == y)
		ui->ghost_1_4->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_2_1->geometry().x() == x && ui->ghost_2_1->geometry().y() == y)
		ui->ghost_2_1->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_2_2->geometry().x() == x && ui->ghost_2_2->geometry().y() == y)
		ui->ghost_2_2->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_2_3->geometry().x() == x && ui->ghost_2_3->geometry().y() == y)
		ui->ghost_2_3->setGeometry(-25, -25, 0, 0);
	if (ui->ghost_2_4->geometry().x() == x && ui->ghost_2_4->geometry().y() == y)
		ui->ghost_2_4->setGeometry(-25, -25, 0, 0);
}

void LowGame::on_pushButton_1_clicked()
{
	if (lock != 2) return;
	destination[0] = 0;
	destination[1] = 0;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(25, 425);
	moving_btn->setGeometry(25, 425, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_2_clicked()
{
	if (lock != 2) return;
	destination[0] = 0;
	destination[1] = 1;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(25, 325);
	moving_btn->setGeometry(25, 325, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_3_clicked()
{
	if (lock != 2) return;
	destination[0] = 0;
	destination[1] = 2;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(25, 225);
	moving_btn->setGeometry(25, 225, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_4_clicked()
{
	if (lock != 2) return;
	destination[0] = 0;
	destination[1] = 3;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(25, 125);
	moving_btn->setGeometry(25, 125, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_5_clicked()
{
	if (lock != 2) return;
	destination[0] = 0;
	destination[1] = 4;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(25, 25);
	moving_btn->setGeometry(25, 25, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_6_clicked()
{
	if (lock != 2) return;
	destination[0] = 1;
	destination[1] = 0;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(125, 425);
	moving_btn->setGeometry(125, 425, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_7_clicked()
{
	if (lock != 2) return;
	destination[0] = 1;
	destination[1] = 1;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(125, 325);
	moving_btn->setGeometry(125, 325, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_8_clicked()
{
	if (lock != 2) return;
	destination[0] = 1;
	destination[1] = 2;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(125, 225);
	moving_btn->setGeometry(125, 225, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_9_clicked()
{
	if (lock != 2) return;
	destination[0] = 1;
	destination[1] = 3;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(125, 125);
	moving_btn->setGeometry(125, 125, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_10_clicked()
{
	if (lock != 2) return;
	destination[0] = 1;
	destination[1] = 4;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(125, 25);
	moving_btn->setGeometry(125, 25, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_11_clicked()
{
	if (lock != 2) return; 
	destination[0] = 2;
	destination[1] = 0;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(225, 425);
	moving_btn->setGeometry(225, 425, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_12_clicked()
{
	if (lock != 2) return;
	destination[0] = 2;
	destination[1] = 1;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(225, 325);
	moving_btn->setGeometry(225, 325, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_13_clicked()
{
	if (lock != 2) return;
	destination[0] = 2;
	destination[1] = 2;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(225, 225);
	moving_btn->setGeometry(225, 225, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_14_clicked()
{
	if (lock != 2) return;
	destination[0] = 2;
	destination[1] = 3;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(225, 125);
	moving_btn->setGeometry(225, 125, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_15_clicked()
{
	if (lock != 2) return;
	destination[0] = 2;
	destination[1] = 4;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(225, 25);
	moving_btn->setGeometry(225, 25, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_16_clicked()
{
	if (lock != 2) return;
	destination[0] = 3;
	destination[1] = 0;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(325, 425);
	moving_btn->setGeometry(325, 425, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_17_clicked()
{
	if (lock != 2) return;
	destination[0] = 3;
	destination[1] = 1;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(325, 325);
	moving_btn->setGeometry(325, 325, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_18_clicked()
{
	if (lock != 2) return;
	destination[0] = 3;
	destination[1] = 2;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(325, 225);
	moving_btn->setGeometry(325, 225, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_19_clicked()
{
	if (lock != 2) return;
	destination[0] = 3;
	destination[1] = 3;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(325, 125);
	moving_btn->setGeometry(325, 125, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_20_clicked()
{
	if (lock != 2) return;
	destination[0] = 3;
	destination[1] = 4;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(325, 25);
	moving_btn->setGeometry(325, 25, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_21_clicked()
{
	if (lock != 2) return;
	destination[0] = 4;
	destination[1] = 0;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(425, 425);
	moving_btn->setGeometry(425, 425, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_22_clicked()
{
	if (lock != 2) return;
	destination[0] = 4;
	destination[1] = 1;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(425, 325);
	moving_btn->setGeometry(425, 325, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_23_clicked()
{
	if (lock != 2) return;
	destination[0] = 4;
	destination[1] = 2;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(425, 225);
	moving_btn->setGeometry(425, 225, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_24_clicked()
{
	if (lock != 2) return;
	destination[0] = 4;
	destination[1] = 3;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(425, 125);
	moving_btn->setGeometry(425, 125, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_pushButton_25_clicked()
{
	if (lock != 2) return;
	destination[0] = 4;
	destination[1] = 4;
	if (flag) return;
	int result = lgame.lowNormalActionII(chess_pos[0], chess_pos[1], destination[0], destination[1], A, B);
	if (result == 0) return;
	dropchess(425, 25);
	moving_btn->setGeometry(425, 25, 50, 50);
	int i = 0;
	while (A[i] != -1 && B[i] != -1) {
		int pos = A[i] * 5 + B[i] + 1;
		QPushButton *btn;
		btn = findpos(pos);
		btn->setStyleSheet({ "" });
		i++;
	}
	if (result == 1) {
		lock = 0;
		if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
		else ui->label->setText({ "player2 playing..." });
	}
	if (result == 2) {
		lock = 3;
		if (lgame.getCurrentPlayer() == "player2") ui->label->setText({ "player1 win!" });
		else ui->label->setText({ "player2 win!" });
	}
}

void LowGame::on_omiuji_1_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->omiuji_1->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->omiuji_1->geometry().y() - 25) / 100;
	moving_btn = ui->omiuji_1;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}

void LowGame::on_omiuji_2_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->omiuji_2->geometry().x() - 25) / 100;
	chess_pos[1] = 4 - (ui->omiuji_2->geometry().y() - 25) / 100;
	moving_btn = ui->omiuji_2;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_1_1_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_1_1->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_1_1->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_1_1;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_1_2_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_1_2->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_1_2->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_1_2;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_1_3_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_1_3->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_1_3->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_1_3;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_1_4_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_1_4->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_1_4->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_1_4;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_2_1_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_2_1->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_2_1->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_2_1;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_2_2_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_2_2->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_2_2->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_2_2;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_2_3_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_2_3->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_2_3->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_2_3;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}
void LowGame::on_ghost_2_4_clicked()
{
	if (lock != 1) return;
	chess_pos[0] = (ui->ghost_2_4->geometry().x() - 25) / 100;
	chess_pos[1] = 4-(ui->ghost_2_4->geometry().y() - 25) / 100;
	moving_btn = ui->ghost_2_4;
	if (flag) return;
	if (lgame.lowNormalActionI(choosed_card, chess_pos[0], chess_pos[1], A, B)) {
		int i = 0;
		while (A[i] != -1 && B[i] != -1) {
			int pos = A[i] * 5 + B[i] + 1;
			QPushButton *btn;
			btn = findpos(pos);
			btn->setStyleSheet({ "background-color:rgb(255, 255, 127)" });
			i++;
			lock = 2;
		}
	}
	else lock = 0;
}

void LowGame::on_card_1_clicked()
{
	if (lock != 0) return;
	choosed_card = ui->card_1->whatsThis().toStdString();
	choosed_btn = ui->card_1;
	if (flag) {
		if (lgame.lowJumpAction(choosed_card)) {
			cardset(choosed_card, ui->card_5);
			cardset(backup_card, choosed_btn);
			backup_card = choosed_card;
			flag = false;
			if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
			else ui->label->setText({ "player2 playing..." });
		}
	}
	else lock = 1;
}
void LowGame::on_card_2_clicked()
{
	if (lock != 0) return;
	choosed_card = ui->card_2->whatsThis().toStdString();
	choosed_btn = ui->card_2;
	if (flag) {
		if (lgame.lowJumpAction(choosed_card)) {
			cardset(choosed_card, ui->card_5);
			cardset(backup_card, choosed_btn);
			backup_card = choosed_card;
			flag = false;
			if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
			else ui->label->setText({ "player2 playing..." });
		}
	}
	else lock = 1;
}
void LowGame::on_card_3_clicked()
{
	if (lock != 0) return;
	choosed_card = ui->card_3->whatsThis().toStdString();
	choosed_btn = ui->card_3;
	if (flag) {
		if (lgame.lowJumpAction(choosed_card)) {
			cardset(choosed_card, ui->card_5);
			cardset(backup_card, choosed_btn);
			backup_card = choosed_card;
			flag = false;
			if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
			else ui->label->setText({ "player2 playing..." });
		}
	}
	else lock = 1;
}
void LowGame::on_card_4_clicked()
{
	if (lock != 0) return;
	choosed_card = ui->card_4->whatsThis().toStdString();
	choosed_btn = ui->card_4;
	if (flag) {
		if (lgame.lowJumpAction(choosed_card)) {
			cardset(choosed_card, ui->card_5);
			cardset(backup_card, choosed_btn);
			backup_card = choosed_card;
			flag = false;
			if (lgame.getCurrentPlayer() == "player1") ui->label->setText({ "player1 playing..." });
			else ui->label->setText({ "player2 playing..." });
		}
	}
	else lock = 1;
}
void LowGame::on_pushButton_skip_clicked()
{
	flag = true;
}