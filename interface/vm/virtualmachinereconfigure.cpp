#include "virtualmachinereconfigure.h"
#include "controller/MessageType.h"
#include "controller/messagethread.h"

VirtualMachineReconfigure::VirtualMachineReconfigure(QObject *parent) :
    QObject(parent)
{
}

//对指定主机下的指定主机的cpu重配置
void VirtualMachineReconfigure::setVirtualMachineCpuNums(QString hostName, QString vmName,int cpuNums)
{
    QString str = QString::number(MessageType::VirtualMachineCpuReconfig)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        + QString::number(cpuNums)+MessageThread::getMessageThreadInstance()->getReqParSplit() ;

    MessageThread::getMessageThreadInstance()->sendData(str);
}

//对虚拟机cpu调节后的信息
void VirtualMachineReconfigure::sendsetVirtualMachineCpuNumsSignal(QString msg)
{
    emit setVirtualMachineCpuNumsSignal(msg);
}

//设置虚拟机memory的大小
void VirtualMachineReconfigure::setVirtualMachineMemorySize(QString hostName, QString vmName, long memorySizeMB)
{
    QString str = QString::number(MessageType::VirtualMachineMemoryReconfig)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        + QString::number(memorySizeMB)+MessageThread::getMessageThreadInstance()->getReqParSplit() ;

    MessageThread::getMessageThreadInstance()->sendData(str);
}

//返回对虚拟机内存调节后的信息
void VirtualMachineReconfigure::sendsetVirtualMachineMemorySizeSignal(QString msg)
{
    emit setVirtualMachineMemorySizeSignal(msg);
}

//设置虚拟机虚拟磁盘的大小
void VirtualMachineReconfigure::setVitualMachineDiskSize(QString hostName, QString vmName, int diskSizeGB, QString diskName)
{
    QString str = QString::number(MessageType::VirtualMachineDiskReconfig)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        + QString::number(diskSizeGB)+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        + diskName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;

    MessageThread::getMessageThreadInstance()->sendData(str);
}

void VirtualMachineReconfigure::sendsetVitualMachineDiskSizeSignal(QString msg)
{
    emit setVitualMachineDiskSizeSignal(msg);
}

//启用虚拟机cpu的热插拔
void VirtualMachineReconfigure::setVMCpuHotAddAndRemoveEnable(QString hostName, QString vmName)
{
    QString str = QString::number(MessageType::VirtualMachineCpuHotAddAndRemoveEnable)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;

    MessageThread::getMessageThreadInstance()->sendData(str);
}

void VirtualMachineReconfigure::sendsetVMCpuHotAddAndRemoveEnableSignal(QString msg)
{
    emit setVMCpuHotAddAndRemoveEnableSignal(msg);
}

//启用虚拟机memory的热增加
void VirtualMachineReconfigure::setVMMemoryHotAddEnable(QString hostName, QString vmName)
{
    QString str = QString::number(MessageType::VirtualMachineMemoryHotAddEnable)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;

    MessageThread::getMessageThreadInstance()->sendData(str);
}


void VirtualMachineReconfigure::sendsetVMMemoryHotAddEnableSignal(QString msg)
{
    emit setVMMemoryHotAddEnableSignal(msg);
}

static VirtualMachineReconfigure *virtualMachineReconfigure;

VirtualMachineReconfigure * VirtualMachineReconfigure::getVirtualMachineReconfigureInstance()
{
    if(virtualMachineReconfigure == NULL){
        virtualMachineReconfigure = new VirtualMachineReconfigure();
    }
    return virtualMachineReconfigure;
}
