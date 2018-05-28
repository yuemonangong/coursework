#include "MidGame.h"  
#include "ui_MidGame.h"  


MidGame::MidGame(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::MidGame)
{
	ui->setupUi(this);
}

MidGame::~MidGame()
{
	delete ui;
}

void MidGame::on_pushButton_to_start_clicked()
{
	emit display(0);
}