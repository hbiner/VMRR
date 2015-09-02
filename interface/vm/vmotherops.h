#ifndef VMOTHEROPS_H
#define VMOTHEROPS_H

#include <QObject>

/*
 * 功能:完成虚拟机的一些额外的操作
 * 编写时间：2013-04-22
 * 详情功能:重命名,删除,移除(从清单中)
 */
class VMOtherOps : public QObject
{
    Q_OBJECT
public:
    explicit VMOtherOps(QObject *parent = 0);
    static  VMOtherOps* getVMOtherOpsInstance();  //获取单例对象

    void  destroyVm(QString hostName,QString  vmName);//删除虚拟机
    void  senddestroyVmSignal(QString msg);  //发送destroyVmSignal信号

    void  unregisterVm(QString hostName,QString vmName);//从清单中移除虚拟机
    void  sendunregisterVmSignal(QString msg);  //发送unregisterVmSignal信号

    void  renameVm(QString hostName,QString vmName, QString newVmName);//虚拟机重命名
    void  sendrenameVmSignal(QString msg);  //发送renameVmSignal信号


signals:
    void  destroyVmSignal(QString);  //接收数据
    void  unregisterVmSignal(QString);  //接收数据
    void  renameVmSignal(QString);  //接收数据



public slots:

};

#endif // VMOTHEROPS_H
