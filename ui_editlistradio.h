/********************************************************************************
** Form generated from reading UI file 'editlistradio.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITLISTRADIO_H
#define UI_EDITLISTRADIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditlistRadio
{
public:
    QGridLayout *gridLayout_6;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *return_pushButton;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_3;
    QLabel *add_label;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_11;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *add_url_lineEdit_2;
    QLineEdit *add_url_lineEdit;
    QPushButton *add_pushButton;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *del_label;
    QSpacerItem *horizontalSpacer_9;
    QComboBox *del_comboBox;
    QPushButton *del_pushButton;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_7;
    QGridLayout *gridLayout;
    QLabel *Category_label;
    QComboBox *Category_comboBox;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *EditlistRadio)
    {
        if (EditlistRadio->objectName().isEmpty())
            EditlistRadio->setObjectName("EditlistRadio");
        EditlistRadio->setWindowModality(Qt::ApplicationModal);
        EditlistRadio->resize(600, 300);
        EditlistRadio->setMinimumSize(QSize(600, 300));
        EditlistRadio->setMaximumSize(QSize(600, 300));
        EditlistRadio->setStyleSheet(QString::fromUtf8(""));
        gridLayout_6 = new QGridLayout(EditlistRadio);
        gridLayout_6->setObjectName("gridLayout_6");
        verticalSpacer_4 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_4, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_5 = new QSpacerItem(188, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        return_pushButton = new QPushButton(EditlistRadio);
        return_pushButton->setObjectName("return_pushButton");
        return_pushButton->setMinimumSize(QSize(80, 25));
        return_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/res/back.png);"));

        horizontalLayout_3->addWidget(return_pushButton);

        horizontalSpacer_6 = new QSpacerItem(208, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        gridLayout_5->addLayout(horizontalLayout_3, 5, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        add_label = new QLabel(EditlistRadio);
        add_label->setObjectName("add_label");
        add_label->setMinimumSize(QSize(170, 20));
        add_label->setMaximumSize(QSize(170, 20));
        add_label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(85, 255, 0);\n"
"font: 700 italic 14pt \"Times New Roman\";"));

        gridLayout_3->addWidget(add_label, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(175, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 0, 2, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(165, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_11, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName("gridLayout_4");
        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        label_2 = new QLabel(EditlistRadio);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Times New Roman\";\n"
"color: rgb(255, 255, 0);"));

        gridLayout_4->addWidget(label_2, 0, 3, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        add_url_lineEdit_2 = new QLineEdit(EditlistRadio);
        add_url_lineEdit_2->setObjectName("add_url_lineEdit_2");
        add_url_lineEdit_2->setMinimumSize(QSize(150, 25));
        add_url_lineEdit_2->setMaximumSize(QSize(150, 25));
        add_url_lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(add_url_lineEdit_2);

        add_url_lineEdit = new QLineEdit(EditlistRadio);
        add_url_lineEdit->setObjectName("add_url_lineEdit");
        add_url_lineEdit->setMinimumSize(QSize(300, 25));
        add_url_lineEdit->setMaximumSize(QSize(300, 25));
        add_url_lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"background-color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(add_url_lineEdit);

        add_pushButton = new QPushButton(EditlistRadio);
        add_pushButton->setObjectName("add_pushButton");
        add_pushButton->setMinimumSize(QSize(25, 25));
        add_pushButton->setMaximumSize(QSize(25, 25));
        add_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/res/add.png);"));

        horizontalLayout_2->addWidget(add_pushButton);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 5);

        label = new QLabel(EditlistRadio);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 700 italic 14pt \"Times New Roman\";\n"
"color: rgb(255, 255, 0);"));

        gridLayout_4->addWidget(label, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        gridLayout_5->addLayout(verticalLayout, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        verticalSpacer = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        horizontalLayout_4->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        del_label = new QLabel(EditlistRadio);
        del_label->setObjectName("del_label");
        del_label->setMinimumSize(QSize(135, 20));
        del_label->setMaximumSize(QSize(100, 20));
        del_label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(85, 255, 0);\n"
"font: 700 italic 14pt \"Times New Roman\";"));

        horizontalLayout->addWidget(del_label);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_9);

        del_comboBox = new QComboBox(EditlistRadio);
        del_comboBox->setObjectName("del_comboBox");
        del_comboBox->setMinimumSize(QSize(200, 25));
        del_comboBox->setMaximumSize(QSize(200, 25));
        del_comboBox->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 255, 0);\n"
"font: 700 italic 12pt \"Times New Roman\";\n"
"background-color: rgb(85, 0, 255);\n"
"color: rgb(255, 255, 0);\n"
"selection-color: rgb(0, 0, 255);"));

        horizontalLayout->addWidget(del_comboBox);

        del_pushButton = new QPushButton(EditlistRadio);
        del_pushButton->setObjectName("del_pushButton");
        del_pushButton->setMinimumSize(QSize(25, 25));
        del_pushButton->setMaximumSize(QSize(25, 25));
        del_pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"border-image: url(:/res/del.png);"));

        horizontalLayout->addWidget(del_pushButton);


        horizontalLayout_4->addLayout(horizontalLayout);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);


        gridLayout_5->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(17, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 2, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalSpacer_7 = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        Category_label = new QLabel(EditlistRadio);
        Category_label->setObjectName("Category_label");
        Category_label->setMinimumSize(QSize(170, 25));
        Category_label->setMaximumSize(QSize(170, 25));
        Category_label->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(0, 255, 0);\n"
"font: 700 italic 14pt \"Times New Roman\";"));
        Category_label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(Category_label, 1, 0, 1, 1);

        Category_comboBox = new QComboBox(EditlistRadio);
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->addItem(QString());
        Category_comboBox->setObjectName("Category_comboBox");
        Category_comboBox->setMinimumSize(QSize(170, 25));
        Category_comboBox->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 255, 0);\n"
"font: 700 italic 12pt \"Times New Roman\";\n"
"background-color: rgb(85, 0, 255);\n"
"color: rgb(255, 255, 0);\n"
"selection-color: rgb(0, 0, 255);"));

        gridLayout->addWidget(Category_comboBox, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(178, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 2, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_5->addItem(verticalSpacer_6, 4, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_6->addItem(verticalSpacer_3, 2, 1, 1, 1);


        retranslateUi(EditlistRadio);

        QMetaObject::connectSlotsByName(EditlistRadio);
    } // setupUi

    void retranslateUi(QWidget *EditlistRadio)
    {
        EditlistRadio->setWindowTitle(QCoreApplication::translate("EditlistRadio", "Form", nullptr));
        return_pushButton->setText(QString());
        add_label->setText(QCoreApplication::translate("EditlistRadio", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\260\320\264\320\270\320\276", nullptr));
        label_2->setText(QCoreApplication::translate("EditlistRadio", "URL \321\200\320\260\320\264\320\270\320\276", nullptr));
        add_pushButton->setText(QString());
        label->setText(QCoreApplication::translate("EditlistRadio", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        del_label->setText(QCoreApplication::translate("EditlistRadio", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\200\320\260\320\264\320\270\320\276", nullptr));
        del_pushButton->setText(QString());
        Category_label->setText(QCoreApplication::translate("EditlistRadio", "\320\223\321\200\321\203\320\277\320\277\320\260 \321\200\320\260\320\264\320\270\320\276:", nullptr));
        Category_comboBox->setItemText(0, QString());
        Category_comboBox->setItemText(1, QCoreApplication::translate("EditlistRadio", "\320\240\320\276\320\272", nullptr));
        Category_comboBox->setItemText(2, QCoreApplication::translate("EditlistRadio", "\320\237\320\276\320\277", nullptr));
        Category_comboBox->setItemText(3, QCoreApplication::translate("EditlistRadio", "\320\242\320\260\320\275\321\206\320\265\320\262\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        Category_comboBox->setItemText(4, QCoreApplication::translate("EditlistRadio", "\320\250\320\260\320\275\321\201\320\276\320\275", nullptr));
        Category_comboBox->setItemText(5, QCoreApplication::translate("EditlistRadio", "\320\240\320\265\320\277, \321\205\320\270\320\277-\321\205\320\276\320\277", nullptr));
        Category_comboBox->setItemText(6, QCoreApplication::translate("EditlistRadio", "\320\232\320\273\320\260\321\201\321\201\320\270\320\272\320\260", nullptr));
        Category_comboBox->setItemText(7, QCoreApplication::translate("EditlistRadio", "\320\224\320\265\321\202\321\201\320\272\320\276\320\265", nullptr));
        Category_comboBox->setItemText(8, QCoreApplication::translate("EditlistRadio", "\320\256\320\274\320\276\321\200", nullptr));
        Category_comboBox->setItemText(9, QCoreApplication::translate("EditlistRadio", "\320\235\320\276\320\262\320\276\321\201\321\202\320\270", nullptr));
        Category_comboBox->setItemText(10, QCoreApplication::translate("EditlistRadio", "\320\224\321\200\321\203\320\263\320\276\320\265", nullptr));

    } // retranslateUi

};

namespace Ui {
    class EditlistRadio: public Ui_EditlistRadio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITLISTRADIO_H
