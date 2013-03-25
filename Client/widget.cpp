#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	ui->setupUi(this);

	this->setWindowTitle("Client");

	this->client = new QTcpSocket(this);

	//client->bytesAvailable();
	connect(this->ui->requestPushButton, SIGNAL(clicked()), this,	SLOT(clickRequestButton()));
	connect(this->client, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
	connect(this->client, SIGNAL(readyRead()), this, SLOT(readFormServer()));
	connect(this->ui->btnLocal,SIGNAL(clicked()),this,SLOT(setlocalip()));
	connect(this->ui->lstIP,SIGNAL(itemActivated(QListWidgetItem*)),this,SLOT(setip(QListWidgetItem*)));
	//快捷指令
	connect(this->ui->btnCall1,SIGNAL(clicked()),this,SLOT(call1()));
	connect(this->ui->btnCall2,SIGNAL(clicked()),this,SLOT(call2()));
	connect(this->ui->btnReadTime,SIGNAL(clicked()),this,SLOT(readtime()));
	connect(this->ui->btnReadTI,SIGNAL(clicked()),this,SLOT(readti()));
	connect(this->ui->btnRCU,SIGNAL(clicked()),this,SLOT(rcu()));
	connect(this->ui->btnRLK,SIGNAL(clicked()),this,SLOT(rlk()));
	connect(this->ui->btnXL,SIGNAL(clicked()),this,SLOT(xl()));
	connect(this->ui->btnSP_2,SIGNAL(clicked()),this,SLOT(sp()));
	this->ui->lstIP->addItem ("localhost");
	this->ui->lstIP->addItem ("192.168.1.143");
	this->ui->lineHost->setText("192.168.1.143");
	this->ui->linPort->setText("10001");
	this->ui->lstIP->setCurrentRow (1);
	this->ui->toTextEdit->setText("10 49 01 00 4A 16");
}

Widget::~Widget()
{
	delete ui;
}

void Widget::clickRequestButton()
{
	sendToServer();
}

void Widget::sendToServer()
{
	this->client->abort();
	char errmsg[1024];
	int i;int len=0;
	//get host and port
	QString ip = this->ui->lineHost->text();
	int port =this->ui->linPort->text ().toInt ();
	this->ui->errorLabel->clear();
	this->client->connectToHost(ip, port);
	ui->txtHasSend->clear ();
	QString str = this->ui->toTextEdit->toPlainText();
	QByteArray dat;
	int ret;
	this->ui->fromTextEdit->clear();
	QStringList strlist =str.split
			(QRegExp("[\n\r\t ,_]"),QString::SkipEmptyParts);
	len=strlist.length ();
	qDebug ()<<"len of list is "<<len;
	bool bchange=false;
	//bool nouse;
	QString byt;

	this->ui->txtStatus->clear ();
	for(i=0;i<len;i++){
		unsigned char a ;
		a=strlist.at (i).toUInt (&bchange,16);
		if(bchange){
			char p0[256];
			sprintf(p0,"%02X ",a);
			byt.append (p0);
			dat.append (a);
		}else{
			//qDebug ("change err");
			sprintf(errmsg,"change err,no [%d] \"%s\" is not hex"
				,i+1,strlist.at (i).toLocal8Bit ().data ());
			this->ui->txtStatus->append (errmsg);
		}
	}
	//show sended dat
	if(ui->rbtSend->isChecked()){
		ui->txtHasSend->append (byt);

		ret=this->client->write(/*str3*/dat);
		if (ret==-1){
			sprintf(errmsg,"send ret = %d ",ret);
			this->ui->txtStatus->append(errmsg);
			//this->ui->txtStatus->setTextColor("red");
		}
	}

}
//读取数据
void Widget::readFormServer()
{
	int i;
	this->ui->fromTextEdit->clear();
	QString str5;QString byt;
	//	QEventLoop eventloop;
	//	QTimer::singleShot(500, &eventloop, SLOT(quit()));
	//	eventloop.exec();
	//	int buf=this->client->readBufferSize();
	//str5 = this->client->readAll();
	QByteArray dat;
	dat=this->client->readAll();
	for(i=0;i<dat.length();i++){
		unsigned char a ;
		a=dat.at(i);
		char p0[256];
		sprintf(p0,"%02X ",a);
		byt.append (p0);

	}
	this->ui->fromTextEdit->setText(byt);
}

void Widget::displayError(QAbstractSocket::SocketError)
{
	//this->ui->errorLabel->setText(this->client->errorString());
	this->ui->txtStatus->append(this->client->errorString());
}
void Widget::setlocalip ()
{
	this->ui->lineHost->text ().clear ();
	this->ui->lineHost->setText(this->ui->lstIP->selectedItems ().first ()->text ());
}
void Widget::setip(QListWidgetItem* id)
{
	this->ui->lineHost->text ().clear ();
	this->ui->lineHost->setText(id->text ());
}
/// call 1 class data
void Widget::call1()
{
	this->ui->toTextEdit->setText("10 5A 01 00 5B 16");
	sendToServer();
}
// call 2 class data
void Widget::call2()
{
	this->ui->toTextEdit->setText("10 7B 01 00 7C 16");
	sendToServer();
}
void Widget::readtime()
{
	this->ui->toTextEdit->setText("68 09 09 68 73 01 00 67 00 05 01 00 00 E1 16");
	sendToServer();
}
//读电量
void Widget::readti()
{
	this->ui->toTextEdit->setText("68 15 15 68 "
				      "53 01 00 78 01 06 01 00 1F 01 10 "
				      "00 00 01 0b 0c "
				      "00 01 01 0b 0c "
				      "67 16");
	sendToServer();
}
void Widget::rcu()
{
	this->ui->toTextEdit->setText("10 40 01 00 41 16");
	sendToServer();
}
void Widget::rlk()
{
	this->ui->toTextEdit->setText("10 49 01 00 4A 16 ");
	sendToServer();
}
void Widget::xl()
{
	this->ui->toTextEdit->setText("68 15 15 68 53 01 00 AE 01 06 01 00 1F 2C 2F 00 00 01 07 04 00 01 01 07 04 9D 16 ");
	sendToServer();
}
void Widget::sp()
{
	this->ui->toTextEdit->setText("68 13 13 68 53 01 00 66 02 06 01 00 33 \n"
				      "00 00 05 0c 0c \n"
				      "3b 17 05 0c 0c \n"
				      "9D 16 \n");
	sendToServer();
}
