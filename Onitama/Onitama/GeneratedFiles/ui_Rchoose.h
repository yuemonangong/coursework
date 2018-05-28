/********************************************************************************
** Form generated from reading UI file 'Rchoose.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RCHOOSE_H
#define UI_RCHOOSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rchoose
{
public:
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *nouse;

    void setupUi(QWidget *Rchoose)
    {
        if (Rchoose->objectName().isEmpty())
            Rchoose->setObjectName(QStringLiteral("Rchoose"));
        Rchoose->resize(800, 600);
        Rchoose->setStyleSheet(QStringLiteral("border-image: url(:/Onitama/Resources/Rchoose.jpg);"));
        pushButton_1 = new QPushButton(Rchoose);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(80, 280, 150, 46));
        pushButton_1->setStyleSheet(QStringLiteral("border-image: url(:/Onitama/Resources/LowIcon.jpg);"));
        pushButton_2 = new QPushButton(Rchoose);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 280, 150, 46));
        pushButton_2->setStyleSheet(QStringLiteral("border-image: url(:/Onitama/Resources/MidIcon.jpg);"));
        pushButton_3 = new QPushButton(Rchoose);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(540, 280, 150, 46));
        pushButton_3->setStyleSheet(QStringLiteral("border-image: url(:/Onitama/Resources/HighIcon.jpg);"));
        nouse = new QPushButton(Rchoose);
        nouse->setObjectName(QStringLiteral("nouse"));
        nouse->setGeometry(QRect(0, 0, 800, 600));
        nouse->raise();
        pushButton_1->raise();
        pushButton_2->raise();
        pushButton_3->raise();

        retranslateUi(Rchoose);

        QMetaObject::connectSlotsByName(Rchoose);
    } // setupUi

    void retranslateUi(QWidget *Rchoose)
    {
        Rchoose->setWindowTitle(QApplication::translate("Rchoose", "Rchoose", Q_NULLPTR));
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        nouse->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Rchoose: public Ui_Rchoose {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RCHOOSE_H
