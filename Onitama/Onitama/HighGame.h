#ifndef HIGHGAME_H  
#define HIGHGAME_H  

#include <QWidget>  


namespace Ui {
	class HighGame;
}

class HighGame : public QWidget
{
	Q_OBJECT

public:
	explicit HighGame(QWidget *parent = 0);
	~HighGame();

signals:
	void display(int number);

	private slots:
	void on_pushButton_to_start_clicked();

private:
	Ui::HighGame *ui;
};

#endif // HIGHGAME_H
