#include "playlistradio.h"
#include "ui_playlistradio.h"
#include <QSqlQuery>

PlaylistRadio::PlaylistRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistRadio)
{
    ui->setupUi(this);

    this->setWindowFlag(Qt::Tool);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Popup);
    this->setFocusPolicy(Qt::ClickFocus);

    init();

    //connect(this->ui->comboBox_rok,     &QComboBox::currentTextChanged,     this,   &PlaylistRadio::play_radio);
}

PlaylistRadio::~PlaylistRadio()
{
    delete ui;
    delete mplayer;
    delete audioOutput;
}

// ------------------------------------ Инициализация ---------------------------------------

void PlaylistRadio::init()
{
    QSqlQuery query;
    QString name, groups;

    query.exec("SELECT groups, name FROM maxradio_table;");
    while (query.next())
    {
        name = query.value("name").toString();
        groups = query.value("groups").toString();
        if (groups=="Рок") this->ui->comboBox_rok->addItem(name);
        if (groups=="Поп") this->ui->comboBox_pop->addItem(name);
        if (groups=="Шансон") this->ui->comboBox_shanson->addItem(name);
        if (groups=="Танцевальная") this->ui->comboBox_dance->addItem(name);
        if (groups=="Реп, хип-хоп") this->ui->comboBox_hiphop->addItem(name);
        if (groups=="Новости") this->ui->comboBox_news->addItem(name);
        if (groups=="Юмор") this->ui->comboBox_humor->addItem(name);
        if (groups=="Детское") this->ui->comboBox_kind->addItem(name);
        if (groups=="Классика") this->ui->comboBox_classic->addItem(name);
        if (groups=="Другое") this->ui->comboBox_other->addItem(name);
    }

    mplayer =           new QMediaPlayer();
    audioOutput =       new QAudioOutput();
    mplayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);
}

// --------------------------------- проигрывание радио -----------------------------------------

void PlaylistRadio::play_radio()
{
    QString name, url;
    QSqlQuery query;

    //name = list_radio->currentText();
    query.exec("SELECT url FROM maxradio_table WHERE name = '"+name+"'");
    query.next();
    url = query.value("url").toString();
    //list_radio->hide();
    mplayer->setSource(QUrl(url));
    mplayer->play();
}


