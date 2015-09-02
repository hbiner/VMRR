#include "vmsnapshot.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VMSnapshot::VMSnapshot(QObject *parent) :
    QObject(parent)
{
}


static  VMSnapshot *vMSnapshot;  //单例对象

//获取单例对象
VMSnapshot* VMSnapshot::getVMSnapshotInstance()
{
   if(vMSnapshot==NULL)
   {
       vMSnapshot=new VMSnapshot();
   }
   return vMSnapshot;
}

//创建虚拟机快照
void  VMSnapshot::createSnapshot(QString hostName,QString vmName,QString snapshotName,QString desc)
{
    QString str= QString::number( MessageType::CreateSnapshot)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +snapshotName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +desc+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送createSnapshotSignal信号
void  VMSnapshot::sendcreateSnapshotSignal(QString msg)
{
    emit createSnapshotSignal(msg);
}


 //列举指定虚拟机的当期的全部快照
void VMSnapshot::listSnapshot(QString hostName, QString vmName)
{
    QString str= QString::number( MessageType::ListSnapshot)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);

}
//发送listSnapshotSignal信号
void  VMSnapshot::sendlistSnapshotSignal(QString msg)
{
     emit listSnapshotSignal(msg);

}


//恢复到指定的快照
void  VMSnapshot::revertSnapshot(QString hostName,QString  vmName,QString snapshotName)
{
    QString str= QString::number( MessageType::RevertSnapshot)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +snapshotName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);

}
//发送revertSnapshotSignal信号
void  VMSnapshot::sendrevertSnapshotSignal(QString msg)
{
   emit revertSnapshotSignal(msg);
}

 //恢复到当前快照
void  VMSnapshot::revertToCurrentSnapshot(QString hostName,QString  vmName)
{
    QString str= QString::number( MessageType::RevertToCurrentSnapshot)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送revertToCurrentSnapshotSignal信号
void  VMSnapshot::sendrevertToCurrentSnapshotSignal(QString msg)
{
   emit revertToCurrentSnapshotSignal(msg);
}

  //删除全部快照
void  VMSnapshot::removeAllSnapshot(QString hostName,QString vmName)
{
    QString str= QString::number( MessageType::RemoveAllSnapshot)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送removeAllSnapshotSignal信号
void  VMSnapshot::sendremoveAllSnapshotSignal(QString msg)
{
    emit removeAllSnapshotSignal(msg);
}

 //移除指定的快照
void  VMSnapshot::removeSnapshot(QString hostName,QString  vmName,QString  snapshotName,QString removeChild)
{
    QString str= QString::number( MessageType::RemoveSnapshot)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +snapshotName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +removeChild +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送removeSnapshotSignal信号
void  VMSnapshot::sendremoveSnapshotSignal(QString msg)
{
   emit removeSnapshotSignal(msg);
}


