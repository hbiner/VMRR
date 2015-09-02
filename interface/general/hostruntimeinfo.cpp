#include "hostruntimeinfo.h"
#include "controller/commonfactory.h"
#include "controller/messagethread.h"
#include "controller/MessageType.h"

HostRuntimeInfo::HostRuntimeInfo(QObject *parent) :
    QObject(parent)
{
}

//查询主机cpu和memory大小及使用率
void HostRuntimeInfo::getHostRuntimeInfo(QString hostName)
{
    QString str = QString::number(MessageType::GetHostRuntimeInfo)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;


    MessageThread::getMessageThreadInstance()->sendData(str);
}

//返回主机cpu和memory大小及使用率
void HostRuntimeInfo::sendgetHostRuntimeInfoSignal(QString msg)
{
    emit this->getHostRuntimeInfoSignal(msg);
}

//查询主机存储器容量及使用率
void HostRuntimeInfo::getHostDataStoreInfo(QString hostName)
{
    QString str = QString::number(MessageType::GetHostDataStoreInfo)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;
    MessageThread::getMessageThreadInstance()->sendData(str);
}

//返回主机存储器容量及使用率
void HostRuntimeInfo::sendgetHostDataStoreInfoSignal(QString msg)
{
    emit this->getHostDataStoreInfoSignal(msg);
}

static HostRuntimeInfo *hostRuntimeInfo;

//获取HostRuntimeInfo类的单例
HostRuntimeInfo * HostRuntimeInfo::getHostRuntimeInfoInstance()
{
    if(hostRuntimeInfo == NULL)
    {
        hostRuntimeInfo = new HostRuntimeInfo();
    }
    return hostRuntimeInfo;
}

