/********************************************************************************
** Form generated from reading UI file 'Onitama.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONITAMA_H
#define UI_ONITAMA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OnitamaClass
{
public:

    void setupUi(QWidget *OnitamaClass)
    {
        if (OnitamaClass->objectName().isEmpty())
            OnitamaClass->setObjectName(QStringLiteral("OnitamaClass"));
        OnitamaClass->resize(801, 600);

        retranslateUi(OnitamaClass);

        QMetaObject::connectSlotsByName(OnitamaClass);
    } // setupUi

    void retranslateUi(QWidget *OnitamaClass)
    {
        OnitamaClass->setWindowTitle(QApplication::translate("OnitamaClass", "Onitama", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OnitamaClass: public Ui_OnitamaClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONITAMA_H
