#include "hostinfo.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

HostInfo::HostInfo(QObject *parent) :
    QObject(parent)
{
}


static  HostInfo *hostInfo;  //单例对象

//获取单例对象
HostInfo* HostInfo:: getHostInfoInstance()
{
    if(hostInfo==NULL)
    {
        hostInfo=new HostInfo();
    }
    return hostInfo;

}



/*
 *功能：获取指定主机的详情信息
 *返回值：以字符串的形式返回指定主机的详情信息
 */
void  HostInfo::getHostInfoString(QString hostName)
{
     QString str= QString::number( MessageType::GetHostInfo)
                          +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                          +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                          +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                          +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()  ;

     MessageThread::getMessageThreadInstance()->sendData(str);
}


/*
 *功能：发送getHostInfoStringSignal信号
 */
void HostInfo:: sendgetHostInfoStringSignal(QString msg)
{
    emit getHostInfoStringSignal(msg);
}


