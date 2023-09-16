#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QAction>
//#include <QBuffer>
#include <QUrl>
#include <QScreen>
#include <QSize>
#include <QEvent>
#include "playlistradio.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSystemTrayIcon     *trayIcon;
    QMenu               *menu;
    QAction             *exit_of_programm;
    QAction             *editor_radio;
//    QBuffer             *buffer;
    PlaylistRadio       *playlist_radio;
    QScreen             *screen;
    int                 size_w;
    int                 size_h;
    bool                FLAG_SHOW;

private slots:
    void close_programm();                                      // Выход из программы
    void editor();                                              // Редактор радиостанций
    void show_list_radio(QSystemTrayIcon::ActivationReason);    // Показать список радиостанций
    void play_radio();                                          // Запуск выбранной радиостанции
    void init();                                                // Инициализация
    void init_size();                                           // Инициализация переменных size_w, size_h
    void init_playlist();                                       // Инициализация плейлиста

};

#endif // MAINWINDOW_H
