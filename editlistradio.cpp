#include "editlistradio.h"
#include "ui_editlistradio.h"
#include <QSqlQuery>
#include <QProcess>
#include <QTcpSocket>
#include <QUrl>
#include <QSqlQuery>

EditlistRadio::EditlistRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditlistRadio)
{
    ui->setupUi(this);
    this->hide();

    background      = new QLabel(this);
    message         = new QMessageBox(this);
    check_player    = new QMediaPlayer(this);
    audiooutput     = new QAudioOutput(this);
    timer_check_url = new QTimer(this);

    check_player->setAudioOutput(audiooutput);
    audiooutput->setVolume(0);

    message->setWindowFlag(Qt::FramelessWindowHint);

    background->resize(this->width(), this->height());
    background->lower();
    background->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/vborder.png); ");

    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);                       // делаем окно прозрачным

    connect(ui->return_pushButton, &QPushButton::clicked,           this,   &EditlistRadio::return_mainwindow);     // Кнопка назад
    connect(ui->Category_comboBox, &QComboBox::currentIndexChanged, this,   &EditlistRadio::update_del_combobox);   // изменяем группу
    connect(ui->del_pushButton,    &QPushButton::clicked,           this,   &EditlistRadio::del_radio);             // удаляем радиостанцию
    connect(ui->add_pushButton,    &QPushButton::clicked,           this,   &EditlistRadio::add_radio);             // добавляем радиостанцию
}

EditlistRadio::~EditlistRadio()
{
    delete ui;
    delete background;
    delete message;
    delete check_player;
}

// ----------------------------- Возврат из редактора -----------------------------------

void EditlistRadio::return_mainwindow()
{
    emit editor_actived(false);             // посылаем сигнал, что редактор больше не активный
    timer_check_url->stop();

    disconnect(check_player,  &QMediaPlayer::positionChanged,  this,  &EditlistRadio::check_position);
    disconnect(timer_check_url, &QTimer::timeout, this, &EditlistRadio::timer_changed);

    this->close();                          // для обновления плейлиста в playlistradio.cpp
}

// ------------------------------ Обновить combobox радиостанций для удаления ------------------

void EditlistRadio::update_del_combobox()
{
    QSqlQuery query;
    QString groups, name;

    ui->del_comboBox->clear();

    groups = ui->Category_comboBox->currentText();

    if(groups == "")
    {
        ui->del_comboBox->clear();
        return;
    }

    query.exec("SELECT groups, name FROM maxradio_table WHERE groups = '"+groups+"';");
    ui->del_comboBox->addItem("");
    while (query.next())
    {
        name = query.value("name").toString();
        ui->del_comboBox->addItem(name);
    }
}

// ------------------------------ Удаление радио из плейлиста ----------------------------------

void EditlistRadio::del_radio()
{
    QString groups, name;
    QSqlQuery query;

    groups = ui->Category_comboBox->currentText();
    name = ui->del_comboBox->currentText();

    if (groups==""||name == "")
    {
        message->setStyleSheet("background-color: darkgrey; color: rgb(255, 255, 0); "
                               "font: 700 italic 14pt 'Times New Roman';");
        message->setText("<center><font color = 'red'> Ошибка !!! </center>");
        message->setInformativeText("<center>Не выбранна группа или радиостанция...</center>");
        message->setIcon(QMessageBox::Warning);
        message->show();
        return;
    } else
    {
        message->setStyleSheet("background-color: pink; color: black; "
                               "font: 700 italic 14pt 'Times New Roman';");
        message->setText("<center><font color = 'red'>Внимание !!!</center>");
        message->setInformativeText("<center> Вы действительно "
                                    "хотите удалить радиостанцию: <font color = 'magenta'>"
                                    ""+name+" <font color = 'black'>из группы: "
                                    "<font color = 'magenta'>"+groups+"<font color = 'black'>?");
        message->setIcon(QMessageBox::Critical);
        message->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        message->setDefaultButton(QMessageBox::Cancel);
        message->show();

        int ret = message->exec();

        switch (ret)
        {
        case QMessageBox::Ok: query.exec("DELETE FROM maxradio_table WHERE groups='"+groups+"' and name='"+name+"';"); break;
        case QMessageBox::Cancel: break;
        }

        ui->del_comboBox->clear();
        update_del_combobox();
        emit change_playlist(true);
    }
}

// ----------------------------------- Добавить радиостанцию -----------------------------------

