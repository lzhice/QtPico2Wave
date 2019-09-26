#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QInputDialog>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextBlock>
#include <QString>
#include <iostream>
#include <QStringList>
#include <QDebug>
#include <QLabel>
#include <QTextDocumentFragment>
#include <QScrollBar>
#include <QAction>
#include <QMenu>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openFile_clicked();

    void on_playStop_clicked();


    void on_textEdit_selectionChanged();

    void on_checkBox_toggled(bool checked);
    void about();

private:
    Ui::MainWindow *ui;
    QString fileName;
    QProcess sh;
    QPixmap *mypix;
    QPixmap pausepic;
    QPixmap playpic;
    Qt::TextInteractionFlags flags1;
    QAction *exitme;
    QAction *aboutme;
    int w;
    int h;
    qint64 pid3,pid2,pid1;
    bool READING_NOW;
};

#endif // MAINWINDOW_H
