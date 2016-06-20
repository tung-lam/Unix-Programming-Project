#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_browseFolder_clicked();

    void on_listingButton_clicked();

    void on_sortByNameButton_clicked();

    void on_searchButton_clicked();

    void on_sortBySizeButton_clicked();

    void on_sortByDateButton_clicked();

    void on_duplicateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
