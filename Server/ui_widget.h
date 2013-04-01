/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 4.8.4
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
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *errorLabel;
    QPushButton *btnListen;
    QLineEdit *linePort;
    QLabel *label_2;
    QLabel *fromLabel;
    QLabel *lblStat;
    QLabel *toLabel;
    QTextEdit *toTextEdit;
    QPushButton *replyPushButton;
    QTextEdit *fromTextEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(655, 508);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/titli.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        errorLabel = new QLabel(Widget);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(10, 527, 16, 17));
        btnListen = new QPushButton(Widget);
        btnListen->setObjectName(QString::fromUtf8("btnListen"));
        btnListen->setGeometry(QRect(480, 69, 80, 28));
        linePort = new QLineEdit(Widget);
        linePort->setObjectName(QString::fromUtf8("linePort"));
        linePort->setGeometry(QRect(480, 36, 127, 27));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(480, 13, 79, 17));
        fromLabel = new QLabel(Widget);
        fromLabel->setObjectName(QString::fromUtf8("fromLabel"));
        fromLabel->setGeometry(QRect(12, 13, 71, 17));
        lblStat = new QLabel(Widget);
        lblStat->setObjectName(QString::fromUtf8("lblStat"));
        lblStat->setGeometry(QRect(479, 104, 53, 17));
        toLabel = new QLabel(Widget);
        toLabel->setObjectName(QString::fromUtf8("toLabel"));
        toLabel->setGeometry(QRect(20, 190, 54, 17));
        toTextEdit = new QTextEdit(Widget);
        toTextEdit->setObjectName(QString::fromUtf8("toTextEdit"));
        toTextEdit->setGeometry(QRect(10, 210, 441, 131));
        replyPushButton = new QPushButton(Widget);
        replyPushButton->setObjectName(QString::fromUtf8("replyPushButton"));
        replyPushButton->setGeometry(QRect(154, 370, 80, 28));
        fromTextEdit = new QTextEdit(Widget);
        fromTextEdit->setObjectName(QString::fromUtf8("fromTextEdit"));
        fromTextEdit->setGeometry(QRect(12, 39, 441, 141));
        fromTextEdit->setUndoRedoEnabled(false);
        fromTextEdit->setReadOnly(false);
        fromTextEdit->setTextInteractionFlags(Qt::TextEditorInteraction);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250,\347\233\221\345\220\254,\347\255\211\345\276\205\345\256\242\346\210\267\347\253\257\351\223\276\346\216\245", 0, QApplication::UnicodeUTF8));
        errorLabel->setText(QString());
        btnListen->setText(QApplication::translate("Widget", "\347\233\221\345\220\254", 0, QApplication::UnicodeUTF8));
        linePort->setText(QApplication::translate("Widget", "10009", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\345\274\200\346\224\276\347\232\204\347\253\257\345\217\243\345\217\267", 0, QApplication::UnicodeUTF8));
        fromLabel->setText(QApplication::translate("Widget", "Form Client:", 0, QApplication::UnicodeUTF8));
        lblStat->setText(QApplication::translate("Widget", "\346\262\241\346\234\211\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
        toLabel->setText(QApplication::translate("Widget", "To Client:", 0, QApplication::UnicodeUTF8));
        replyPushButton->setText(QApplication::translate("Widget", "Reply", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
