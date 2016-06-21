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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *browseFolder;
    QLineEdit *folderPathInput;
    QTextEdit *mainOutput;
    QLineEdit *keywordInput;
    QPushButton *listingButton;
    QPushButton *searchButton;
    QPushButton *sortByNameButton;
    QPushButton *sortBySizeButton;
    QPushButton *sortByDateButton;
    QPushButton *duplicateButton;
    QPushButton *viewButton;
    QLineEdit *fileNameToView;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuImage;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(757, 491);
        MainWindow->setMaximumSize(QSize(757, 491));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        browseFolder = new QPushButton(centralWidget);
        browseFolder->setObjectName(QStringLiteral("browseFolder"));
        browseFolder->setGeometry(QRect(620, 0, 99, 27));
        folderPathInput = new QLineEdit(centralWidget);
        folderPathInput->setObjectName(QStringLiteral("folderPathInput"));
        folderPathInput->setGeometry(QRect(50, 0, 541, 27));
        mainOutput = new QTextEdit(centralWidget);
        mainOutput->setObjectName(QStringLiteral("mainOutput"));
        mainOutput->setGeometry(QRect(50, 160, 671, 271));
        keywordInput = new QLineEdit(centralWidget);
        keywordInput->setObjectName(QStringLiteral("keywordInput"));
        keywordInput->setGeometry(QRect(50, 100, 201, 27));
        listingButton = new QPushButton(centralWidget);
        listingButton->setObjectName(QStringLiteral("listingButton"));
        listingButton->setGeometry(QRect(410, 50, 99, 27));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));
        searchButton->setGeometry(QRect(270, 100, 99, 27));
        sortByNameButton = new QPushButton(centralWidget);
        sortByNameButton->setObjectName(QStringLiteral("sortByNameButton"));
        sortByNameButton->setGeometry(QRect(540, 100, 61, 27));
        sortBySizeButton = new QPushButton(centralWidget);
        sortBySizeButton->setObjectName(QStringLiteral("sortBySizeButton"));
        sortBySizeButton->setGeometry(QRect(600, 100, 61, 27));
        sortByDateButton = new QPushButton(centralWidget);
        sortByDateButton->setObjectName(QStringLiteral("sortByDateButton"));
        sortByDateButton->setGeometry(QRect(660, 100, 61, 27));
        duplicateButton = new QPushButton(centralWidget);
        duplicateButton->setObjectName(QStringLiteral("duplicateButton"));
        duplicateButton->setGeometry(QRect(410, 100, 99, 27));
        viewButton = new QPushButton(centralWidget);
        viewButton->setObjectName(QStringLiteral("viewButton"));
        viewButton->setGeometry(QRect(270, 50, 99, 27));
        fileNameToView = new QLineEdit(centralWidget);
        fileNameToView->setObjectName(QStringLiteral("fileNameToView"));
        fileNameToView->setGeometry(QRect(50, 50, 201, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(610, 70, 67, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 757, 25));
        menuImage = new QMenu(menuBar);
        menuImage->setObjectName(QStringLiteral("menuImage"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuImage->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        browseFolder->setText(QApplication::translate("MainWindow", "Browse", 0));
        folderPathInput->setText(QString());
        listingButton->setText(QApplication::translate("MainWindow", "Listing", 0));
        searchButton->setText(QApplication::translate("MainWindow", "Search", 0));
        sortByNameButton->setText(QApplication::translate("MainWindow", "Name", 0));
        sortBySizeButton->setText(QApplication::translate("MainWindow", "Size", 0));
        sortByDateButton->setText(QApplication::translate("MainWindow", "Date", 0));
        duplicateButton->setText(QApplication::translate("MainWindow", "Duplicate", 0));
        viewButton->setText(QApplication::translate("MainWindow", "View", 0));
        label->setText(QApplication::translate("MainWindow", "Sort by", 0));
        menuImage->setTitle(QApplication::translate("MainWindow", " Image managing tool", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
