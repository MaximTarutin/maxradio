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
    background->resize(this->width(), this->height());
    background->lower();
    background->setStyleSheet("background-color: rgba(255, 255, 255, 0); border-image: url(:/res/vborder.png);");
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);                       // делаем окно прозрачным

    connect(ui->return_pushButton,      &QPushButton::clicked,      this,   &EditlistRadio::return_mainwindow);     // Кнопка назад
}

EditlistRadio::~EditlistRadio()
{
    delete ui;
}

// ----------------------------- Возврат из редактора -----------------------------------

void EditlistRadio::return_mainwindow()
{
    emit editor_actived(false);         // посылаем сигнал, что редактор больше не активный
    ui->Category_comboBox->clear();     // очищаем список групп радиостанций
    this->close();
}

// ----------------------------- Инициализация редактора -------------------------------

void EditlistRadio::init_editor()
{
    QSqlQuery   query;
    QString     groups;

    query.exec("SELECT DISTINCT groups FROM maxradio_table;");

    ui->Category_comboBox->addItem("");
    while (query.next())
    {
        groups = query.value("groups").toString();
        ui->Category_comboBox->addItem(groups);
        qDebug() << groups;
    }

}
