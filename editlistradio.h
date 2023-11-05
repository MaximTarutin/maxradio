#ifndef EDITLISTRADIO_H
#define EDITLISTRADIO_H

#include <QWidget>

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
};

#endif // EDITLISTRADIO_H
