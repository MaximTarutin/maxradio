#include "mainwindow.h"
#include <QApplication>
#include <QtPlugin>

Q_IMPORT_PLUGIN(QSQLiteDriverPlugin)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setQuitOnLastWindowClosed(false);             // Не закрывать приложение
    return a.exec();
}
