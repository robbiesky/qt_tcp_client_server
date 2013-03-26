#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include <QString>
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

    QTcpServer *server;
    QTcpSocket *tcpsocket;
    QString readFormClientMessage;
    quint16 blockSize;

private slots:
    void clickReplyButton();
    void readFormClient();
    void sendToClient();
    void acceptConnection();
    void on_btnListen_clicked();
};

#endif // WIDGET_H
