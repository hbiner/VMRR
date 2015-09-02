#include "isofile.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

IsoFile::IsoFile(QObject *parent) :
    QObject(parent)
{
}

static  IsoFile *isoFile;  //单例对象

//获取单例对象
IsoFile* IsoFile::getIsoFileInstance()
{
   if(isoFile==NULL)
   {
       isoFile=new IsoFile();
   }
   return isoFile;
}

//获取全部镜像文件
void  IsoFile::getIsoFile()
{
    QString str= QString::number( MessageType::GetIsoFile)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData() ;

    MessageThread::getMessageThreadInstance()->sendData(str);
}

 //发送getIsoFileSignal信号
void  IsoFile::sendgetIsoFileSignal(QString msg)
{
   emit getIsoFileSignal(msg);
}
