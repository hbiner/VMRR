#include "virtualmachineruntimeinfo.h"
#include "controller/messagethread.h"
#include "controller/MessageType.h"

VirtualMachineRuntimeInfo::VirtualMachineRuntimeInfo(QObject *parent) :
    QObject(parent)
{

}

//获取指定主机下的虚拟机的cpu和memory的信息
void VirtualMachineRuntimeInfo::getVirtualMachineCpuAndMemoryString(QString hostName, QString vmName)
{
    QString str = QString::number(MessageType::GetVirtualMachineCpuAndMemoryInfo)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                       +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;


    MessageThread::getMessageThreadInstance()->sendData(str);
}

//发送getVirtualMachineCpuAndMemoryStringSignal信号
void VirtualMachineRuntimeInfo::sendgetVirtualMachineCpuAndMemoryStringSignal(QString msg)
{
     emit getVirtualMachineCpuAndMemoryStringSignal(msg);
}

//获取指定主机下的虚拟机的磁盘信息
void VirtualMachineRuntimeInfo::getVirtualMachineDiskString(QString hostName, QString vmName)
{
    QString str = QString::number(MessageType::GetVirtualMachineDiskInfo)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                       +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;

    MessageThread::getMessageThreadInstance()->sendData(str);
}


//发送getVirtualMachineDiskStringSignal信号
void VirtualMachineRuntimeInfo::sendgetVirtualMachineDiskStringSignal(QString msg)
{
    emit getVirtualMachineDiskStringSignal(msg);
}

static VirtualMachineRuntimeInfo *virtualMachineRuntimeInfo;

//获取VirtualMachineRuntimeInfo类的单例
VirtualMachineRuntimeInfo * VirtualMachineRuntimeInfo::getVirtualMachineRuntimeInfoInstance()
{
    if(virtualMachineRuntimeInfo ==NULL)
    {
        virtualMachineRuntimeInfo = new VirtualMachineRuntimeInfo();
    }
    return virtualMachineRuntimeInfo;
}

