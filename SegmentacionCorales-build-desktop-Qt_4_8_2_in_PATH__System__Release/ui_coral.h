/********************************************************************************
** Form generated from reading UI file 'coral.ui'
**
** Created: Tue Apr 8 20:52:17 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORAL_H
#define UI_CORAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Coral
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Coral)
    {
        if (Coral->objectName().isEmpty())
            Coral->setObjectName(QString::fromUtf8("Coral"));
        Coral->resize(1316, 841);
        centralWidget = new QWidget(Coral);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(90, 610, 121, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 611, 511));
        label->setFrameShape(QFrame::WinPanel);
        label->setScaledContents(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(700, 50, 591, 511));
        label_2->setFrameShape(QFrame::WinPanel);
        label_2->setScaledContents(true);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(90, 680, 121, 41));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(320, 10, 121, 21));
        label_3->setScaledContents(false);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(940, 20, 121, 21));
        label_4->setScaledContents(false);
        Coral->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Coral);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1316, 26));
        Coral->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Coral);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Coral->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Coral);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Coral->setStatusBar(statusBar);

        retranslateUi(Coral);

        QMetaObject::connectSlotsByName(Coral);
    } // setupUi

    void retranslateUi(QMainWindow *Coral)
    {
        Coral->setWindowTitle(QApplication::translate("Coral", "Coral", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Coral", "Carga Imagen", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        label_2->setText(QString());
        pushButton_2->setText(QApplication::translate("Coral", "Segmentar", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Coral", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Original</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Coral", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Resultado</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Coral: public Ui_Coral {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORAL_H
