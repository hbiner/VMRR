#ifndef VMPOWEROPS_H
#define VMPOWEROPS_H

#include <QObject>

/*
 * 功能:完成虚拟的基本操作
 * 编写时间：2013-04-22
 * 详情功能：打开电源，关闭电源，挂起，重置，重启客户机，关闭客户机，启动客户机操作系统待机
 */
class VMPowerOps : public QObject
{
    Q_OBJECT
public:
     explicit VMPowerOps(QObject *parent = 0);
     static  VMPowerOps* getVMPowerOpsInstance();  //获取单例对象

    void  powerOnVM(QString hostName,QString vmName);// 给指定的虚拟机打开电源
    void  sendpowerOnVMSignal(QString msg);  //发送powerOnVMSignal信号

    void  powerOffVM(QString hostName, QString vmName);// 给指定的虚拟机关闭电源
    void  sendpowerOffVMSignal(QString msg);  //发送powerOffVMSignal信号

    void  resetVM(QString hostName,QString  vmName); // 复位指定的虚拟机
    void  sendresetVMSignal(QString msg);  //发送resetVMSignal信号

    void  suspendVM(QString hostName,QString vmName);// 挂起指定的虚拟机
    void  sendsuspendVMSignal(QString msg);  //发送suspendVMSignal信号

    void  rebootVM(QString hostName,QString  vmName);// 重启客户机
    void  sendrebootVMSignal(QString msg);  //发送rebootVMSignal信号

    void  shutdownVM(QString hostName,QString  vmName);// 关闭客户机
    void  sendshutdownVMSignal(QString msg);  //发送shutdownVMSignal信号

    void  standbyVM(QString hostName,QString vmName);// 启动客户机操作系统待机
    void  sendstandbyVMSignal(QString msg);  //发送standbyVMSignal信号


signals:
       void  powerOnVMSignal(QString);  //接收数据
       void  powerOffVMSignal(QString);  //接收数据
       void  resetVMSignal(QString);  //接收数据
       void  suspendVMSignal(QString);  //接收数据
       void  rebootVMSignal(QString);  //接收数据
       void  shutdownVMSignal(QString);  //接收数据
       void  standbyVMSignal(QString);  //接收数据
public slots:

};

#endif // VMPOWEROPS_H
