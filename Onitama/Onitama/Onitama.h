#ifndef ONITAMA_H  
#define ONITAMA_H  
#include <QtWidgets/QMainWindow>

class Start;
class Rchoose;
class LowGame;
class MidGame;
class HighGame;
class QStackedLayout;
class QVBoxLayout;

class Onitama : public QWidget
{
	Q_OBJECT

public:
	explicit Onitama(QWidget *parent = Q_NULLPTR);

private:
	Start *start;
	Rchoose *rchoose;
	LowGame *lowgame;
	MidGame *midgame;
	HighGame *highgame;
	QStackedLayout *stackLayout;
	QVBoxLayout *mainLayout;
};

#endif // ONITAMA_H  