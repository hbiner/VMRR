#include "virtualmachineinfo.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VirtualMachineInfo::VirtualMachineInfo(QObject *parent) :
    QObject(parent)
{
}

static  VirtualMachineInfo *virtualMachineInfo;  //单例对象

 //获取单例对象
 VirtualMachineInfo* VirtualMachineInfo::getVirtualMachineInfoInstance()
{

     if(virtualMachineInfo==NULL)
     {
         virtualMachineInfo=new VirtualMachineInfo();
     }
     return virtualMachineInfo;
}



 //获取指定主机下的虚拟机的详情信息
void  VirtualMachineInfo::getVirtualMachineInfoString(QString hostName,QString vmName)
{
    QString str= QString::number( MessageType::GetVirtualMachineInfo)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;





    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送getVirtualMachineInfoStringSignal信号
void  VirtualMachineInfo::sendgetVirtualMachineInfoStringSignal(QString msg)
{
     emit  getVirtualMachineInfoStringSignal(msg);
}

