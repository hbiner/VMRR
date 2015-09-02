#include "vncinfo.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VNCInfo::VNCInfo(QObject *parent) :
    QObject(parent)
{
}

static VNCInfo* vncInfo;//单例对象

//获取单例对象
VNCInfo* VNCInfo::getVNCinfoInstance()
{
    if(vncInfo==NULL)
    {
        vncInfo=new VNCInfo();
    }
    return vncInfo;
}

void VNCInfo::getVNCInfo(QString hostName, QString vmName)
{
     QString str= QString::number(MessageType::getVNCInfo)   
                 +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                 +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                 +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                 +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                 +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}

void VNCInfo::sendGetVNCInfoSignals(QString msg)
{
    emit getVNCInfoSignals(msg);
}
