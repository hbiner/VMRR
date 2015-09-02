#ifndef HOSTINFO_H
#define HOSTINFO_H

#include <QObject>

/*
 * 功能：获取指定主机下的全部虚拟机和模板及其状态
 * 编写时间：2013-04-17
 */
class HostInfo : public QObject
{
    Q_OBJECT
public:
    explicit HostInfo(QObject *parent = 0);
    static  HostInfo* getHostInfoInstance();  //获取单例对象

    void  getHostInfoString(QString hostName);  //获取指定主机的详情信息
    void  sendgetHostInfoStringSignal(QString msg);  //发送getHostInfoStringSignal信号


signals:
    void  getHostInfoStringSignal(QString);  //接收数据

public slots:

};

#endif // HOSTINFO_H

