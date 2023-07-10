/*
    文件等级：密一
    author:klug
    我从未许诺你玫瑰花园
    start:221129
    last:230710
*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
