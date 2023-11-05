#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QIcon>
#include <QMenu>
#include <QAction>
#include <QUrl>
#include <QScreen>
#include <QSize>
#include <QEvent>
#include <QFileInfo>
#include "playlistradio.h"
#include "editlistradio.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:    
    QSystemTrayIcon     *trayIcon;                              // Иконка в трее
    QMenu               *menu;                                  // меню по правой кнопке мышки
    QAction             *exit_of_programm;                      // меню выход из программы
    QAction             *editor_radio;                          // меню редактор плейлиста
    PlaylistRadio       *playlist_radio;                        // плейлист радиостанций
    EditlistRadio       *editlist_radio;                        // редактор плейлиста
    QScreen             *screen;
    int                 size_w;                                 // ширина экрана
    int                 size_h;                                 // высота экрана
    bool                FLAG_SHOW;
    bool                FLAG_EDITOR;                            // запущен ли редактор плейлиста, true - да

    bool check_db_file();                                       // Проверяем существует ли база данных

private slots:
    void close_programm();                                      // Выход из программы
    void editor();                                              // Редактор радиостанций
    void show_list_radio(QSystemTrayIcon::ActivationReason);    // Показать список радиостанций
    void init();                                                // Инициализация
    void init_size();                                           // Инициализация переменных size_w, size_h
    void init_playlist();                                       // Инициализация плейлиста
    void icon_in_tray(bool b);                                  // меняет иконку в зависимости от того проигрывается ли поток
    void change_flag_editor(bool b);                            // изменяет FLAG_EDITOR на false, при закрытии редактора
};

#endif // MAINWINDOW_H
