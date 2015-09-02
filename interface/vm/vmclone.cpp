#include "vmclone.h"
#include"controller/messagethread.h"
#include"controller/MessageType.h"

VMClone::VMClone(QObject *parent) :
    QObject(parent)
{
}


static  VMClone *vMClone;  //单例对象

//获取单例对象
VMClone* VMClone::getVMCloneInstance()
{
   if(vMClone==NULL)
   {
       vMClone=new VMClone();
   }
   return vMClone;
}


 // 克隆虚拟机(开机或关机)
void VMClone::cloneVM(QString hostName, QString  vmName, QString cloneName)
{
    QString str= QString::number( MessageType::CloneVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +cloneName+MessageThread::getMessageThreadInstance()->getReqParSplit();




    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送cloneVMSignal信号
void  VMClone::sendcloneVMSignal(QString msg)
{
    emit cloneVMSignal(msg);
}


// 克隆模板 (模板是虚拟机的主镜像)
void VMClone::cloneTemplate(QString hostName,QString  templateName, QString cloneName)
{
    QString str= QString::number( MessageType::CloneTemplate)
            +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
            +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
            +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
            +hostName+  MessageThread::getMessageThreadInstance()->getReqParSplit()
            +templateName+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +cloneName+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送cloneTemplateSignal信号
void VMClone:: sendcloneTemplateSignal(QString msg)
{
   emit cloneTemplateSignal(msg);
}


// 虚拟机克隆为模板
void VMClone::cloneVMToTemplate(QString hostName,QString  vmName, QString cloneName)
{
    QString str= QString::number( MessageType::CloneVMToTemplate)
            +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
            +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
            +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
            +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()
            +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit()
            +cloneName+MessageThread::getMessageThreadInstance()->getReqParSplit() ;


    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送cloneVMToTemplateSignal信号
void  VMClone::sendcloneVMToTemplateSignal(QString msg)
{
    emit cloneVMToTemplateSignal(msg);
}


 // 从模板部署虚拟机
void VMClone::cloneTemplatToVM(QString clusterName, QString hostName,QString  templateName, QString cloneName)
{
    QString str= QString::number( MessageType::CloneTemplatToVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +clusterName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +hostName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +templateName+MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +cloneName+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送cloneTemplatToVMSignal信号
void  VMClone::sendcloneTemplatToVMSignal(QString msg)
{
   emit  cloneVMToTemplateSignal(msg);
}


 // 将虚拟机转化为模板
void VMClone::vmToTemp( QString hostName,QString  vmName)
{
    QString str= QString::number( MessageType::VmToTemp)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +vmName+MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
 //发送vmToTempSignal信号
void  VMClone::sendvmToTempSignal(QString msg)
{
    emit  vmToTempSignal(msg);
}


 // 将模板转化为虚拟机
void VMClone::markAsVM(QString clusterName,QString hostName, QString templateName)
{
    QString str= QString::number( MessageType::MarkAsVM)
                        +MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit()
                        +QString::number(MessageThread::getMessageThreadInstance()->getNumberOfCommand())
                        +MessageThread::getMessageThreadInstance()->getMsgTypeSplitData()
                        +clusterName+ MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +hostName+ MessageThread::getMessageThreadInstance()->getReqParSplit()
                        +templateName  +MessageThread::getMessageThreadInstance()->getReqParSplit();

    MessageThread::getMessageThreadInstance()->sendData(str);
}
//发送markAsVMSignal信号
void  VMClone::sendmarkAsVMSignal(QString msg)
{
  emit markAsVMSignal(msg);
}
