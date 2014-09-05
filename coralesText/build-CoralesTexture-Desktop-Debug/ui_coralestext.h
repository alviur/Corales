/********************************************************************************
** Form generated from reading UI file 'coralestext.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORALESTEXT_H
#define UI_CORALESTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoralesText
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CoralesText)
    {
        if (CoralesText->objectName().isEmpty())
            CoralesText->setObjectName(QStringLiteral("CoralesText"));
        CoralesText->resize(625, 517);
        centralWidget = new QWidget(CoralesText);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(260, 330, 85, 27));
        CoralesText->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CoralesText);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 625, 22));
        CoralesText->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CoralesText);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CoralesText->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CoralesText);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CoralesText->setStatusBar(statusBar);

        retranslateUi(CoralesText);

        QMetaObject::connectSlotsByName(CoralesText);
    } // setupUi

    void retranslateUi(QMainWindow *CoralesText)
    {
        CoralesText->setWindowTitle(QApplication::translate("CoralesText", "CoralesText", 0));
        pushButton->setText(QApplication::translate("CoralesText", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class CoralesText: public Ui_CoralesText {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORALESTEXT_H
