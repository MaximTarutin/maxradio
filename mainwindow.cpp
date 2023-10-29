#include "mainwindow.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
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
    connect(playlist_radio,     &PlaylistRadio::play_streamer,  this,   &MainWindow::icon_in_tray);         // цвет иконки
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
    QIcon trayImage(":/res/radio-gray.png");                   // Приложение запускаем в трее
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
    size_w = size.width();                                      // Ширина экрана
    size_h = size.height();                                     // Высота экрана
}

// ---------------------------- Инициализация плейлиста --------------------------------------

void MainWindow::init_playlist()
{
    QSqlQuery query;
    QString   name;
    int count = 0;

    query.exec("SELECT COUNT(*) FROM maxradio_table");              // Проверяем не пустая ли база
    while(query.next())
    {
        count++;
    }

    if(count == 0)
    {
        query.exec("CREATE TABLE maxradio_table ("
                   "groups STRING, name STRING, url STRING, UNIQUE(url));");
        query.exec("INSERT INTO maxradio_table (groups, name, url)"
                   "VALUES ('Рок', 'Наше радио', 'http://nashe.streamr.ru/nashe-128.mp3')");
        query.exec("INSERT INTO maxradio_table (groups, name, url)"
                   "VALUES ('Рок', 'Maximum', 'http://46.146.243.42:8000/max')");

        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Европа плюс', 'http://ep128.hostingradio.ru:8030/ep128')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Ретро FM', 'http://retroserver.streamr.ru:8043/retro256.mp3')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Русское радио','http://82.146.46.30:8000/rusradio')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Маруся-FM','http://radio-holding.ru:9000/marusya_default')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Радио Ваня','http://icecast-radiovanya.cdnvideo.ru:8000/rv_spb')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Радио дача','http://listen5.vdfm.ru:8000/dacha')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Hit FM','http://str.simpex.ru:8076/HIT')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Поп', 'Пассаж','http://listen.radiopassazh.ru/mp3-128')");

        //query.exec("INSERT INTO maxradio_table (groups, name, url) "
        //          "VALUES ('Реп, хип-хоп', 'Русский реп','https://radio-stream-0.obozrevatel.com/rep128.mp3')");

        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Танцевальная', 'NRJ',"
                   "'http://185.52.127.168/fr/30001/mp3_128.mp3?origine=fluxradios?1535727639539.mp3&access_token=bccc39f27055469799ec9f2f48d34f12')");

        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Шансон', 'радио Шансон','http://chanson.hostingradio.ru:8041/chanson128.mp3')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Шансон', 'За друзей','http://listen2.myradio24.com:9000/8144')");


        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Юмор', 'Comedy радио','http://pub0302.101.ru:8000/stream/reg/mp3/128/region_comedy_31')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Юмор', 'Юмор FM','http://pub0302.101.ru:8000/stream/reg/mp3/128/region_humor_6')");

        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Детское', 'Детское радио','http://pub0302.101.ru:8000/stream/reg/mp3/128/region_deti_2')");

        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Новости', 'Комерсант FM','http://kommersant77.hostingradio.ru:8016/kommersant64.mp3')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Новости', 'Комсомольская правда','http://kraskp.ru:8000/mskregion')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Новости', 'радио России','http://91.228.66.62:8000/live')");
        query.exec("INSERT INTO maxradio_table (groups, name, url) "
                   "VALUES ('Новости', 'Маяк','http://icecast.vgtrk.cdnvideo.ru/mayakfm_mp3_128kbps')");

        query.exec("INSERT INTO maxradio_table (groups, name, url)"
                   "VALUES ('Классика', 'Радио классик', 'http://jfm1.hostingradio.ru:14536/rcstream.mp3')");
        query.exec("INSERT INTO maxradio_table (groups, name, url)"
                   "VALUES ('Классика', 'Радио культура', 'http://icecast.vgtrk.cdnvideo.ru/kulturafm')");

        query.exec("INSERT INTO maxradio_table (groups, name, url)"
                   "VALUES ('Другое', 'TarutinRadio', "
                   "'https://ep256.hostingradio.ru:8052/europaplus256.mp3')");


    }
    playlist_radio->init();
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

//------------------------------ проверка существования базы данных ----------------------

bool MainWindow::check_db_file()
{
    QFileInfo check_file("maxradio.db");
    if (check_file.exists() && check_file.isFile())
    {
        return true;
    } else {
        return false;
    }
}


// ----------------------------- Выход из программы ------------------------------------

void MainWindow::close_programm()
{
    exit(0);
}

// ------------------------------ Меняем цвет иконки ----------------------------------

void MainWindow::icon_in_tray(bool b)
{
    if (b == true)
    {
        QIcon trayImage(":/res/radio-color.png");                   // Приложение запускаем в трее
        trayIcon->setIcon(trayImage);
        trayIcon->show();
    } else
    {
        QIcon trayImage(":/res/radio-gray.png");                   // Приложение запускаем в трее
        trayIcon->setIcon(trayImage);
        trayIcon->show();
    }
}
