#include "hostoperation.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

HostOperation::HostOperation(QObject *parent) :
    QObject(parent)
{
}

static  HostOperation *hostOperation;  //单例对象

//获取单例对象
HostOperation* HostOperation::getHostOperationInstance()
{
   if(hostOperation==NULL)
   {
       hostOperation=new HostOperation();
   }
   return hostOperation;
}

//添加主机到集群
void  HostOperation::addHostToCluster(QString clusterName,QString hostName,QString userName,QString password)
{
    QString str= QString::number( MessageType::AddHostToCluster)
            +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
            +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
            +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
            +clusterName+ MessageThread::getMessageThreadInstance()->getReqParSplit()
            +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()
            +userName+ MessageThread::getMessageThreadInstance()->getReqParSplit()
            +password+ MessageThread::getMessageThreadInstance()->getReqParSplit();




     MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送信号
void  HostOperation::sendaddHostToClusterSignal(QString msg)
{
     emit addHostToClusterSignal( msg);
}


  //将主机从集群中移除
void  HostOperation::removeHostFromCluster(QString hostName)
{
    QString str= QString::number( MessageType::RemoveHostFromCluster)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        + hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()    ;

     MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送信号
 void  HostOperation::sendremoveHostFromClusterSignal(QString msg)
 {
     emit removeHostFromClusterSignal( msg);
 }


//将主机进入维护模式
void  HostOperation::enterMaintenanceMode(QString hostName)
{
    QString str= QString::number( MessageType::EnterMaintenanceMode)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()    ;

     MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送信号
 void  HostOperation::sendenterMaintenanceModeSignal(QString msg)
 {
     emit enterMaintenanceModeSignal( msg);
 }


 //将主机退出维护模式
void  HostOperation::exitMaintenanceMode(QString hostName)
{
    QString str= QString::number( MessageType::ExitMaintenanceMode)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()    ;

     MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送信号
 void  HostOperation::sendexitMaintenanceModeSignal(QString msg)
 {
     emit exitMaintenanceModeSignal( msg);
 }


 //断开与主机的连接
void  HostOperation::disconnectHost(QString hostName)
{
    QString str= QString::number( MessageType::DisconnectHost)
            +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
            +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
            +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
            +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()    ;

     MessageThread::getMessageThreadInstance()->sendData(str);
}

//发送信号
 void  HostOperation::senddisconnectHostSignal(QString msg)
 {
    emit disconnectHostSignal( msg);
 }


  //重新与主机进行连接
void  HostOperation::reconnectHost(QString hostName)
{
    QString str= QString::number( MessageType::ReconnectHost)
            +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
            +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
            +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
            +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()    ;

     MessageThread::getMessageThreadInstance()->sendData(str);
}

//发送信号
 void  HostOperation::sendreconnectHostSignal(QString msg)
 {
    emit reconnectHostSignal( msg);
 }

