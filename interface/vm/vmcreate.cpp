#include "vmcreate.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VMCreate::VMCreate(QObject *parent) :
    QObject(parent)
{
}

static  VMCreate *vMCreate;  //单例对象

//获取单例对象
VMCreate* VMCreate::getVMCreateInstance()
{
   if(vMCreate==NULL)
   {
       vMCreate=new VMCreate();
   }
   return vMCreate;
}

    //创建虚拟机
void  VMCreate::createVirtualMachine(QString hostname,QString vmName, QString guestOsId,
                                             QString numCpus,QString  diskSize,QString vmMemorySize,
                                             QString numNics,QString dataStore,QString iso,
                                             QString  startVM)
{

    QString str= QString::number( MessageType::CreateVirtualMachine)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostname+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +guestOsId+MessageThread::getMessageThreadInstance()->getReqParSplit()

                        +numCpus+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +diskSize+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmMemorySize+MessageThread::getMessageThreadInstance()->getReqParSplit()

                        +numNics+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +dataStore+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +iso+MessageThread::getMessageThreadInstance()->getReqParSplit()

                        +startVM+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);

}
//发送createVirtualMachineSignal信号
void  VMCreate::sendcreateVirtualMachineSignal(QString msg)
{
    emit  createVirtualMachineSignal(msg);
}
