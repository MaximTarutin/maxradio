#ifndef EDITLISTRADIO_H
#define EDITLISTRADIO_H

#include <QWidget>
#include <QLabel>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>

namespace Ui {
class EditlistRadio;
}

class EditlistRadio : public QWidget
{
    Q_OBJECT

public:
    explicit EditlistRadio(QWidget *parent = nullptr);
    ~EditlistRadio();

private:
    Ui::EditlistRadio *ui;

    QLabel          *background;                // фон редактора;
    QMessageBox     *message;                   // сообщения
    QMediaPlayer    *check_player;              // плеер для проверки существования потока
    QAudioOutput    *audiooutput;               // вывод аудио
    QTimer          *timer_check_url;           // таймер времени в течении которого проверяется существование потока
    int             num;                        // количество секунд для обратного отсчета времени при проверке url


    void check_url_window(QString url);         // окно проверки рабочий ли поток

signals:
    void editor_actived(bool);                  // сигнал посылается при закрытии редактора
    void change_playlist(bool);                 // сигнал true - плейлист изменен, false - нет

private slots:
    void return_mainwindow();                   // выйти из редактора
    void update_del_combobox();                 // обновить список радиостанций для удаления
    void del_radio();                           // удалить радиостанцию
    void add_radio();                           // Добавить радиостанцию
    void check_position();                      // проверяем изменяется ли позиция в потоке url в течении 10 сек,
                                                // если нет, то поток не существует
    void timer_changed();                       // обратный отсчет таймера при проверке существования url



};

#endif // EDITLISTRADIO_H
