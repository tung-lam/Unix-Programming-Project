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


}
