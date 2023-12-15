/********************************************************************************
** Form generated from reading UI file 'playlistradio.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYLISTRADIO_H
#define UI_PLAYLISTRADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaylistRadio
{
public:
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *radio_label;
    QSpacerItem *horizontalSpacer_6;
    QLabel *track_label;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_play;
    QSpacerItem *horizontalSpacer_3;
    QSlider *verticalSlider;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *Button_stop;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_rok;
    QComboBox *comboBox_pop;
    QComboBox *comboBox_dance;
    QComboBox *comboBox_shanson;
    QComboBox *comboBox_hiphop;
    QComboBox *comboBox_classic;
    QComboBox *comboBox_kind;
    QComboBox *comboBox_humor;
    QComboBox *comboBox_news;
    QComboBox *comboBox_other;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *PlaylistRadio)
    {
        if (PlaylistRadio->objectName().isEmpty())
            PlaylistRadio->setObjectName("PlaylistRadio");
        PlaylistRadio->resize(234, 500);
        PlaylistRadio->setMinimumSize(QSize(231, 500));
        PlaylistRadio->setMaximumSize(QSize(234, 500));
        PlaylistRadio->setStyleSheet(QString::fromUtf8("background-image: url(:/res/prosrach.png);\n"
""));
        gridLayout_3 = new QGridLayout(PlaylistRadio);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        radio_label = new QLabel(PlaylistRadio);
        radio_label->setObjectName("radio_label");
        radio_label->setMinimumSize(QSize(210, 30));
        radio_label->setMaximumSize(QSize(210, 30));
        radio_label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 0);\n"
"font: italic 14pt \"Times New Roman\";"));
        radio_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(radio_label, 0, 0, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        track_label = new QLabel(PlaylistRadio);
        track_label->setObjectName("track_label");
        track_label->setMinimumSize(QSize(190, 30));
        track_label->setMaximumSize(QSize(190, 30));
        track_label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 255, 127);\n"
"font: italic 11pt \"Times New Roman\";"));
        track_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(track_label, 1, 1, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 1, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_play = new QPushButton(PlaylistRadio);
        Button_play->setObjectName("Button_play");
        Button_play->setMinimumSize(QSize(50, 50));
        Button_play->setMaximumSize(QSize(31, 31));
        Button_play->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/res/play.png);\n"
""));

        horizontalLayout->addWidget(Button_play);

        horizontalSpacer_3 = new QSpacerItem(42, 51, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        verticalSlider = new QSlider(PlaylistRadio);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        horizontalSpacer_8 = new QSpacerItem(42, 51, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        Button_stop = new QPushButton(PlaylistRadio);
        Button_stop->setObjectName("Button_stop");
        Button_stop->setMinimumSize(QSize(50, 50));
        Button_stop->setMaximumSize(QSize(31, 31));
        Button_stop->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/res/stop.png);"));

        horizontalLayout->addWidget(Button_stop);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 3, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(21, 263, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 4, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        comboBox_rok = new QComboBox(PlaylistRadio);
        comboBox_rok->addItem(QString());
        comboBox_rok->setObjectName("comboBox_rok");
        comboBox_rok->setMinimumSize(QSize(150, 0));
        comboBox_rok->setMaximumSize(QSize(150, 16777215));
        comboBox_rok->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"selection-color: rgb(0, 0, 127);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));

        verticalLayout->addWidget(comboBox_rok);

        comboBox_pop = new QComboBox(PlaylistRadio);
        comboBox_pop->addItem(QString());
        comboBox_pop->setObjectName("comboBox_pop");
        comboBox_pop->setMinimumSize(QSize(150, 0));
        comboBox_pop->setMaximumSize(QSize(150, 16777215));
        comboBox_pop->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));\n"
"selection-color: rgb(0, 0, 127);"));

        verticalLayout->addWidget(comboBox_pop);

        comboBox_dance = new QComboBox(PlaylistRadio);
        comboBox_dance->addItem(QString());
        comboBox_dance->setObjectName("comboBox_dance");
        comboBox_dance->setMinimumSize(QSize(150, 0));
        comboBox_dance->setMaximumSize(QSize(150, 16777215));
        comboBox_dance->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_dance->setFrame(true);

        verticalLayout->addWidget(comboBox_dance);

        comboBox_shanson = new QComboBox(PlaylistRadio);
        comboBox_shanson->addItem(QString());
        comboBox_shanson->setObjectName("comboBox_shanson");
        comboBox_shanson->setMinimumSize(QSize(150, 0));
        comboBox_shanson->setMaximumSize(QSize(150, 16777215));
        comboBox_shanson->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_shanson->setFrame(true);

        verticalLayout->addWidget(comboBox_shanson);

        comboBox_hiphop = new QComboBox(PlaylistRadio);
        comboBox_hiphop->addItem(QString());
        comboBox_hiphop->setObjectName("comboBox_hiphop");
        comboBox_hiphop->setMinimumSize(QSize(150, 0));
        comboBox_hiphop->setMaximumSize(QSize(150, 16777215));
        comboBox_hiphop->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_hiphop->setFrame(true);

        verticalLayout->addWidget(comboBox_hiphop);

        comboBox_classic = new QComboBox(PlaylistRadio);
        comboBox_classic->addItem(QString());
        comboBox_classic->setObjectName("comboBox_classic");
        comboBox_classic->setMinimumSize(QSize(150, 0));
        comboBox_classic->setMaximumSize(QSize(150, 16777215));
        comboBox_classic->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_classic->setFrame(true);

        verticalLayout->addWidget(comboBox_classic);

        comboBox_kind = new QComboBox(PlaylistRadio);
        comboBox_kind->addItem(QString());
        comboBox_kind->setObjectName("comboBox_kind");
        comboBox_kind->setMinimumSize(QSize(150, 0));
        comboBox_kind->setMaximumSize(QSize(150, 16777215));
        comboBox_kind->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_kind->setFrame(true);

        verticalLayout->addWidget(comboBox_kind);

        comboBox_humor = new QComboBox(PlaylistRadio);
        comboBox_humor->addItem(QString());
        comboBox_humor->setObjectName("comboBox_humor");
        comboBox_humor->setMinimumSize(QSize(150, 0));
        comboBox_humor->setMaximumSize(QSize(150, 16777215));
        comboBox_humor->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_humor->setFrame(true);

        verticalLayout->addWidget(comboBox_humor);

        comboBox_news = new QComboBox(PlaylistRadio);
        comboBox_news->addItem(QString());
        comboBox_news->setObjectName("comboBox_news");
        comboBox_news->setMinimumSize(QSize(150, 0));
        comboBox_news->setMaximumSize(QSize(150, 16777215));
        comboBox_news->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_news->setFrame(true);

        verticalLayout->addWidget(comboBox_news);

        comboBox_other = new QComboBox(PlaylistRadio);
        comboBox_other->addItem(QString());
        comboBox_other->setObjectName("comboBox_other");
        comboBox_other->setMinimumSize(QSize(150, 0));
        comboBox_other->setMaximumSize(QSize(150, 16777215));
        comboBox_other->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"selection-color: rgb(0, 0, 127);\n"
"selection-background-color: rgb(85, 255, 255);\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(255, 241, 118, 177), stop:1 rgba(255, 255, 255, 255));"));
        comboBox_other->setFrame(true);

        verticalLayout->addWidget(comboBox_other);


        gridLayout_2->addLayout(verticalLayout, 4, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(21, 263, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 4, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 5, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        retranslateUi(PlaylistRadio);

        QMetaObject::connectSlotsByName(PlaylistRadio);
    } // setupUi

    void retranslateUi(QWidget *PlaylistRadio)
    {
        PlaylistRadio->setWindowTitle(QCoreApplication::translate("PlaylistRadio", "Form", nullptr));
        radio_label->setText(QString());
        track_label->setText(QString());
        Button_play->setText(QString());
        Button_stop->setText(QString());
        comboBox_rok->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\240\320\276\320\272", nullptr));

        comboBox_pop->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\237\320\276\320\277", nullptr));

        comboBox_dance->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\242\320\260\320\275\321\206\320\265\320\262\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));

        comboBox_shanson->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\250\320\260\320\275\321\201\320\276\320\275", nullptr));

        comboBox_hiphop->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\240\320\265\320\277, \321\205\320\270\320\277-\321\205\320\276\320\277", nullptr));

        comboBox_classic->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\232\320\273\320\260\321\201\321\201\320\270\320\272\320\260", nullptr));

        comboBox_kind->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\224\320\265\321\202\321\201\320\272\320\276\320\265", nullptr));

        comboBox_humor->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\256\320\274\320\276\321\200", nullptr));

        comboBox_news->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\235\320\276\320\262\320\276\321\201\321\202\320\270", nullptr));

        comboBox_other->setItemText(0, QCoreApplication::translate("PlaylistRadio", "\320\224\321\200\321\203\320\263\320\276\320\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class PlaylistRadio: public Ui_PlaylistRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYLISTRADIO_H
