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

    //this->server->listen(QHostAddress::Any, 10005);
    connect(this->server, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
    connect(this->ui->replyPushButton, SIGNAL(clicked()), this, SLOT(clickReplyButton()));
    connect(this->ui->btnListen, SIGNAL(clicked()), this, SLOT(on_btnListen_clicked()));
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

///以二进制文本的形式打印字节流
void Widget::readFormClient()
{
    QString byt;QByteArray dat;
    dat = this->tcpsocket->readAll();
    for(int i=0;i<dat.length();i++){
	    unsigned char a ;
	    a=dat.at(i);
	    char p0[256];
	    sprintf(p0,"%02X ",a);
	    byt.append (p0);

    }
    this->ui->fromTextEdit->setText(byt);
    // this->ui->fromTextEdit->setText(str);
}
///发送到客户端
void Widget::sendToClient()
{
	int i;int len=0;
	//get host and port

	QString str = this->ui->toTextEdit->toPlainText();
	QByteArray dat;
	QStringList strlist =str.split
			(QRegExp("[\n\r\t ,_]"),QString::SkipEmptyParts);
	len=strlist.length ();
	qDebug ()<<"len of list is "<<len;
	bool bchange=false;
	//bool nouse;
	QString byt;

	for(i=0;i<len;i++){
		unsigned char a ;
		a=strlist.at (i).toUInt (&bchange,16);
		if(bchange){
			char p0[256];
			sprintf(p0,"%02X ",a);
			byt.append (p0);
			dat.append (a);
		}
	}

	this->tcpsocket->write(/*str3*/dat);
	return;
	/////
    QString sss = this->ui->toTextEdit->toPlainText();
    if(sss != "")
    {
	string str2 = string(sss.toAscii().data());
	const char *str3 = str2.c_str();
	this->tcpsocket->write(str3);
    }
    this->ui->toTextEdit->clear();
}

void Widget::on_btnListen_clicked()
{
    // this->server->listen(QHostAddress::Any, 10005);
	this->server->listen(QHostAddress::Any, this->ui->linePort->text().toInt());
	this->ui->lblStat->setText("Listening:"+this->ui->linePort->text());
}
