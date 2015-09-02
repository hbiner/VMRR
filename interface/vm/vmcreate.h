#ifndef VMCREATE_H
#define VMCREATE_H

#include <QObject>

/*
 * 功能:完成虚拟的创建
 * 编写时间：2013-04-22
 */
class VMCreate : public QObject
{
    Q_OBJECT
public:
    explicit VMCreate(QObject *parent = 0);
    static  VMCreate* getVMCreateInstance();  //获取单例对象

    void  createVirtualMachine(QString hostname,QString vmName, QString guestOsId,
                                                 QString numCpus,QString  diskSize,QString vmMemorySize,
                                                 QString numNics,QString dataStore,QString iso,
                                                 QString  startVM);     //创建虚拟机
    void  sendcreateVirtualMachineSignal(QString msg);  //发送createVirtualMachineSignal信号


signals:
      void  createVirtualMachineSignal(QString);  //接收数据


public slots:

};

#endif // VMCREATE_H
