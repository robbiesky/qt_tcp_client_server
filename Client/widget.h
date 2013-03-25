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
     void call2();
      void readtime();
      void readti();
       void rcu();
	void rlk();
	void xl();
	void sp();
};

#endif // WIDGET_H
