#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
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
    QString directory = ui->folderPathInput->text();

    QProcess process1;
    process1.start("./Part1.1", QStringList() << directory);
    process1.waitForFinished(-1);

    ui->mainOutput->setText(process1.readAllStandardOutput());
}

void MainWindow::on_sortByNameButton_clicked()
{
    QString directory = ui->folderPathInput->text();

    QProcess process2;
    process2.start("./SortByName", QStringList() << directory);
    process2.waitForFinished(-1);

    ui->mainOutput->setText(process2.readAllStandardOutput());
}

void MainWindow::on_searchButton_clicked()
{
    QString directory = ui->folderPathInput->text();
    QString keyword = ui->keywordInput->text();

    QProcess process5;
    process5.start("./SearchKeyword", QStringList() << directory << keyword);
    process5.waitForFinished(-1);

    ui->mainOutput->setText(process5.readAllStandardOutput());
}

void MainWindow::on_sortBySizeButton_clicked()
{
    QString directory = ui->folderPathInput->text();

    QProcess process2;
    process2.start("./SortBySize", QStringList() << directory);
    process2.waitForFinished(-1);

    ui->mainOutput->setText(process2.readAllStandardOutput());
}

void MainWindow::on_sortByDateButton_clicked()
{
    QString directory = ui->folderPathInput->text();

    QProcess process2;
    process2.start("./SortByDate", QStringList() << directory);
    process2.waitForFinished(-1);

    ui->mainOutput->setText(process2.readAllStandardOutput());
}

void MainWindow::on_duplicateButton_clicked()
{
    QString directory = ui->folderPathInput->text();

    QProcess process3;
    process3.start("./SameName", QStringList() << directory);
    process3.waitForFinished(-1);

    ui->mainOutput->setText(process3.readAllStandardOutput());
}

void MainWindow::on_viewButton_clicked()
{
    QString directory = ui->folderPathInput->text();
    QString name = "ACA1.png"; // any image in directory, for testing

    QProcess process4;
    process4.start("./View", QStringList() << directory << name);
    process4.waitForFinished(-1);

    ui->mainOutput->setText(process4.readAllStandardOutput());
}
