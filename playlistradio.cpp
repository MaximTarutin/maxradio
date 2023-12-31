/* --------------------------------------------------- *
 *                                                     *
 *      Для корректного чтения тегов из url            *
 *      в среду сборки добавить переменную:            *
 *      QT_MEDIA_BACKEND со значением gstreamer        *
 *      (по умолчанию используется значение ffmpeg)    *
 *                                                     *
 *---------------------------------------------------- */


#include "playlistradio.h"
#include "ui_playlistradio.h"
#include <QSqlQuery>
#include <QMediaMetaData>


PlaylistRadio::PlaylistRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlaylistRadio)
{
    FLAG_FIRST_START = true;                                // еще ничего не воспроизвBASSодилось,
                                                            // программу только запустили
    VOL_LEVEL=0.5;

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

    mplayer->setAudioOutput(audioOutput);
    mplayer->audioOutput()->setVolume(VOL_LEVEL);


    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setWindowFlag(Qt::Popup);
    this->setFocusPolicy(Qt::ClickFocus);
    this->setAttribute(Qt::WA_TranslucentBackground);                       // делаем окно прозрачным

    this->ui->Button_play->setStyleSheet("background-color: rgba(255, 255, 255, 0); "
                                         "border-image: url(:/res/play.png);");
    this->ui->Button_stop->setStyleSheet("background-color: rgba(255, 255, 255, 0); "
                                         "border-image: url(:/res/stop-d.png);");

    this->ui->verticalSlider->setMaximum(100);
    this->ui->verticalSlider->setMinimum(0);
    this->ui->verticalSlider->setSliderPosition(VOL_LEVEL*100);

    connect(this->ui->comboBox_rok,     &QComboBox::currentTextChanged, this,   [this](){play_radio("rok");});      // Выбираем категорию радио
    connect(this->ui->comboBox_pop,     &QComboBox::currentTextChanged, this,   [this](){play_radio("pop");});
    connect(this->ui->comboBox_shanson, &QComboBox::currentTextChanged, this,   [this](){play_radio("shanson");});
    connect(this->ui->comboBox_dance,   &QComboBox::currentTextChanged, this,   [this](){play_radio("dance");});
    connect(this->ui->comboBox_hiphop,  &QComboBox::currentTextChanged, this,   [this](){play_radio("hiphop");});
    connect(this->ui->comboBox_news,    &QComboBox::currentTextChanged, this,   [this](){play_radio("news");});
    connect(this->ui->comboBox_humor,   &QComboBox::currentTextChanged, this,   [this](){play_radio("humor");});
    connect(this->ui->comboBox_kind,    &QComboBox::currentTextChanged, this,   [this](){play_radio("kind");});
    connect(this->ui->comboBox_classic, &QComboBox::currentTextChanged, this,   [this](){play_radio("classic");});
    connect(this->ui->comboBox_other,   &QComboBox::currentTextChanged, this,   [this](){play_radio("other");});

    connect(this->ui->Button_play,      &QPushButton::clicked,  this,   &PlaylistRadio::play_button);       // Нажали кнопку play
    connect(this->ui->Button_stop,      &QPushButton::clicked,  this,   &PlaylistRadio::stop_button);       // Нажали кнопку stop

    connect(this->timer,    &QTimer::timeout,       this,   &PlaylistRadio::run_string);                    // бегущая строка
    connect(mplayer, &QMediaPlayer::positionChanged, this,  &PlaylistRadio::track_name);                    // считываем название песни

    connect(this, &PlaylistRadio::volume, this, &PlaylistRadio::volume_level);                              // уровень громкости
    connect(this->ui->verticalSlider,   &QSlider::sliderMoved,  this,   &PlaylistRadio::slider_vol);
}

PlaylistRadio::~PlaylistRadio()
{
    delete ui;
    delete mplayer;
    delete audioOutput;
    delete timer;
    delete runstring;
    delete background;
}

// ------------------------------------ Инициализация ---------------------------------------

void PlaylistRadio::init()
{
    QSqlQuery query;
    QString name, groups;

    ui->comboBox_classic->clear();
    ui->comboBox_classic->addItem("Классика");
    ui->comboBox_dance->clear();
    ui->comboBox_dance->addItem("Танцевальная");
    ui->comboBox_hiphop->clear();
    ui->comboBox_hiphop->addItem("Реп, хип-хоп");
    ui->comboBox_humor->clear();
    ui->comboBox_humor->addItem("Юмор");
    ui->comboBox_kind->clear();
    ui->comboBox_kind->addItem("Детское");
    ui->comboBox_news->clear();
    ui->comboBox_news->addItem("Новости");
    ui->comboBox_other->clear();
    ui->comboBox_other->addItem("Другое");
    ui->comboBox_pop->clear();
    ui->comboBox_pop->addItem("Поп");
    ui->comboBox_rok->clear();
    ui->comboBox_rok->addItem("Рок");
    ui->comboBox_shanson->clear();
    ui->comboBox_shanson->addItem("Шансон");

    if(mplayer->isPlaying()==false)             // очищаем название радио и трека
    {
        ui->radio_label->setText("");
        runstring->setText("");
    }

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
    FLAG_FIRST_START = false;
    play_button();

}

// ------------------------------ кнопка play ------------------------------------

void PlaylistRadio::play_button()
{
    if (!FLAG_FIRST_START)
    {
        timer->start(40);
        mplayer->play();
        this->ui->Button_play->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/play-d.png);");
        this->ui->Button_stop->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/stop.png);");
    }
}

// ------------------------------ кнопка stop ------------------------------------

void PlaylistRadio::stop_button()
{
    timer->stop();
    mplayer->stop();
    this->ui->Button_play->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/play.png);");
    this->ui->Button_stop->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/stop-d.png);");
    emit play_streamer(false);
}

// ----------------------------- бегущая строка -----------------------------------

void PlaylistRadio::run_string()
{
    static int count;
    count--;
    if (count <= -190) count = 190;
    runstring->move(count, 5);
}

// ------------------------- считываем название текущего трека --------------------

void PlaylistRadio::track_name()
{
    emit play_streamer(true);
    track=mplayer->metaData().value(QMediaMetaData::Title).toString();
    emit name_play_song(track);
    runstring->setText(track);
}

// ------------------------- Регулировка громкости посылаем сигнал ----------------

void PlaylistRadio::wheelEvent(QWheelEvent *event)
{
    QPoint angle = event->angleDelta()/8;
    event->accept();

    if(angle.y() > 0)
    {
        emit volume(true);              // Добавляем громкость
    } else
    {
        emit volume(false);             // Убавляем громкость
    }
}

void PlaylistRadio::slider_vol(int p)
{
    float p1;
    p1 = p/10;
    VOL_LEVEL = p1/10;
    mplayer->audioOutput()->setVolume(VOL_LEVEL);
    qDebug() << VOL_LEVEL;
}

void PlaylistRadio::volume_level(bool v)
{
    if(v == true)
    {
        VOL_LEVEL=VOL_LEVEL+0.05;
        if(VOL_LEVEL >= 1) VOL_LEVEL = 1;

    } else
    {
        VOL_LEVEL=VOL_LEVEL-0.05;
        if(VOL_LEVEL <= 0) VOL_LEVEL = 0;
    }

    this->ui->verticalSlider->setSliderPosition(VOL_LEVEL*100);
    mplayer->audioOutput()->setVolume(VOL_LEVEL);
    qDebug() << mplayer->audioOutput()->volume();

}
