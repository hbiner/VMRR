#include "datastoresbyhost.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

DatastoresByHost::DatastoresByHost(QObject *parent) :
    QObject(parent)
{
}

static  DatastoresByHost *datastoresByHost;  //单例对象

//获取单例对象
DatastoresByHost* DatastoresByHost::getDatastoresByHostInstance()
{
   if(datastoresByHost==NULL)
   {
       datastoresByHost=new DatastoresByHost();
   }
   return datastoresByHost;
}

 //获取指定主机下的全部的存储器
void  DatastoresByHost::getDataStores(QString hostName)
{
    QString str= QString::number( MessageType::GetDataStores)
                       +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                       +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                       +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                       +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;


    MessageThread::getMessageThreadInstance()->sendData(str);
}

//显示存储器的下一级文件夹
void DatastoresByHost::getDatastoreSubForder(QString hostName)
{
    QString str= QString::number( MessageType::GetDataStoresSubForder)
               +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
               +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
               +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
               +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;
    MessageThread::getMessageThreadInstance()->sendData(str);
}

 //发送getDataStoresSignal信号
void  DatastoresByHost::sendgetDataStoresSignal(QString msg)
{
    emit getDataStoresSignal(msg);
}

//发送getDataStoresSignal信号
void  DatastoresByHost::sendgetDataStoresSubForderSignal(QString msg)
{
   emit getDatastoreSubForderSignal(msg);
}
