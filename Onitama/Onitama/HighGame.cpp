#include "HighGame.h"  
#include "ui_HighGame.h"  


HighGame::HighGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::HighGame)
{
	ui->setupUi(this);
}

HighGame::~HighGame()
{
	delete ui;
}

void HighGame::on_pushButton_to_start_clicked()
{
	emit display(0);
}