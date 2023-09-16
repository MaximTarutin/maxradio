#include "mainwindow.h"
#include "connectbasa.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createConnect();
    FLAG_SHOW = false;
    trayIcon =          new QSystemTrayIcon(this);
    menu =              new QMenu(this);
    exit_of_programm =  new QAction("Выход", this);
    editor_radio =      new QAction("Редактор радиостанций", this);
    playlist_radio =    new PlaylistRadio();

    init();                         // инициируем программу (значок в трее и меню)
    init_size();                    // инициируем переменные ширины и высоты экрана
    init_playlist();                // инициируем плейлист

    connect(exit_of_programm,   &QAction::triggered,            this,   &MainWindow::close_programm);       // выход из программы
    connect(editor_radio,       &QAction::triggered,            this,   &MainWindow::editor);               // редактор плейлиста
    connect(trayIcon,           &QSystemTrayIcon::activated,    this,   &MainWindow::show_list_radio);      // клик по иконке
}

MainWindow::~MainWindow()
{
    delete trayIcon;
    delete menu;
    delete exit_of_programm;
    delete editor_radio;
    delete playlist_radio;
}

// ----------------------------- Инициализация -----------------------------------

void MainWindow::init()
{
    QIcon trayImage(":/res/radio-color.png");                   // Приложение запускаем в трее
    trayIcon->setIcon(trayImage);
    trayIcon->show();
    menu->addAction(editor_radio);                              // Формируем меню приложения
    menu->addSeparator();
    menu->addAction(exit_of_programm);
    trayIcon->setContextMenu(menu);
}

// ----------------------------- Инициализация переменных size_w, size_h -----------------------------

void MainWindow::init_size()
{
    screen = QApplication::screens().at(0);
    QSize size = screen->availableSize();
    size_w = size.width();                                      // Ширина экрана !!!!!!!!!
    size_h = size.height();
}

// ---------------------------- Инициализация плейлиста --------------------------------------

void MainWindow::init_playlist()
{
    QSqlQuery query;
    QString   name;

    query.exec("CREATE TABLE maxradio_table ("
               "groups STRING, name STRING, url STRING, UNIQUE(url));");

    query.exec("INSERT INTO maxradio_table (groups, name, url)"
               "VALUES ('Рок', 'Наше радио', 'http://nashe.streamr.ru/nashe-128.mp3')");
    query.exec("INSERT INTO maxradio_table (groups, name, url) "
               "VALUES ('Поп', 'Европа плюс', 'http://ep256.hostingradio.ru:8052/europaplus256.mp3')");
    query.exec("INSERT INTO maxradio_table (groups, name, url) "
               "VALUES ('Поп', 'Ретро FM', 'http://retroserver.streamr.ru:8043/retro256.mp3')");
    query.exec("INSERT INTO maxradio_table (groups, name, url) "
               "VALUES ('Поп', 'NRJ',"
               "'http://185.52.127.168/fr/30001/mp3_128.mp3?origine=fluxradios?1535727639539.mp3&access_token=bccc39f27055469799ec9f2f48d34f12')");
}

// ----------------------------- Редактор радиостанций ---------------------------------

void MainWindow::editor()
{
    printf("fghjk");
}

// ----------------------------- Список радиостанций ----------------------------------

void MainWindow::show_list_radio(QSystemTrayIcon::ActivationReason r)
{
    if (!FLAG_SHOW)
    {
        if (r==QSystemTrayIcon::Trigger)
        {
            int x_cur, y_cur;
            x_cur = QCursor::pos().x();
            y_cur = QCursor::pos().y();

            if(y_cur < size_h/2)
            {
                playlist_radio->move(x_cur-playlist_radio->width()/2, y_cur+40);
            } else
            {
                playlist_radio->move(x_cur-playlist_radio->width()/2, y_cur-playlist_radio->height()-40);
            }
            playlist_radio->show();
        }
        FLAG_SHOW = true;
        return;
    } else
    {
        playlist_radio->hide();
        FLAG_SHOW = false;
        return;
    }
}

// ------------------------------------------------------------------------------------

void MainWindow::play_radio()
{


}

// ----------------------------- Выход из программы ------------------------------------

void MainWindow::close_programm()
{
    exit(0);
}
