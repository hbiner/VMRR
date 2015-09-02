#include "vmpowerops.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VMPowerOps::VMPowerOps(QObject *parent) :
    QObject(parent)
{
}

static  VMPowerOps *vMPowerOps;  //单例对象

//获取单例对象
VMPowerOps* VMPowerOps::getVMPowerOpsInstance()
{
   if(vMPowerOps==NULL)
   {
       vMPowerOps=new VMPowerOps();
   }
   return vMPowerOps;
}


// 给指定的虚拟机打开电源
void   VMPowerOps::powerOnVM(QString hostName,QString vmName)
{
    QString str= QString::number( MessageType::PowerOnVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送powerOnVMSignal信号
void  VMPowerOps::sendpowerOnVMSignal(QString msg)
{
    emit powerOnVMSignal(msg);
}


// 给指定的虚拟机关闭电源
void   VMPowerOps::powerOffVM(QString hostName, QString vmName)
{
    QString str= QString::number( MessageType::PowerOffVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送powerOffVMSignal信号
void   VMPowerOps::sendpowerOffVMSignal(QString msg)
{
   emit powerOffVMSignal(msg);
}


// 复位指定的虚拟机
void   VMPowerOps::resetVM(QString hostName,QString  vmName)
{
    QString str= QString::number( MessageType::ResetVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送resetVMSignal信号
void   VMPowerOps::sendresetVMSignal(QString msg)
{
    emit  resetVMSignal(msg);
}


// 挂起指定的虚拟机
void   VMPowerOps::suspendVM(QString hostName,QString vmName)
{
    QString str= QString::number( MessageType::SuspendVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送suspendVMSignal信号
void   VMPowerOps::sendsuspendVMSignal(QString msg)
{
   emit suspendVMSignal(msg);
}


// 重启客户机
void   VMPowerOps::rebootVM(QString hostName,QString  vmName)
{
    QString str= QString::number( MessageType::RebootVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送rebootVMSignal信号
void   VMPowerOps::sendrebootVMSignal(QString msg)
{
   emit rebootVMSignal(msg);
}


// 关闭客户机
void  VMPowerOps::shutdownVM(QString hostName,QString  vmName)
{
    QString str= QString::number( MessageType::ShutdownVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);

}
 //发送shutdownVMSignal信号
void   VMPowerOps::sendshutdownVMSignal(QString msg)
{
    emit shutdownVMSignal(msg);
}


// 启动客户机操作系统待机
void   VMPowerOps::standbyVM(QString hostName,QString vmName)
{

    QString str= QString::number( MessageType::StandbyVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送standbyVMSignal信号
void   VMPowerOps::sendstandbyVMSignal(QString msg)
{
   emit standbyVMSignal(msg);
}

