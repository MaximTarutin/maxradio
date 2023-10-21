#include "mainwindow.h"
#include <QApplication>
#include <QtPlugin>
#include <QSql>
#include <QSqlDatabase>
#include <QDir>
#include <QString>
#include <QDebug>

Q_IMPORT_PLUGIN(QSQLiteDriverPlugin)

int main(int argc, char *argv[])
{
    QString path;

    #ifdef Q_OS_WIN
         path = "maxradio.db";
    #endif

    #ifdef Q_OS_LINUX
         path = QDir::homePath()+"/.maxradio.db";
    #endif

    qDebug() << path;
    QSqlDatabase maxradio_db = QSqlDatabase::addDatabase("QSQLITE");
    maxradio_db.setDatabaseName(path);
    maxradio_db.open();

    QApplication a(argc, argv);
    MainWindow w;
    QApplication::setQuitOnLastWindowClosed(false);             // Не закрывать приложение
    return a.exec();
}
