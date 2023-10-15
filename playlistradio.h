#ifndef PLAYLISTRADIO_H
#define PLAYLISTRADIO_H

#include <QWidget>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QLabel>

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
    QLabel              *background;
    QVariant            vr;

private slots:
    void play_button();
    void stop_button();

public:
    void init();
    void play_radio(QString radio);
};

#endif // PLAYLISTRADIO_H
