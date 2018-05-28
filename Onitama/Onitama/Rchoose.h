#ifndef TWO_H  
#define TWO_H  

#include <QWidget>  

namespace Ui {
	class Rchoose;
}

class Rchoose : public QWidget
{
	Q_OBJECT

public:
	explicit Rchoose(QWidget *parent = 0);
	~Rchoose();

signals:
	void display(int number);


	private slots:
	void on_pushButton_1_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();

private:
	Ui::Rchoose *ui;
};

#endif // TWO_H  