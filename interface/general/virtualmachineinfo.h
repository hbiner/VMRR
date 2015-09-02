#ifndef VIRTUALMACHINEINFO_H
#define VIRTUALMACHINEINFO_H

#include <QObject>

/*
 * 功能:获取虚拟机详情信息
 * 编写时间：2013-04-17
 */
class VirtualMachineInfo : public QObject
{
    Q_OBJECT
public:
    explicit VirtualMachineInfo(QObject *parent = 0);
    static  VirtualMachineInfo* getVirtualMachineInfoInstance();  //获取单例对象

    void  getVirtualMachineInfoString(QString hostName,QString vmName);  //获取指定主机下的虚拟机的详情信息
    void  sendgetVirtualMachineInfoStringSignal(QString msg);  //发送getVirtualMachineInfoStringSignal信号


signals:
    void  getVirtualMachineInfoStringSignal(QString);  //接收数据

public slots:

};

#endif // VIRTUALMACHINEINFO_H

