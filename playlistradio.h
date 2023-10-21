#ifndef PLAYLISTRADIO_H
#define PLAYLISTRADIO_H

#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QLabel>
#include <QTimer>

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
    QVariant            vr;
    QString             url;
    QString             track;
    QLabel              *runstring;         // бегущая строка
    bool                FLAG_FIRST_START;   // программа только что запущена

signals:
    void play_streamer(bool);

private slots:
    void play_button();         // запуск радиопотока по кнопке
    void stop_button();         // остановка радиопотока по кнопке
    void run_string();          // бегущая строка с названием трека
    void track_name();          // считываем название трека из потока

public:
    void init();                        // инициализация плейлиста
    void play_radio(QString radio);     // проигрывание потока
};

#endif // PLAYLISTRADIO_H
