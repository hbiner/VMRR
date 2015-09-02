#include "vmotion.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VMotion::VMotion(QObject *parent) :
    QObject(parent)
{
}


static  VMotion *vMotion;  //单例对象

//获取单例对象
VMotion* VMotion::getVMotionInstance()
{
   if(vMotion==NULL)
   {
       vMotion=new VMotion();
   }
   return vMotion;
}

// 对虚拟机进行迁移操作
void  VMotion::migrateVM(QString vmname, QString tcluster,QString tHost, QString srcHost, QString priority)
{
    QString str= QString::number( MessageType::MigrateVM)
            +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
            +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
            +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
            +vmname+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +tcluster+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +tHost+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +srcHost+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +priority+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送migrateVMSignal信号
void  VMotion::sendmigrateVMSignal(QString msg)
{
   emit migrateVMSignal(msg);
}


// 对虚拟机在同一主机内进行重定位操作
void  VMotion::relocateVMOnSameHost(QString vmname,QString  tcluster,QString tDS, QString srcHost,QString  priority)
{
    QString str= QString::number( MessageType::RelocateVMOnSameHost)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +vmname+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +tcluster+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +tDS+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +srcHost+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +priority+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送relocateVMOnSameHostSignal信号
void  VMotion::sendrelocateVMOnSameHostSignal(QString msg)
{
    emit relocateVMOnSameHostSignal(msg);
}


// 对虚拟机在不同主机内进行重定位操作
void  VMotion::relocateVMOnDifferentHost(QString vmname,QString  tcluster,QString tHost,QString  tDS,QString  srcHost,QString  priority)
{

    QString str= QString::number( MessageType::RelocateVMOnDifferentHost)
            +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
            +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
            +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
            +vmname+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +tcluster+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +tHost+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +tDS+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +srcHost+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +priority+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送relocateVMOnDifferentHostSignal信号
void  VMotion::sendrelocateVMOnDifferentHostSignal(QString msg)
{
   emit relocateVMOnDifferentHostSignal(msg);
}
