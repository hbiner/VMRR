#ifndef VIRTUALMACHINERUNTIMEINFO_H
#define VIRTUALMACHINERUNTIMEINFO_H

#include <QObject>

/*
 * 功能：获取指定主机上的指定虚拟机的运行时信息
 */
class VirtualMachineRuntimeInfo : public QObject
{
    Q_OBJECT
public:
    explicit VirtualMachineRuntimeInfo(QObject *parent = 0);
     static VirtualMachineRuntimeInfo *getVirtualMachineRuntimeInfoInstance(); //获取VirtualMachineRuntimeInfo类的单例

    void  getVirtualMachineCpuAndMemoryString(QString hostName,QString vmName); //获取指定主机下的虚拟机的cpu和memory的信息
    void  sendgetVirtualMachineCpuAndMemoryStringSignal(QString msg);//发送getVirtualMachineCpuAndMemoryStringSignal信号

    void  getVirtualMachineDiskString(QString hostName, QString vmName);//获取指定主机下的虚拟机的磁盘信息
    void  sendgetVirtualMachineDiskStringSignal(QString msg); //发送getVirtualMachineCpuAndMemoryStringSignal信号



signals:
    void  getVirtualMachineCpuAndMemoryStringSignal(QString);  //接收获取到的cpu和memory信息
    void  getVirtualMachineDiskStringSignal(QString); //接收获取到的memory信息

public slots:

};

#endif // VIRTUALMACHINERUNTIMEINFO_H
