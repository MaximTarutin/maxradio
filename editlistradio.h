#ifndef EDITLISTRADIO_H
#define EDITLISTRADIO_H

#include <QWidget>
#include <QLabel>

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

signals:
    void editor_actived(bool);                  // сигнал посылается при закрытии редактора

private slots:
    void return_mainwindow();                   // выйти из редактора


public:
    void init_editor();                         // инициализация редактора

};

#endif // EDITLISTRADIO_H
