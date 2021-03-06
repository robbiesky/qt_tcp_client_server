#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QString>
#include <QListWidgetItem>
 #include <QAbstractButton>
using namespace std;

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;

    QTcpSocket *client;
    QString readFormServerMessage;
    quint16 blockSize;

private slots:
	void clickRequestButton();
	void sendToServer();
	void readFormServer();
	void displayError(QAbstractSocket::SocketError);
	void setlocalip();
	void setip(QListWidgetItem *id);
	void call1();
	void call1_2();
	void call2();
	void readtime();
	void syn_time();
	void readti();
	void readti_all();
	void rcu();
	void rlk();
	void xl();
	void sp();
	void sp_ta();
};

#endif // WIDGET_H
