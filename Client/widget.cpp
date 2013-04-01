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
	connect(this->ui->btnCall1_2,SIGNAL(clicked()),this,SLOT(call1_2()));
	connect(this->ui->btnCall2,SIGNAL(clicked()),this,SLOT(call2()));
	connect(this->ui->btnReadTime,SIGNAL(clicked()),this,SLOT(readtime()));
	connect(this->ui->btnSynTime,SIGNAL(clicked()),this,SLOT(syn_time()));


	connect(this->ui->btnReadTI,SIGNAL(clicked()),this,SLOT(readti()));
	connect(this->ui->btnReadTI_all,SIGNAL(clicked()),this,SLOT(readti_all()));
	connect(this->ui->btnRCU,SIGNAL(clicked()),this,SLOT(rcu()));
	connect(this->ui->btnRLK,SIGNAL(clicked()),this,SLOT(rlk()));
	connect(this->ui->btnXL,SIGNAL(clicked()),this,SLOT(xl()));
	connect(this->ui->btnSP_2,SIGNAL(clicked()),this,SLOT(sp()));
	connect(this->ui->btnSP_TA,SIGNAL(clicked()),this,SLOT(sp_ta()));
	this->ui->lstIP->addItem ("localhost");
	this->ui->lstIP->addItem ("192.168.1.143");
	this->ui->lstIP->addItem ("192.168.1.69");
	this->ui->lstIP->addItem ("192.168.1.122");
	this->ui->lineHost->setText("192.168.1.26");
	this->ui->linPort->setText("10002");
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
/// call 1 class data ,only fcb diffence
void Widget::call1_2()
{
	this->ui->toTextEdit->setText("10 7A 01 00 7B 16");
	sendToServer();
}
// call 2 class data
void Widget::call2()
{
	this->ui->toTextEdit->setText("10 7B 01 00 7C 16");
	sendToServer();
}
//get time from rtu
void Widget::readtime()
{
	this->ui->toTextEdit->setText("68 09 09 68 \n"
				      "73 01 00 67 00 05 01 00 00 \n"
				      "E1 16");
	sendToServer();
}
//syn time
void Widget::syn_time()
{
	this->ui->toTextEdit->setText("68 10 10 68 \n"
				      "73 01 00 80 01 30 01 00 00\n"
				      "14 58 24 0F 1E 03 0D \n"
				      "E1 16");
	sendToServer();
}
//读电量
void Widget::readti()
{
	this->ui->toTextEdit->setText("68 15 15 68 53 01 00 78 01 06 01 00 0b \n"
				      "01 05 \n"
				      "1e 0e 1c 03 0d \n"
				      "1f 0e 1c 03 0d \n"
				      "57 16\n");
	sendToServer();
}
//读4class all it totle+jian feng ping gu ,rad=12 buff2(3)
void Widget::readti_all()
{
	this->ui->toTextEdit->setText("68 15 15 68 53 01 00 78 01 06 01 00 0c \n"
				      "01 16 \n"
				      "1e 0e 1c 03 0d \n"
				      "1f 0e 1c 03 0d \n"
				      "57 16");
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
//history sp
void Widget::sp()
{
	this->ui->toTextEdit->setText("68 13 13 68 53 01 00 66 02 06 01 00 33 \n"
				      "1d 0c 1d 03 0d \n"
				      "20 0c 1d 03 0d \n"
				      "9D 16 \n");
	sendToServer();
}
//single point without time range
void Widget::sp_ta()
{
	this->ui->toTextEdit->setText("68 09 09 68 53 01 00 65 00 06 01 00 33 \n"
				      "9D 16 \n");
	sendToServer();
}
