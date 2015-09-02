#ifndef VMOTION_H
#define VMOTION_H

#include <QObject>

/*
 * 功能:完成虚拟的迁移和重定向
 * 编写时间：2013-04-24
 */
class VMotion : public QObject
{
    Q_OBJECT
public:
    explicit VMotion(QObject *parent = 0);
    static  VMotion* getVMotionInstance();  //获取单例对象

    void  migrateVM(QString vmname, QString tcluster,QString tHost, QString srcHost, QString priority); // 对虚拟机进行迁移操作
    void  sendmigrateVMSignal(QString msg);  //发送migrateVMSignal信号

    void  relocateVMOnSameHost(QString vmname,QString  tcluster,QString tDS, QString srcHost,QString  priority);// 对虚拟机在同一主机内进行重定位操作
    void  sendrelocateVMOnSameHostSignal(QString msg);  //发送relocateVMOnSameHostSignal信号

    void  relocateVMOnDifferentHost(QString vmname,QString  tcluster,QString tHost,QString  tDS,QString  srcHost,QString  priority);// 对虚拟机在不同主机内进行重定位操作
    void  sendrelocateVMOnDifferentHostSignal(QString msg);  //发送relocateVMOnDifferentHostSignal信号

signals:
   void  migrateVMSignal(QString);  //接收数据
   void  relocateVMOnSameHostSignal(QString);  //接收数据
   void  relocateVMOnDifferentHostSignal(QString);  //接收数据



public slots:

};

#endif // VMOTION_H
