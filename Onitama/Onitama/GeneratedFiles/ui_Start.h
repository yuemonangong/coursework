/********************************************************************************
** Form generated from reading UI file 'Start.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_START_H
#define UI_START_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Start
{
public:
    QPushButton *pushButton;
    QPushButton *nouse;

    void setupUi(QWidget *Start)
    {
        if (Start->objectName().isEmpty())
            Start->setObjectName(QStringLiteral("Start"));
        Start->resize(800, 600);
        Start->setStyleSheet(QStringLiteral("border-image:url(:/Onitama/Resources/Start.jpg)"));
        pushButton = new QPushButton(Start);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(190, 120, 420, 360));
        pushButton->setStyleSheet(QLatin1String("border-image: url(:/Onitama/Resources/StartIcon.jpg);\n"
""));
        nouse = new QPushButton(Start);
        nouse->setObjectName(QStringLiteral("nouse"));
        nouse->setGeometry(QRect(0, 0, 800, 600));
        nouse->raise();
        pushButton->raise();

        retranslateUi(Start);

        QMetaObject::connectSlotsByName(Start);
    } // setupUi

    void retranslateUi(QWidget *Start)
    {
        Start->setWindowTitle(QApplication::translate("Start", "Start", Q_NULLPTR));
        pushButton->setText(QString());
        nouse->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Start: public Ui_Start {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_START_H
