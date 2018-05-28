/********************************************************************************
** Form generated from reading UI file 'HighGame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HIGHGAME_H
#define UI_HIGHGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HighGame
{
public:
    QPushButton *pushButton_to_start;

    void setupUi(QWidget *HighGame)
    {
        if (HighGame->objectName().isEmpty())
            HighGame->setObjectName(QStringLiteral("HighGame"));
        HighGame->resize(800, 600);
        pushButton_to_start = new QPushButton(HighGame);
        pushButton_to_start->setObjectName(QStringLiteral("pushButton_to_start"));
        pushButton_to_start->setGeometry(QRect(150, 200, 75, 23));

        retranslateUi(HighGame);

        QMetaObject::connectSlotsByName(HighGame);
    } // setupUi

    void retranslateUi(QWidget *HighGame)
    {
        HighGame->setWindowTitle(QApplication::translate("HighGame", "HighGame", Q_NULLPTR));
        pushButton_to_start->setText(QApplication::translate("HighGame", "return to start", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HighGame: public Ui_HighGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HIGHGAME_H
