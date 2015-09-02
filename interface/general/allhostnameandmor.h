#ifndef ALLHOSTNAMEANDMOR_H
#define ALLHOSTNAMEANDMOR_H

#include <QObject>

/*
 * 功能：获取指定vCenter Server 中的所有物理主机的名称
 * 编写时间：2013-04-15
 */

class AllHostNameAndMOR : public QObject
{
    Q_OBJECT

public:
    explicit AllHostNameAndMOR(QObject *parent = 0);
    static  AllHostNameAndMOR* getAllHostNameAndMORInstance();  //获取单例对象

    void  getAllHostNameString();  //获取全部主机的名称
    void  sendgetAllHostNameStringSignal(QString msg);  //发送getAllHostNameStringSignal信号



private:


signals:
    void getAllHostNameStringSignal(QString);  //接收数据

public slots:

};

#endif // ALLHOSTNAMEANDMOR_H


