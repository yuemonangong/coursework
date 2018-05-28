#ifndef MIDGAME_H  
#define MIDGAME_H  

#include <QWidget>  


namespace Ui {
	class MidGame;
}

class MidGame : public QWidget
{
	Q_OBJECT

public:
	explicit MidGame(QWidget *parent = 0);
	~MidGame();

signals:
	void display(int number);

	private slots:
	void on_pushButton_to_start_clicked();

private:
	Ui::MidGame *ui;
};

#endif // MIDGAME_H