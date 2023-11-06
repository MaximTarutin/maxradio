#ifndef EDITLISTRADIO_H
#define EDITLISTRADIO_H

#include <QWidget>
#include <QLabel>
#include <QMessageBox>

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

signals:
    void editor_actived(bool);                  // сигнал посылается при закрытии редактора
    void change_playlist(bool);                 // сигнал true - плейлист изменен, false - нет

private slots:
    void return_mainwindow();                   // выйти из редактора
    void update_del_combobox();                 // обновить список радиостанций для удаления
    void del_radio();                           // удалить радиостанцию


};

#endif // EDITLISTRADIO_H
