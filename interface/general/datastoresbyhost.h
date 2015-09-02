#ifndef DATASTORESBYHOST_H
#define DATASTORESBYHOST_H

#include <QObject>

/*
 * 功能：获取指定主机所可以使用的全部存储器
 * 编写时间：2013-04-23
 */

class DatastoresByHost : public QObject
{
    Q_OBJECT
public:
    explicit DatastoresByHost(QObject *parent = 0);
    static  DatastoresByHost* getDatastoresByHostInstance();  //获取单例对象

    void  getDataStores(QString hostName);  //获取指定主机下的全部的存储器
    void  sendgetDataStoresSignal(QString msg);  //发送getDataStoresSignal信号

    void getDatastoreSubForder(QString hostName);//显示存储器的下一级文件夹
    void  sendgetDataStoresSubForderSignal(QString msg);  //发送获取存储器的下一级文件夹信号


signals:
    void  getDataStoresSignal(QString);  //接收数据
    void getDatastoreSubForderSignal(QString);  //接收数据

public slots:

};

#endif // DATASTORESBYHOST_H