void EditlistRadio::add_radio()
{
    QString     group, name, url, db_url;
    QSqlQuery   query;

    group = ui->Category_comboBox->currentText();
    name  = ui->add_url_lineEdit_2->text();
    url   = ui->add_url_lineEdit->text();

    if(group == "")
    {
        message->setStyleSheet("background-color: pink; color: black; "
                             "font: 700 italic 14pt 'Times New Roman';");
        message->setText("<center><font color = 'red'> Ошибка !!! </center>");
        message->setInformativeText("<center>Не выбранна группа куда добавить url ...</center>");
        message->setIcon(QMessageBox::Warning);
        message->show();
        return;
    }
    if(name == "")
    {
        message->setStyleSheet("background-color: pink; color: black; "
                               "font: 700 italic 14pt 'Times New Roman';");
        message->setText("<center><font color = 'red'> Ошибка !!! </center>");
        message->setInformativeText("<center>Не заполнено поле 'Название' ...</center>");
        message->setIcon(QMessageBox::Warning);
        message->show();
        return;
    }
    if(url == "")
    {
        message->setStyleSheet("background-color: pink; color: black; "
                               "font: 700 italic 14pt 'Times New Roman';");
        message->setText("<center><font color = 'red'> Ошибка !!! </center>");
        message->setInformativeText("<center>Не заполнено поле 'URL радио' ...</center>");
        message->setIcon(QMessageBox::Warning);
        message->show();
        return;
    }


    /* Проверяем нет ли такого URL в базе данных */

    query.exec("SELECT url FROM maxradio_table");
    while (query.next())
    {
        db_url = query.value("url").toString();
        if (url == db_url)
        {
            message->setStyleSheet("background-color: pink; color: black; "
                                   "font: 700 italic 14pt 'Times New Roman';");
            message->setText("<center><font color = 'red'> Внимание !!! </center>");
            message->setInformativeText("<center>Такой URL уже есть в базе данных !!! "
                                        "Радиостанция не будет добавлена в плейлист !!!'</center>");
            message->setIcon(QMessageBox::Critical);
            message->show();
            ui->add_url_lineEdit->clear();
            return;
        }
    }

    check_url_window(url);
}

// ------------------------------ Проверяем рабочий ли URL -----------------------------------

void EditlistRadio::check_url_window(QString url)
{
    check_player->setSource(QUrl(url));
    check_player->play();
    num = 20;                               // количество секунд для обратного отсчета времени
    timer_check_url->start(1000);           // запускаем таймер проверки url

    connect(check_player,  &QMediaPlayer::positionChanged,  this,  &EditlistRadio::check_position);
    connect(timer_check_url, &QTimer::timeout, this, &EditlistRadio::timer_changed);

// *********** Всплывающее окно с обратным отсчетом времени **************

    message->setStyleSheet("background-color: cyan; color: black; "
                           "font: 700 italic 14pt 'Times New Roman';");
    message->setText("<center><font color = 'red'>Проверка существования потока...</center>");
    message->setInformativeText("<center> Время проверки:  "+QString::number(num)+" сек.");
    message->setIcon(QMessageBox::Information);
    message->setStandardButtons(QMessageBox::Cancel);
    message->show();

    int ret = message->exec();

    switch (ret)
    {
    case QMessageBox::Cancel:   timer_check_url->stop();                // кнопка отмена
        disconnect(check_player,  &QMediaPlayer::positionChanged,
                   this,  &EditlistRadio::check_position);
        disconnect(timer_check_url, &QTimer::timeout,
                   this, &EditlistRadio::timer_changed);
        message->close();
        break;
    }
}

// --------- Если позиция QMediaPlayer изменилась, то поток существует ---------------------------

void EditlistRadio::check_position()
{
    QString     group, name, url;
    QSqlQuery   query;

    group = ui->Category_comboBox->currentText();
    name  = ui->add_url_lineEdit_2->text();
    url   = ui->add_url_lineEdit->text();

    message->setStyleSheet("background-color: lightgreen; color: black; "
                           "font: 700 italic 14pt 'Times New Roman';");
    message->setText("<center><font color = 'red'>Проверка существования потока...</center>");
    message->setInformativeText("<center> Данный поток существует, радиостанция добавлена в плейлист !!!");
    message->setIcon(QMessageBox::Information);
    message->setStandardButtons(QMessageBox::Ok);
    message->show();

    num = 20;
    timer_check_url->stop();
    disconnect(check_player,  &QMediaPlayer::positionChanged,  this,  &EditlistRadio::check_position);
    disconnect(timer_check_url, &QTimer::timeout, this, &EditlistRadio::timer_changed);



    /* Добавляем радиостанцию в базу данных */

    query.exec("INSERT INTO maxradio_table (groups, name, url) VALUES ('"+group+"','"+name+"','"+url+"')");
}

// --------- Если вышло время и позиция не изменилась, то потока не существует -------------------

void EditlistRadio::timer_changed()
{
    message->setInformativeText("<center> Время проверки:  "+QString::number(num)+" сек.");
    num--;
    if(num<0)
    {
        num = 20;
        timer_check_url->stop();
        disconnect(check_player,  &QMediaPlayer::positionChanged,  this,  &EditlistRadio::check_position);
        disconnect(timer_check_url, &QTimer::timeout, this, &EditlistRadio::timer_changed);
        message->close();
    }
}




