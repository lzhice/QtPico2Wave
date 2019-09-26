#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->startPos->setValue(1);
    ui->numLines->setValue(200);
    pausepic.load("./pause.png");
    playpic.load("./play.png");
    w = ui->label->width();
    h = ui->label->height();
    ui->playStop->setIcon(QIcon(playpic.scaled(w,h,Qt::KeepAspectRatio)));
    this->setWindowTitle("QtPico2Wave_v0.1");
    QFile file2("./.stations");
    if(!file2.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"Information",file2.errorString());
    }
    QTextStream in2(&file2);
    while(!in2.atEnd())
    {
       ui->comboBox->addItem(in2.readLine());
    }
    QMenu *file = ui->menuBar->addMenu("&File");

    //connect()
    exitme = new QAction(tr("&Exit"),this);
    file->addAction(exitme);
    connect(exitme,SIGNAL(triggered()), this, SLOT(close()));


    aboutme = new QAction(tr("&About"),this);
    file->addAction(aboutme);
    connect(aboutme,SIGNAL(triggered()), this, SLOT(about()));
    READING_NOW=false;
}

void MainWindow::about()
{
    QString abouttext = "<b>QtPico2Wave ver0.1<\b> \nRelease date: 2019, Author: B.Sudarsan \n QtPico2Wave comes with ABSOLUTELY NO WARRANTY.";
    QString abouttext2 = "\nThis is free software, and you are welcome to redistribute it under certain conditions.\nLook up gnu gpl v2, and/or google murray bookchin :)";
    QMessageBox::about(this,"About",abouttext+abouttext2);
}

MainWindow::~MainWindow()
{

    sh.kill();
    QProcess sh2;
    sh2.execute("killall -9 aplay");
    sh2.close();
    sh2.startDetached("rm /tmp/test.wav");
    sh2.close();
    qDebug()<<"\nBye!";
    delete ui;
}

void MainWindow::on_openFile_clicked()
{

     QFileDialog dialog(this);
     dialog.setNameFilter(tr("Text Files(*.txt *.dat)"));
     dialog.setViewMode(QFileDialog::Detail);
     fileName = QFileDialog::getOpenFileName(this,tr("Open Text File"), "~/", tr("Text Files(*.txt *.dat)"));
     if (!fileName.isEmpty())
     {
         QFile file1(fileName);
         if(!file1.open(QIODevice::ReadOnly))
         {
             QMessageBox::information(0,"Information",file1.errorString());
         }
         QTextStream in(&file1);
         ui->textEdit->setText(in.readAll());
         ui->statusBar->setStatusTip("File:"+fileName);
     }
}


void MainWindow::on_playStop_clicked()
{
    if(READING_NOW)
    {
     QProcess sh2;
     sh2.execute("killall -9 aplay");
     sh2.close();
     sh2.execute("rm /tmp/test.wav");
     sh2.close();
     READING_NOW=false;
     ui->startPos->setDisabled(false);
     ui->numLines->setDisabled(false);
     ui->textEdit->setTextInteractionFlags(flags1);
     ui->playStop->setIcon(QIcon(playpic.scaled(w,h,Qt::KeepAspectRatio)));
    }
    else
  {
    bool ok=true;
    //int line_number = QInputDialog::getInt(this, tr("Go to Line"), tr("Enter a line number to go to: "), 1, 1, ui->textEdit->document()->blockCount(), 1, &ok);
    int line_number = ui->startPos->value();
    int number_of_lines = ui->numLines->value();
    if (ok)
    {

       QTextCursor text_cursor(ui->textEdit->document()->findBlockByNumber(line_number - 1));
       ui->textEdit->setTextCursor(text_cursor);
       auto vsb = ui->textEdit->verticalScrollBar()->value();
       text_cursor.movePosition(QTextCursor::Down,QTextCursor::KeepAnchor,number_of_lines);
       ui->textEdit->setTextCursor(text_cursor);
       ui->textEdit->verticalScrollBar()->setValue(vsb);
       flags1 = ui->textEdit->textInteractionFlags();
       ui->textEdit->setTextInteractionFlags(Qt::NoTextInteraction);
    }
   if(!fileName.isEmpty())
   {
    ui->playStop->setIcon(QIcon(pausepic.scaled(w,h,Qt::KeepAspectRatio)));
    QString program2 = "./tts.sh "+QString::number(line_number)+" "+QString::number(number_of_lines)+" "+fileName;
    sh.startDetached(program2);//,{QString::number(line_number),QString::number(number_of_lines),fileName},".",&pid2);
    READING_NOW=true;
    ui->startPos->setDisabled(true);
    ui->numLines->setDisabled(true);
    sh.close();

   }
  }
}

void MainWindow::on_textEdit_selectionChanged()
{

    QTextCursor cursor = ui->textEdit->textCursor();
    QTextCursor cursor2 = cursor;
    cursor2.setPosition(cursor.selectionStart());
    int linenum = cursor2.blockNumber();


    int selectedLines = 0;
    if(!cursor.selection().isEmpty())
    {
        QString str = cursor.selection().toPlainText();
        selectedLines = str.count("\n")+1;
    }
  if(!READING_NOW)
  {
  ui->startPos->setValue(linenum);
  ui->numLines->setValue(selectedLines);
  }
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    QProcess sh3;
    if(checked)
    {
        auto num = ui->comboBox->currentIndex();
        QString station = ui->comboBox->itemText(num);
        sh3.startDetached("mpv",{station},".",&pid3);
        //pid3 = sh3.processId();
        qDebug()<<pid3;
        sh3.close();
    }
    else
    {
        sh3.execute("kill "+QString::number(pid3));
        sh3.close();
    }
}
