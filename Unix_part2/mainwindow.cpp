#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QProcess mainProcess;
    mainProcess.start("./server");
    mainProcess.waitForFinished(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectButton_clicked()
{
   QString userName = ui->userNameEdit->text();
   QString portNumber = ui->portNumberEdit->text();

   QProcess process;

   process.start("./client -s 127.0.0.1:5000 -p " + portNumber + " -n " + userName);
//   ./client1 -s 127.0.0.1:5000 -p 1234 -n lam
   process.waitForFinished(-1);

//   ui->mainOutput->setText(process.readAllStandardOutput());
}
