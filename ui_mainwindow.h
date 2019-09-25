/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QPushButton *openFile;
    QPushButton *playStop;
    QTextEdit *textEdit;
    QSpinBox *startPos;
    QLabel *label;
    QSpinBox *numLines;
    QLabel *label_2;
    QLabel *label_3;
    QCheckBox *checkBox;
    QComboBox *comboBox;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(991, 663);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openFile = new QPushButton(centralWidget);
        openFile->setObjectName(QStringLiteral("openFile"));
        openFile->setGeometry(QRect(20, 5, 91, 31));
        playStop = new QPushButton(centralWidget);
        playStop->setObjectName(QStringLiteral("playStop"));
        playStop->setGeometry(QRect(110, 5, 31, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 961, 571));
        textEdit->setTextInteractionFlags(Qt::TextEditorInteraction);
        startPos = new QSpinBox(centralWidget);
        startPos->setObjectName(QStringLiteral("startPos"));
        startPos->setGeometry(QRect(230, 5, 81, 31));
        startPos->setMaximum(2000);
        startPos->setValue(1);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 0, 31, 31));
        numLines = new QSpinBox(centralWidget);
        numLines->setObjectName(QStringLiteral("numLines"));
        numLines->setGeometry(QRect(410, 5, 71, 31));
        numLines->setMaximum(2000);
        numLines->setValue(1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(150, 10, 81, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 10, 64, 15));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(870, 10, 94, 20));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(550, 5, 281, 31));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 991, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About..", 0));
        openFile->setText(QApplication::translate("MainWindow", "Open", 0));
        playStop->setText(QString());
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Start at line:", 0));
        label_3->setText(QApplication::translate("MainWindow", "# of lines:", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Jam!", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
