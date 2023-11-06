#include "editlistradio.h"
#include "ui_editlistradio.h"
#include <QSqlQuery>

EditlistRadio::EditlistRadio(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditlistRadio)
{
    ui->setupUi(this);
    this->hide();

    background = new QLabel(this);
    message    = new QMessageBox(this);

    message->setWindowFlag(Qt::FramelessWindowHint);

    background->resize(this->width(), this->height());
    background->lower();
    background->setStyleSheet("background-color: rgba(255, 255, 255, 100); border-image: url(:/res/vborder.png); ");
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);                       // делаем окно прозрачным

    connect(ui->return_pushButton, &QPushButton::clicked,           this,   &EditlistRadio::return_mainwindow);     // Кнопка назад
    connect(ui->Category_comboBox, &QComboBox::currentIndexChanged, this,   &EditlistRadio::update_del_combobox);   // изменяем группу
    connect(ui->del_pushButton,    &QPushButton::clicked,           this,   &EditlistRadio::del_radio);             // удаляем радиостанцию
}

EditlistRadio::~EditlistRadio()
{
    delete ui;
    delete background;
    delete message;
}

// ----------------------------- Возврат из редактора -----------------------------------

void EditlistRadio::return_mainwindow()
{
    emit editor_actived(false);         // посылаем сигнал, что редактор больше не активный
    this->close();
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




