#ifndef VNCINFO_H
#define VNCINFO_H

#include <QObject>

class VNCInfo : public QObject
{
    Q_OBJECT
public:
    explicit VNCInfo(QObject *parent = 0);
    static VNCInfo* getVNCinfoInstance();  //获取单例对象

    void getVNCInfo(QString hostName,QString vmName);//获取指定虚拟机的VNC端口，密码
    void sendGetVNCInfoSignals(QString msg);//发送信号
signals:
        void getVNCInfoSignals(QString);//接收数据
public slots:

};

#endif // VNCINFO_H
