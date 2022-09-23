#include "pch.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QTableView *processesTableView, QListView* logListView)
    : QMainWindow(parent),
      processesTableView(processesTableView),
      logListView(logListView)

{
    QWidget* centerWidget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(centerWidget);

    layout->addWidget(processesTableView);
    layout->addWidget(logListView);



    setCentralWidget(centerWidget);
}



