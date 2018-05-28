#include "Start.h"  
#include "ui_Start.h"  


Start::Start(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Start)
{
	ui->setupUi(this);

}

Start::~Start()
{
	delete ui;
}

void Start::on_pushButton_clicked()
{
	emit display(1);
}