#ifndef VirtualMachineReconfigure_H
#define VirtualMachineReconfigure_H

#include <QObject>

class VirtualMachineReconfigure : public QObject
{
    Q_OBJECT
private:

public:
    explicit VirtualMachineReconfigure(QObject *parent = 0);
    static VirtualMachineReconfigure *getVirtualMachineReconfigureInstance();

    void setVirtualMachineCpuNums(QString hostName, QString vmName,int cpuNums);//对指定主机下的指定主机的cpu重配置
    void sendsetVirtualMachineCpuNumsSignal(QString msg);//对虚拟机cpu调节后的信息

    void setVirtualMachineMemorySize(QString hostName, QString vmName,long memorySizeMB);//设置虚拟机memory的大小
    void sendsetVirtualMachineMemorySizeSignal(QString msg);//返回对虚拟机内存调节后的信息

    void setVitualMachineDiskSize(QString hostName,QString vmName,int diskSizeGB,QString diskName);//设置虚拟机虚拟磁盘的大小
    void sendsetVitualMachineDiskSizeSignal(QString msg);

    void setVMCpuHotAddAndRemoveEnable(QString hostName,QString vmName);
    void sendsetVMCpuHotAddAndRemoveEnableSignal(QString msg);

    void setVMMemoryHotAddEnable(QString hostName,QString vmName);
    void sendsetVMMemoryHotAddEnableSignal(QString msg);



signals:
    void setVirtualMachineCpuNumsSignal(QString);
    void setVirtualMachineMemorySizeSignal(QString);
    void setVitualMachineDiskSizeSignal(QString);
    void setVMCpuHotAddAndRemoveEnableSignal(QString);
    void setVMMemoryHotAddEnableSignal(QString);
public slots:

};

#endif // VirtualMachineReconfigure_H
