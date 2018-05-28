#include "Rchoose.h"
#include "ui_Rchoose.h"  

Rchoose::Rchoose(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Rchoose)
{
	ui->setupUi(this);
}

Rchoose::~Rchoose()
{
	delete ui;
}

void Rchoose::on_pushButton_1_clicked()
{
	emit display(2);
}

void Rchoose::on_pushButton_2_clicked()
{
	emit display(3);
}

void Rchoose::on_pushButton_3_clicked()
{
	emit display(4);
}