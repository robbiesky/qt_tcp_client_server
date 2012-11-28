/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *errorLabel;
    QLineEdit *lineHost;
    QLineEdit *linPort;
    QPushButton *requestPushButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnLocal;
    QListWidget *lstIP;
    QTextEdit *txtHasSend;
    QLabel *label_3;
    QTextEdit *txtStatus;
    QLabel *fromLabel;
    QTextEdit *fromTextEdit;
    QLabel *toLabel;
    QTextEdit *toTextEdit;
    QPushButton *btnCall1;
    QPushButton *btnCall2;
    QPushButton *btnRLK;
    QLabel *label_6;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *btnRCU;
    QLabel *label_4;
    QPushButton *btnReadTI;
    QLabel *label_5;
    QPushButton *btnXL;
    QPushButton *btnReadTime;
    QLabel *label_7;
    QLabel *label_12;
    QLabel *label_13;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(901, 567);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/titli.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        errorLabel = new QLabel(Widget);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(250, 440, 251, 20));
        lineHost = new QLineEdit(Widget);
        lineHost->setObjectName(QString::fromUtf8("lineHost"));
        lineHost->setGeometry(QRect(510, 40, 181, 28));
        linPort = new QLineEdit(Widget);
        linPort->setObjectName(QString::fromUtf8("linPort"));
        linPort->setGeometry(QRect(710, 40, 129, 28));
        requestPushButton = new QPushButton(Widget);
        requestPushButton->setObjectName(QString::fromUtf8("requestPushButton"));
        requestPushButton->setGeometry(QRect(370, 370, 128, 28));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(520, 20, 21, 18));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(710, 10, 31, 18));
        btnLocal = new QPushButton(Widget);
        btnLocal->setObjectName(QString::fromUtf8("btnLocal"));
        btnLocal->setGeometry(QRect(710, 90, 81, 28));
        lstIP = new QListWidget(Widget);
        lstIP->setObjectName(QString::fromUtf8("lstIP"));
        lstIP->setGeometry(QRect(510, 90, 181, 111));
        txtHasSend = new QTextEdit(Widget);
        txtHasSend->setObjectName(QString::fromUtf8("txtHasSend"));
        txtHasSend->setEnabled(true);
        txtHasSend->setGeometry(QRect(80, 10, 421, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\346\255\243\351\273\221"));
        font.setBold(true);
        font.setWeight(75);
        txtHasSend->setFont(font);
        txtHasSend->setReadOnly(true);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setEnabled(true);
        label_3->setGeometry(QRect(30, 10, 31, 18));
        txtStatus = new QTextEdit(Widget);
        txtStatus->setObjectName(QString::fromUtf8("txtStatus"));
        txtStatus->setGeometry(QRect(80, 470, 421, 91));
        txtStatus->setReadOnly(true);
        fromLabel = new QLabel(Widget);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));
        fromLabel->setGeometry(QRect(30, 80, 41, 18));
        fromTextEdit = new QTextEdit(Widget);
        fromTextEdit->setObjectName(QString::fromUtf8("fromTextEdit"));
        fromTextEdit->setGeometry(QRect(80, 80, 421, 181));
        fromTextEdit->setFont(font);
        fromTextEdit->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
        toLabel = new QLabel(Widget);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));
        toLabel->setGeometry(QRect(10, 290, 61, 18));
        toTextEdit = new QTextEdit(Widget);
        toTextEdit->setObjectName(QString::fromUtf8("toTextEdit"));
        toTextEdit->setGeometry(QRect(80, 280, 421, 81));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\346\255\243\351\273\221"));
        toTextEdit->setFont(font1);
        toTextEdit->setHtml(QString::fromUtf8("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\346\226\207\346\263\211\351\251\277\347\255\211\345\256\275\346\255\243\351\273\221'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'\345\256\213\344\275\223'; font-size:9pt;\"><br /></p></body></html>"));
        toTextEdit->setAcceptRichText(false);
        btnCall1 = new QPushButton(Widget);
        btnCall1->setObjectName(QString::fromUtf8("btnCall1"));
        btnCall1->setGeometry(QRect(630, 470, 98, 30));
        btnCall2 = new QPushButton(Widget);
        btnCall2->setObjectName(QString::fromUtf8("btnCall2"));
        btnCall2->setGeometry(QRect(630, 510, 98, 30));
        btnRLK = new QPushButton(Widget);
        btnRLK->setObjectName(QString::fromUtf8("btnRLK"));
        btnRLK->setGeometry(QRect(630, 430, 98, 30));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(530, 430, 41, 41));
        QFont font2;
        font2.setPointSize(25);
        label_6->setFont(font2);
        label_8 = new QLabel(Widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(590, 430, 16, 20));
        label_9 = new QLabel(Widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(590, 480, 16, 20));
        label_10 = new QLabel(Widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(590, 520, 16, 20));
        label_11 = new QLabel(Widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 470, 64, 20));
        btnRCU = new QPushButton(Widget);
        btnRCU->setObjectName(QString::fromUtf8("btnRCU"));
        btnRCU->setGeometry(QRect(620, 240, 98, 30));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(590, 240, 16, 20));
        btnReadTI = new QPushButton(Widget);
        btnReadTI->setObjectName(QString::fromUtf8("btnReadTI"));
        btnReadTI->setGeometry(QRect(620, 340, 98, 30));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(590, 300, 16, 20));
        btnXL = new QPushButton(Widget);
        btnXL->setObjectName(QString::fromUtf8("btnXL"));
        btnXL->setGeometry(QRect(730, 300, 98, 30));
        btnReadTime = new QPushButton(Widget);
        btnReadTime->setObjectName(QString::fromUtf8("btnReadTime"));
        btnReadTime->setGeometry(QRect(620, 300, 98, 30));
        label_7 = new QLabel(Widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(530, 230, 41, 41));
        label_7->setFont(font2);
        label_12 = new QLabel(Widget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(730, 430, 71, 20));
        label_13 = new QLabel(Widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(720, 240, 71, 20));

        retranslateUi(Widget);

        lstIP->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Client", 0, QApplication::UnicodeUTF8));
        errorLabel->setText(QString());
        lineHost->setText(QApplication::translate("Widget", "192.168.1.189", 0, QApplication::UnicodeUTF8));
        linPort->setText(QApplication::translate("Widget", "10005", 0, QApplication::UnicodeUTF8));
        requestPushButton->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "IP", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "Port", 0, QApplication::UnicodeUTF8));
        btnLocal->setText(QApplication::translate("Widget", "\350\256\276\347\275\256IP", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\345\217\221\351\200\201", 0, QApplication::UnicodeUTF8));
        fromLabel->setText(QApplication::translate("Widget", "\346\216\245\346\224\266", 0, QApplication::UnicodeUTF8));
        toLabel->setText(QApplication::translate("Widget", "\347\274\226\350\257\221\346\212\245\346\226\207", 0, QApplication::UnicodeUTF8));
        btnCall1->setText(QApplication::translate("Widget", "\345\217\254\345\224\2441\347\272\247\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        btnCall2->setText(QApplication::translate("Widget", "\345\217\254\345\224\2442\347\272\247\346\225\260\346\215\256", 0, QApplication::UnicodeUTF8));
        btnRLK->setText(QApplication::translate("Widget", "\345\217\254\345\224\244\351\223\276\350\267\257\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "S3", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "9", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget", "10", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget", "11", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Widget", "\351\224\231\350\257\257\347\212\266\346\200\201:", 0, QApplication::UnicodeUTF8));
        btnRCU->setText(QApplication::translate("Widget", "\345\244\215\344\275\215\351\223\276\350\267\257", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8));
        btnReadTI->setText(QApplication::translate("Widget", "\350\257\273\347\224\265\351\207\217", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "3", 0, QApplication::UnicodeUTF8));
        btnXL->setText(QApplication::translate("Widget", "\350\257\273\351\234\200\351\207\217", 0, QApplication::UnicodeUTF8));
        btnReadTime->setText(QApplication::translate("Widget", "\350\257\273\345\217\226\346\227\266\351\227\264", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "S2", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Widget", "(FCV\346\227\240\346\225\210)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Widget", "(FCV\346\227\240\346\225\210)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
