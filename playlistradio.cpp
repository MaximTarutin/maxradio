#include "playlistradio.h"
#include "ui_playlistradio.h"
#include <QSqlQuery>
#include <QMediaMetaData>

PlaylistRadio::PlaylistRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistRadio)
{
    ui->setupUi(this);

    mplayer =           new QMediaPlayer();
    audioOutput =       new QAudioOutput();
    background =        new QLabel(this);
    timer =             new QTimer;
    runstring =         new QLabel(ui->track_label);

    background->resize(this->width(), this->height());
    background->lower();
    background->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/ramka.png);");
    runstring->move(190, 5);
    runstring->resize(600, 30);
    runstring->show();

    mplayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(50);

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Popup);
    this->setFocusPolicy(Qt::ClickFocus);
    this->setAttribute(Qt::WA_TranslucentBackground);                       // делаем окно прозрачным

    this->ui->Button_play->setStyleSheet("background-color: rgba(255, 255, 255, 0); "
                                         "border-image: url(:/res/play.png);");
    this->ui->Button_stop->setStyleSheet("background-color: rgba(255, 255, 255, 0); "
                                         "border-image: url(:/res/stop-d.png);");

    connect(this->ui->comboBox_rok,     &QComboBox::currentTextChanged, [this](){play_radio("rok");});
    connect(this->ui->comboBox_pop,     &QComboBox::currentTextChanged, [this](){play_radio("pop");});
    connect(this->ui->comboBox_shanson, &QComboBox::currentTextChanged, [this](){play_radio("shanson");});
    connect(this->ui->comboBox_dance,   &QComboBox::currentTextChanged, [this](){play_radio("dance");});
    connect(this->ui->comboBox_hiphop,  &QComboBox::currentTextChanged, [this](){play_radio("hiphop");});
    connect(this->ui->comboBox_news,    &QComboBox::currentTextChanged, [this](){play_radio("news");});
    connect(this->ui->comboBox_humor,   &QComboBox::currentTextChanged, [this](){play_radio("humor");});
    connect(this->ui->comboBox_kind,    &QComboBox::currentTextChanged, [this](){play_radio("kind");});
    connect(this->ui->comboBox_classic, &QComboBox::currentTextChanged, [this](){play_radio("classic");});
    connect(this->ui->comboBox_other,   &QComboBox::currentTextChanged, [this](){play_radio("other");});

    connect(this->ui->Button_play,      &QPushButton::clicked,  this,   &PlaylistRadio::play_button);
    connect(this->ui->Button_stop,      &QPushButton::clicked,  this,   &PlaylistRadio::stop_button);

    connect(this->timer,    &QTimer::timeout,       this,   &PlaylistRadio::run_string);

    connect(mplayer, &QMediaPlayer::positionChanged, [this]()
    {
            vr=mplayer->metaData().value(QMediaMetaData::Title);
            //ui->track_label->setText(vr.toString());
            //QString m = vr.toString();
            runstring->setText(vr.toString());
            //ui->track_label->show();
            //runstring->setText(vr.toString());
            //runstring->show();
            qDebug() << QList(mplayer->metaData().keys());
            //qDebug() << m;
    });

}

PlaylistRadio::~PlaylistRadio()
{
    delete ui;
    delete mplayer;
    delete audioOutput;
    delete timer;
    delete runstring;
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
}

// --------------------------------- выбор радио из списка -----------------------------------------

void PlaylistRadio::play_radio(QString radio)
{
    QString name;
    QSqlQuery query;

    if (radio=="rok")
    {
        name = this->ui->comboBox_rok->currentText();
        this->ui->comboBox_rok->setCurrentIndex(0);
    }
    if (radio=="pop")
    {
        name = this->ui->comboBox_pop->currentText();
        this->ui->comboBox_pop->setCurrentIndex(0);
    }
    if (radio=="shanson")
    {
        name = this->ui->comboBox_shanson->currentText();
        this->ui->comboBox_shanson->setCurrentIndex(0);
    }
    if (radio=="dance")
    {
        name = this->ui->comboBox_dance->currentText();
        this->ui->comboBox_dance->setCurrentIndex(0);
    }
    if (radio=="hiphop")
    {
        name = this->ui->comboBox_hiphop->currentText();
        this->ui->comboBox_hiphop->setCurrentIndex(0);
    }
    if (radio=="news")
    {
        name = this->ui->comboBox_news->currentText();
        this->ui->comboBox_news->setCurrentIndex(0);
    }
    if (radio=="humor")
    {
        name = this->ui->comboBox_humor->currentText();
        this->ui->comboBox_humor->setCurrentIndex(0);
    }
    if (radio=="kind")
    {
        name = this->ui->comboBox_kind->currentText();
        this->ui->comboBox_kind->setCurrentIndex(0);
    }
    if (radio=="classic")
    {
        name = this->ui->comboBox_classic->currentText();
        this->ui->comboBox_classic->setCurrentIndex(0);
    }
    if (radio=="other")
    {
        name = this->ui->comboBox_other->currentText();
        this->ui->comboBox_other->setCurrentIndex(0);
    }

    this->ui->radio_label->setText(name);

    query.exec("SELECT url FROM maxradio_table WHERE name = '"+name+"'");
    query.next();
    url = query.value("url").toString();
    mplayer->setSource(QUrl(url));
    query.clear();
    play_button();

}

// ------------------------------ кнопка play ------------------------------------

void PlaylistRadio::play_button()
{
    timer->start(30);
    mplayer->play();
    this->ui->Button_play->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/play-d.png);");
    this->ui->Button_stop->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/stop.png);");
}

// ------------------------------ кнопка stop ------------------------------------

void PlaylistRadio::stop_button()
{
    timer->stop();
    mplayer->stop();
    this->ui->Button_play->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/play.png);");
    this->ui->Button_stop->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/stop-d.png);");
}

// ----------------------------- бегущая строка -----------------------------------

void PlaylistRadio::run_string()
{
    static int count;
    count--;
    if (count <= -190) count = 190;
    runstring->move(count, 5);
}

