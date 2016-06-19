#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QThread>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->folderPathInput->setPlaceholderText("Enter folder to manage images");
    ui->keywordInput->setPlaceholderText("Enter keyword for searching");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseFolder_clicked()
{
    // Browse for folder
    QString directory = QFileDialog::getExistingDirectory(this, tr("Select Folder"));

    // display the directory on the QlineEdit
    ui->folderPathInput->setText(directory);
}

void MainWindow::on_listingButton_clicked()
{
    QString directory = ui->folderPathInput->displayText();
    QProcess process1;
    process1.start("ls", QStringList() << directory);
    process1.waitForFinished(-1);

    ui->mainOutput->setText(process1.readAllStandardOutput());
}
