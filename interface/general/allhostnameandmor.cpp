#include "allhostnameandmor.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

AllHostNameAndMOR::AllHostNameAndMOR(QObject *parent) :
    QObject(parent)
{
}

  static  AllHostNameAndMOR *allHostNameAndMOR;  //单例对象

  //获取单例对象
 AllHostNameAndMOR* AllHostNameAndMOR::getAllHostNameAndMORInstance()
 {
     if(allHostNameAndMOR==NULL)
     {
         allHostNameAndMOR=new AllHostNameAndMOR();
     }
     return allHostNameAndMOR;
 }


/*
 *功能：获取全部主机的名称
 *返回值：以字符串的形式返回全部主机的名称
 */
 void  AllHostNameAndMOR::getAllHostNameString()
{
    QString str= QString::number( MessageType::GetAllHostName)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData();

     MessageThread::getMessageThreadInstance()->sendData(str);
 }

 /*
  *发送getAllHostNameStringSignal信号
  */
 void   AllHostNameAndMOR::sendgetAllHostNameStringSignal(QString msg)
 {
      emit getAllHostNameStringSignal(msg);
 }

