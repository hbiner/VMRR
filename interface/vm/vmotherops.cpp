#include "vmotherops.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VMOtherOps::VMOtherOps(QObject *parent) :
    QObject(parent)
{
}


static  VMOtherOps *vMOtherOps;  //单例对象

//获取单例对象
VMOtherOps* VMOtherOps::getVMOtherOpsInstance()
{
   if(vMOtherOps==NULL)
   {
       vMOtherOps=new VMOtherOps();
   }
   return vMOtherOps;
}


//删除虚拟机
void  VMOtherOps::destroyVm(QString hostName,QString  vmName)
{
    QString str= QString::number( MessageType::DestroyVm)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送destroyVmSignal信号
void  VMOtherOps::senddestroyVmSignal(QString msg)
{
   emit destroyVmSignal(msg);
}


//从清单中移除虚拟机
void  VMOtherOps::unregisterVm(QString hostName,QString vmName)
{
    QString str= QString::number( MessageType::UnregisterVm)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送unregisterVmSignal信号
void  VMOtherOps::sendunregisterVmSignal(QString msg)
{
   emit unregisterVmSignal(msg);
}


//虚拟机重命名
void  VMOtherOps::renameVm(QString hostName,QString vmName, QString newVmName)
{
    QString str= QString::number( MessageType::RenameVm)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +newVmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送renameVmSignal信号
void  VMOtherOps::sendrenameVmSignal(QString msg)
{
   emit renameVmSignal(msg);
}



