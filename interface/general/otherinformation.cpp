#include "otherinformation.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

OtherInformation::OtherInformation(QObject *parent) :
    QObject(parent)
{
}


static  OtherInformation *otherInformation;  //单例对象

//获取单例对象
OtherInformation* OtherInformation::getOtherInformationInstance()
{
   if(otherInformation==NULL)
   {
       otherInformation=new OtherInformation();
   }
   return otherInformation;
}

//获取客户机操作类型
void  OtherInformation::getGuestOsId()
{
    QString str= QString::number( MessageType::GetGuestOsId)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData();

    MessageThread::getMessageThreadInstance()->sendData(str);
}

//发送getGuestOsIdSignal信号
void  OtherInformation::sendgetGuestOsIdSignal(QString msg)
{
   emit getGuestOsIdSignal(msg);
}

 //获取迁移优先级
void  OtherInformation::getvMotionPriority()
{
    QString str= QString::number( MessageType::GetvMotionPriority)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送getvMotionPrioritySignal信号
void  OtherInformation::sendgetvMotionPrioritySignal(QString msg)
{

    emit getvMotionPrioritySignal(msg);
}
