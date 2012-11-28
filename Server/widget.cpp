#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Server");

    this->server = new QTcpServer(this);
    this->tcpsocket = new QTcpSocket(this);

    this->server->listen(QHostAddress::Any, 10005);
    connect(this->server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(this->ui->replyPushButton, SIGNAL(clicked()), this, SLOT(clickReplyButton()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::clickReplyButton()
{
    //this->tcpsocket = this->server->nextPendingConnection();
    connect(this->server, SIGNAL(newConnection()), this, SLOT(sendToClient()));
}

void Widget::acceptConnection()
{
    this->tcpsocket = this->server->nextPendingConnection();
    connect(this->tcpsocket, SIGNAL(readyRead()), this, SLOT(readFormClient()));
}

void Widget::readFormClient()
{
    QString str;
    str = this->tcpsocket->readAll();
    this->ui->fromTextEdit->setText(str);
}

void Widget::sendToClient()
{
    QString sss = this->ui->toTextEdit->toPlainText();
    if(sss != "")
    {
        string str2 = string(sss.toAscii().data());
        const char *str3 = str2.c_str();
        this->tcpsocket->write(str3);
    }
    this->ui->toTextEdit->clear();
}
