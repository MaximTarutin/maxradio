#ifndef CONNECTBASA
#define CONNECTBASA

#include <QSql>
#include <QSqlDatabase>

QSqlDatabase maxradio_db = QSqlDatabase::addDatabase("QSQLITE");

bool static createConnect()
{    
    maxradio_db.setDatabaseName("maxradio.db");
    maxradio_db.open();
    return true;
}

void close_db()
{
    maxradio_db.close();
}
#endif // CONNECTBASA

