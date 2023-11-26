#include "mainwindow.h"
#include <QApplication>
#include <QtPlugin>
#include <QSql>
#include <QSqlDatabase>
#include <QDir>
#include <QString>
#include <QDebug>
#include <QSystemSemaphore>
#include <QSharedMemory>
#include <QMessageBox>

//Q_IMPORT_PLUGIN(QSQLiteDriverPlugin)              // Для статической сборки раскоментировать

int main(int argc, char *argv[])
{
    setenv("QT_MEDIA_BACKEND", "gstreamer",50); // будем использовать серверную часть gstreamer, вместо
                                                // ffmpeg, для нормального отображения тегов url-адреса

    QApplication a(argc, argv);

    // Проверим не запущен ли уже один экземпляр программы, и не даем запустится второй раз

    QSystemSemaphore semaphore("<uniq id>", 1);     // создаём семафор
    semaphore.acquire();                            // Поднимаем семафор, запрещая другим экземплярам
                                                    // работать с разделяемой памятью

    #ifndef Q_OS_WIN32                              // в linux/unix разделяемая память не освобождается
                                                    // при аварийном завершении приложения,
                                                    // поэтому необходимо избавиться от данного мусора

        QSharedMemory nix_fix_shared_memory("<uniq id 2>");
        if (nix_fix_shared_memory.attach())
        {
            nix_fix_shared_memory.detach();
        }
    #endif

    QSharedMemory sharedMemory("<uniq id 2>");      // Создаём экземпляр разделяемой памяти
    bool is_running;                                // переменную для проверки ууже запущенного приложения
    if (sharedMemory.attach())
    {                                               // пытаемся присоединить экземпляр разделяемой памяти
                                                    // к уже существующему сегменту
        is_running = true;                          // Если успешно, то определяем, что уже есть
                                                    // запущенный экземпляр
    }
    else
    {
        sharedMemory.create(1);                     // В противном случае выделяем 1 байт памяти
        is_running = false;                         // И определяем, что других экземпляров не запущено
    }
    semaphore.release();                            // Опускаем семафор

    // Если уже запущен один экземпляр приложения, то сообщаем об этом пользователю
    // и завершаем работу текущего экземпляра приложения

    if (is_running)
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(QObject::tr("Приложение maxradio уже запущено.\n"
                                   "Вы можете запустить только один экземпляр приложения."));
        msgBox.exec();
        return 1;
    }

    QString path;

    #ifdef Q_OS_WIN                     // Создаем файл базы данных
         path = "maxradio.db";
    #endif

    #ifdef Q_OS_LINUX
         path = QDir::homePath()+"/.maxradio.db";
    #endif

    QSqlDatabase maxradio_db = QSqlDatabase::addDatabase("QSQLITE");
    maxradio_db.setDatabaseName(path);
    maxradio_db.open();

    MainWindow w;
    QApplication::setQuitOnLastWindowClosed(false);             // Не закрывать приложение
    return a.exec();
}
