#include "vmnameandstate.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VMNameAndState::VMNameAndState(QObject *parent) :
    QObject(parent)
{
}

static  VMNameAndState *vMNameAndState;  //单例对象

//获取单例对象
VMNameAndState* VMNameAndState:: getVMNameAndStateInstance()
{
    if(vMNameAndState==NULL)
    {
        vMNameAndState=new VMNameAndState();
    }
    return vMNameAndState;

}


/*
*功能：获取制定主机下的的全部虚拟机的名称和状态
*返回值：以字符串的形式返回全部虚拟机的名称和状态
*/
void  VMNameAndState::getVMNameAndStateString(QString hostName)
{
    //构造要发送的数据
     QString str= QString::number( MessageType::GetVMNameAndState)
                         +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                         +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                         +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                         +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;

     MessageThread::getMessageThreadInstance()->sendData(str);
}



/*
*发送getVMNameAndStateStringSignal信号
*/
void   VMNameAndState::sendgetVMNameAndStateStringSignal(QString msg)
{
    emit getVMNameAndStateStringSignal(msg);
}


