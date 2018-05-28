#include "Onitama.h"
#include "Start.h"
#include "Rchoose.h"
#include "LowGame.h"
#include "MidGame.h"
#include "HighGame.h"
#include <QStackedLayout>  
#include <QPushButton>  
#include <QVBoxLayout>  

Onitama::Onitama(QWidget *parent)
	: QWidget(parent)
{
	setFixedSize(800,600);
	start = new Start;
	rchoose = new Rchoose;
	lowgame = new LowGame;
	midgame = new MidGame;
	highgame = new HighGame;
	stackLayout = new QStackedLayout;
	stackLayout->addWidget(start);
	stackLayout->addWidget(rchoose);
	stackLayout->addWidget(lowgame);
	stackLayout->addWidget(midgame);
	stackLayout->addWidget(highgame);
	connect(start, &Start::display, stackLayout, &QStackedLayout::setCurrentIndex);         // 0  
	connect(rchoose, &Rchoose::display, stackLayout, &QStackedLayout::setCurrentIndex);       // 1 
	connect(lowgame, &LowGame::display, stackLayout, &QStackedLayout::setCurrentIndex);       // 2  
	connect(midgame, &MidGame::display, stackLayout, &QStackedLayout::setCurrentIndex);       // 3
	connect(highgame, &HighGame::display, stackLayout, &QStackedLayout::setCurrentIndex);       // 4

	mainLayout = new QVBoxLayout;
	mainLayout->addLayout(stackLayout);
	setLayout(mainLayout);
}
