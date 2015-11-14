#include "mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setFixedSize(800,500);
    m_gameView = new GameView(this);
    m_gameView->setFocus();
}

MainWindow::~MainWindow()
{
    delete m_gameView;
}
