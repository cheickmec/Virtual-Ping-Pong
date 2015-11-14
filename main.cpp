#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow pingpong;
    pingpong.setWindowTitle("Cheick | PINGPONG");
    pingpong.show();

    return a.exec();
}
