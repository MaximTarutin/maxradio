#include "playlistradio.h"
#include "ui_playlistradio.h"

PlaylistRadio::PlaylistRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistRadio)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Popup);
    QSqlQuery query;

}

PlaylistRadio::~PlaylistRadio()
{
    delete ui;
}
