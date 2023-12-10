#ifndef PLAYLISTRADIO_H
#define PLAYLISTRADIO_H

#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QLabel>
#include <QTimer>
#include <QWheelEvent>
#include <QMouseEvent>

namespace Ui {
class PlaylistRadio;
}

class PlaylistRadio : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistRadio(QWidget *parent = nullptr);
    ~PlaylistRadio();

private:
    Ui::PlaylistRadio *ui;

    QMediaPlayer        *mplayer;
    QAudioOutput        *audioOutput;
    QLabel              *background;        // фоновая картинка плейлиста
    QTimer              *timer;             // таймер для бегущей строки
    QTimer              *timer1;
    QVariant            vr;
    QString             url;
    QString             track;
    QLabel              *runstring;         // бегущая строка
    bool                FLAG_FIRST_START;   // программа только что запущена
    float               VOL_LEVEL;          // уровень громкости

signals:
    void play_streamer(bool);               // изменяет цвет иконки, в зависимости от того играет поток или нет
    void volume(bool);                      // изменяет громкость: true - громче, false - тише

private slots:
    void play_button();                                                 // запуск радиопотока по кнопке
    void stop_button();                                                 // остановка радиопотока по кнопке
    void run_string();                                                  // бегущая строка с названием трека
    void track_name();                                                  // считываем название трека из потока
    void volume_level(bool v);                                          // регулировка уровня громкости

protected:
    void wheelEvent(QWheelEvent *event);                                // Колесиком мышки регулирем громкость

public:
    void init();                                                        // инициализация плейлиста
    void play_radio(QString radio);     // проигрывание потока
};

#endif // PLAYLISTRADIO_H
