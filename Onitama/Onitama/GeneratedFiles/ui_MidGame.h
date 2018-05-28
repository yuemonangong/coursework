/********************************************************************************
** Form generated from reading UI file 'MidGame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MIDGAME_H
#define UI_MIDGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MidGame
{
public:
    QPushButton *pushButton_to_start;
    QPushButton *quit;

    void setupUi(QWidget *MidGame)
    {
        if (MidGame->objectName().isEmpty())
            MidGame->setObjectName(QStringLiteral("MidGame"));
        MidGame->resize(800, 601);
        pushButton_to_start = new QPushButton(MidGame);
        pushButton_to_start->setObjectName(QStringLiteral("pushButton_to_start"));
        pushButton_to_start->setGeometry(QRect(270, 220, 181, 111));
        quit = new QPushButton(MidGame);
        quit->setObjectName(QStringLiteral("quit"));
        quit->setGeometry(QRect(0, 0, 75, 23));

        retranslateUi(MidGame);
        QObject::connect(quit, SIGNAL(clicked()), MidGame, SLOT(close()));

        QMetaObject::connectSlotsByName(MidGame);
    } // setupUi

    void retranslateUi(QWidget *MidGame)
    {
        MidGame->setWindowTitle(QApplication::translate("MidGame", "MidGame", Q_NULLPTR));
        pushButton_to_start->setText(QApplication::translate("MidGame", "return to start", Q_NULLPTR));
        quit->setText(QApplication::translate("MidGame", "quit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MidGame: public Ui_MidGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MIDGAME_H
