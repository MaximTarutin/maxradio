#include "editlistradio.h"
#include "ui_editlistradio.h"

EditlistRadio::EditlistRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditlistRadio)
{
    ui->setupUi(this);
}

EditlistRadio::~EditlistRadio()
{
    delete ui;
}
