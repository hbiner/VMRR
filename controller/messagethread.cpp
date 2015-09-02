#include "messagethread.h"
#include"MessageType.h"
#include<QHostAddress>
#include<QStringList>
#include"commonfactory.h"
MessageThread::MessageThread(QObject *parent) :
    QObject(parent)
{
    //服务器IP
        IP="192.168.3.230";
    //端口
    port=7000;
    //连接状态
    connState=false;
    //指定消息类型和数据项的分割符
    msgTypeSplitData=":::";
    //指定数据项和数据项的分割符
    betweenDataItemSplit="?";
    //指明请求参数分隔符
    reqParSplit="#";
    // 数据项内部的分隔符
     WithinDataItemSplit=",";
     //指定属性和值得分割符
      propertySplitValue=":";
    //设置序列号从0开始
    numberOfCommand=0;

    //与服务器建立连接后产生sonnected()信号
    connect(&tcpClient, SIGNAL(connected()), this, SLOT(successconnectedSlot()));
    //数据成功发送后产生bytesritten()信号
    connect(&tcpClient, SIGNAL(bytesWritten(qint64)), this, SLOT(successSendDataSlot(qint64)));
    //有可读取的数据时发出readyead()信号
    connect(&tcpClient, SIGNAL(readyRead()), this, SLOT(receiveDataSlot()));
    //产生错误后发出error()信号
    connect(&tcpClient, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayErrorSlot(QAbstractSocket::SocketError)));
}

static MessageThread *messageThread;   //定义单例对象


//获取单例对象
MessageThread *  MessageThread::getMessageThreadInstance()
{
    if(messageThread==NULL)
    {
        messageThread=new MessageThread();
    }

    return messageThread;
}

//获取序列号
qint64 MessageThread::getNumberOfCommand()
{
    return  numberOfCommand++;
}

//获取报文头部和数据的分割符
QString  MessageThread::getMsgTypeSplitData()
{
    return  this->msgTypeSplitData;
}

//获取数据项和数据项的分割符
QString  MessageThread::getBetweenDataItemSplit()
{
    return  this->betweenDataItemSplit;
}

//获取请求参数分割符号
QString  MessageThread::getReqParSplit()
{
    return  this->reqParSplit;
}



// 数据项内部的分隔符
QString  MessageThread::getWithinDataItemSplit()
{
 return  this->WithinDataItemSplit;
}

//指定属性和值得分割符
 QString  MessageThread::getpropertySplitValue()
 {
  return  this->propertySplitValue;
 }


//连接服务端
void MessageThread::conn()
{
    if(!connState)
    {
        QHostAddress  ipaddress;
        ipaddress.setAddress(IP);
        tcpClient.connectToHost(ipaddress, port);
    }
    else
    {
        qDebug()<<tr("当前已经建立了与服务器的TCP连接");
    }

}

//与服务端断开连接
void MessageThread::closeConn()
{
    if(connState)
    {
        //关闭连接
        tcpClient.close();
    }
    else
    {
        qDebug()<<tr("当前你还没有获取与服务器的TCP连接");
    }
}

//与服务器连接成功
void MessageThread::successconnectedSlot()
{
    //指定已经连接了连接
    connState=true;
    qDebug()<<tr("与服务器的TCP连接建立成功");
}

//发送数据
void MessageThread::sendData(QString data)
{

    /*************************************************/
    /******************请求报文格式 ********************/
    /*****************报文头部:::数据 *******************/
    /***************报文头部格式:   操作类型?序列号********/
    /***********数据格式:    参数01?参数02? ***************/
    /************************************************/


    //将要发送的数据转化为utf-8编码的二进制数据
    outBlock=data.toUtf8();
    //发送数据
    tcpClient.write(outBlock);
    tcpClient.flush();
    //清空发送区
    outBlock.resize(0);
    qDebug()<<"发送数据-->"<<data;
}

//显示已经成功发送发送数据
void MessageThread::successSendDataSlot(qint64 numBytes)
{
    if (numBytes > 0)
    {
        //          qDebug()<<"已发送成功消息【消息ID："<<numberOfCommand++<<"】";
        qDebug()<<"已发送成功消息";
    }
    else
    {
        //         qDebug()<<"发送数据失败【消息ID："<<numberOfCommand<<"】-->";
        qDebug()<<"发送数据失败";
    }
}


//接受数据
void MessageThread::receiveDataSlot()
{
    if(tcpClient.bytesAvailable()>0)
    {
        //根据可读取的字节数设置inBlock的大小
        inBlock.resize(tcpClient.bytesAvailable());
        //读取所有可以读取的数据放入到inBlock中
        inBlock=tcpClient.readAll();
        QString   msg=inBlock.data();
        //清空inBlock
        inBlock.resize(0);
        //显示接受的数据
        qDebug()<<"收到数据<--"<<msg;
        QStringList strList;
        //msgTypeSplitData分割符来将消息类型和数据进行分割
        strList = (msg.trimmed()).split(msgTypeSplitData);
        strList=(strList.at(0).trimmed()).split("?");
        //获取消息类型
        MessageType::MsgTypeEnum  type=(MessageType::MsgTypeEnum)(strList.at(0).toInt());
        switch(type)
        {

        /*--------------------------------------------------------AllHostNameAndMOR类使用----------------------------------------------------------------------------------------*/
        case MessageType::GetAllHostName:      //获取制定vCetner Server 中的所有主机名称
        {
            CommonFactory::getAllHostNameAndMORInstance()->sendgetAllHostNameStringSignal(msg);
            break;
        }

            /*--------------------------------------------------------AllHostNameAndMOR类使用----------------------------------------------------------------------------------------*/
        case MessageType::GetVMNameAndState:      //获取制定vCetner Server 中的所有主机名称
        {
            CommonFactory::getVMNameAndStateInstance()->sendgetVMNameAndStateStringSignal(msg);
            break;
        }

            /*--------------------------------------------------------HostInfo类使用----------------------------------------------------------------------------------------*/
        case MessageType::GetHostInfo:      //获取制定vCetner Server 中的所有主机名称
        {
            CommonFactory::getHostInfoInstance()->sendgetHostInfoStringSignal(msg);
            break;
        }

            /*--------------------------------------------------------VirtualMachineInfo类使用----------------------------------------------------------------------------------------*/
        case MessageType::GetVirtualMachineInfo:      //获取制定vCetner Server 中的所有主机名称
        {
            CommonFactory::getVirtualMachineInfoInstance()->sendgetVirtualMachineInfoStringSignal(msg);
            break;
        }
            /*--------------------------------------------------------DatastoresByHost类----------------------------------------------------------------------------------------*/
        case MessageType::GetDataStores:    //获取指定主机下的全部的存储器
        {
            CommonFactory::getDatastoresByHostInstance()->sendgetDataStoresSignal(msg);
            break;
        }
        case MessageType::GetDataStoresSubForder:   //获取存储器的下一级文件夹
             {
                  CommonFactory::getDatastoresByHostInstance()->sendgetDataStoresSubForderSignal(msg);
                  break;
             }

            /*--------------------------------------------------------IsoFile类----------------------------------------------------------------------------------------------------*/
        case MessageType::GetIsoFile:   //获取全部镜像文件
        {
            CommonFactory::getIsoFileInstance()->sendgetIsoFileSignal(msg);
            break;
        }


            /*--------------------------------------------------------OtherInformation类----------------------------------------------------------------------------------------*/
        case MessageType::GetGuestOsId:   //获取客户机操作类型
        {
            CommonFactory::getOtherInformationInstance()->sendgetGuestOsIdSignal(msg);
            break;
        }

        case MessageType::GetvMotionPriority:  //获取迁移优先级
        {
            CommonFactory::getOtherInformationInstance()->sendgetvMotionPrioritySignal(msg);
            break;
        }

            /*--------------------------------------------------------HostOperation类使用----------------------------------------------------------------------------------------*/
        case MessageType:: AddHostToCluster:    //添加主机到集群
        {
            CommonFactory::getHostOperationInstance()->sendaddHostToClusterSignal(msg);
            break;
        }
        case MessageType:: RemoveHostFromCluster:     //将主机从集群中移除
        {
            CommonFactory::getHostOperationInstance()->sendremoveHostFromClusterSignal(msg);
            break;
        }
        case MessageType:: EnterMaintenanceMode:    //将主机进入维护模式
        {
            CommonFactory::getHostOperationInstance()->sendenterMaintenanceModeSignal(msg);
            break;
        }
        case MessageType:: ExitMaintenanceMode:     //将主机退出维护模式
        {
            CommonFactory::getHostOperationInstance()->sendexitMaintenanceModeSignal(msg);
            break;
        }
        case MessageType:: DisconnectHost:     //断开与主机的连接
        {
            CommonFactory::getHostOperationInstance()->senddisconnectHostSignal(msg);
            break;
        }
        case MessageType:: ReconnectHost:    //重新与主机进行连接
        {
            CommonFactory::getHostOperationInstance()->sendreconnectHostSignal(msg);
            break;
        }

            /*---------------------------------------------------------VMClone类-----------------------------------------------------------------------------------------------*/
        case MessageType:: CloneVM: // 克隆虚拟机(开机或关机)
        {
            CommonFactory::getVMCloneInstance()->sendcloneVMSignal(msg);
            break;
        }

        case MessageType:: CloneTemplate: // 克隆模板 (模板是虚拟机的主镜像)
        {

            CommonFactory::getVMCloneInstance()->sendcloneTemplateSignal(msg);
            break;
        }
        case MessageType:: CloneVMToTemplate:  // 虚拟机克隆为模板
        {

            CommonFactory::getVMCloneInstance()->sendcloneVMToTemplateSignal(msg);
            break;
        }
        case MessageType:: CloneTemplatToVM: // 从模板部署虚拟机
        {

            CommonFactory::getVMCloneInstance()->sendcloneTemplatToVMSignal(msg);
            break;
        }
        case MessageType:: VmToTemp: // 将虚拟机转化为模板
        {

            CommonFactory::getVMCloneInstance()->sendvmToTempSignal(msg);
            break;
        }
        case MessageType:: MarkAsVM:  // 将模板转化为虚拟机
        {

            CommonFactory::getVMCloneInstance()->sendmarkAsVMSignal(msg);
            break;
        }


            /*---------------------------------------------------------VMCreate类---------------------------------------------------------------------------------------------*/
        case MessageType:: CreateVirtualMachine://创建虚拟机
        {
            CommonFactory::getVMCreateInstance()->sendcreateVirtualMachineSignal(msg);
            break;
        }


            /*---------------------------------------------------------VMOtherOps类-----------------------------------------------------------------------------------------*/
        case MessageType:: DestroyVm: //删除虚拟机
        {
            CommonFactory::getVMOtherOpsInstance()->senddestroyVmSignal(msg);
            break;
        }
        case MessageType:: UnregisterVm:  //从清单中移除虚拟机
        {
            CommonFactory::getVMOtherOpsInstance()->sendunregisterVmSignal(msg);
            break;
        }
        case MessageType:: RenameVm: //虚拟机重命名
        {
            CommonFactory::getVMOtherOpsInstance()->sendrenameVmSignal(msg);
            break;
        }


            /*---------------------------------------------------------VMotion类-----------------------------------------------------------------------------------------------*/
        case MessageType:: MigrateVM:  // 对虚拟机进行迁移操作
        {
            CommonFactory::getVMotionInstance()->sendmigrateVMSignal(msg);
            break;
        }
        case MessageType:: RelocateVMOnSameHost:  // 对虚拟机在同一主机内进行重定位操作
        {
            CommonFactory::getVMotionInstance()->sendrelocateVMOnSameHostSignal(msg);
            break;
        }
        case MessageType:: RelocateVMOnDifferentHost: // 对虚拟机在不同主机内进行重定位操作
        {
            CommonFactory::getVMotionInstance()->sendrelocateVMOnDifferentHostSignal(msg);
            break;
        }


            /*--------------------------------------------------------VMPowerOps类-----------------------------------------------------------------------------------------*/
        case MessageType:: PowerOnVM: // 给指定的虚拟机打开电源
        {
            CommonFactory::getVMPowerOpsInstance()->sendpowerOnVMSignal(msg);
            break;
        }
        case MessageType:: PowerOffVM: // 给指定的虚拟机关闭电源
        {
            CommonFactory::getVMPowerOpsInstance()->sendpowerOffVMSignal(msg);
            break;
        }
        case MessageType:: ResetVM: // 复位指定的虚拟机
        {
            CommonFactory::getVMPowerOpsInstance()->sendresetVMSignal(msg);
            break;
        }
        case MessageType:: SuspendVM:// 挂起指定的虚拟机
        {
            CommonFactory::getVMPowerOpsInstance()->sendsuspendVMSignal(msg);
            break;
        }
        case MessageType:: RebootVM: // 重启客户机
        {
            CommonFactory::getVMPowerOpsInstance()->sendrebootVMSignal(msg);
            break;
        }
        case MessageType:: ShutdownVM:  // 关闭客户机
        {
            CommonFactory::getVMPowerOpsInstance()->sendshutdownVMSignal(msg);
            break;
        }
        case MessageType:: StandbyVM:  // 启动客户机操作系统待机
        {
            CommonFactory::getVMPowerOpsInstance()->sendstandbyVMSignal(msg);
            break;
        }


            /*---------------------------------------------------------VMSnapshot类-----------------------------------------------------------------------------------------*/
        case MessageType:: CreateSnapshot:  //创建虚拟机快照
        {
            CommonFactory::getVMSnapshotInstance()->sendcreateSnapshotSignal(msg);
            break;
        }
        case MessageType:: ListSnapshot:  //列举指定虚拟机的当期的全部快照
        {
            CommonFactory::getVMSnapshotInstance()->sendlistSnapshotSignal(msg);
            break;
        }
        case MessageType:: RevertSnapshot:    //恢复到指定的快照
        {
            CommonFactory::getVMSnapshotInstance()->sendrevertSnapshotSignal(msg);
            break;
        }
        case MessageType:: RevertToCurrentSnapshot:  //恢复到当前快照
        {
            CommonFactory::getVMSnapshotInstance()->sendrevertToCurrentSnapshotSignal(msg);
            break;
        }
        case MessageType:: RemoveAllSnapshot:  //删除全部快照
        {
            CommonFactory::getVMSnapshotInstance()->sendremoveAllSnapshotSignal(msg);
            break;
        }
        case MessageType:: RemoveSnapshot:  //移除指定的快照
        {
            CommonFactory::getVMSnapshotInstance()->sendremoveSnapshotSignal(msg);
            break;
        }


            /*-------------------------------------------------------HostRuntimeInfo类使用-----------------------------------------------------------------------------------*/

        case MessageType::GetHostRuntimeInfo:
        {
            CommonFactory::getHostRuntimeInfoInstance()->sendgetHostRuntimeInfoSignal(msg);
            break;
        }
        case MessageType::GetHostDataStoreInfo:
        {
            CommonFactory::getHostRuntimeInfoInstance()->sendgetHostDataStoreInfoSignal(msg);
            break;
        }

            /*-----------------------------------------------------VirtualMachineRuntimeInfo类使用-------------------------------------------------------------------------------------*/
        case MessageType::GetVirtualMachineCpuAndMemoryInfo:  //获取指定主机下的虚拟机的cpu和memory信息
        {
            CommonFactory::getVirtualMachineRuntimeInfoInstance()->sendgetVirtualMachineCpuAndMemoryStringSignal(msg);
            break;
        }

        case MessageType::GetVirtualMachineDiskInfo:  //获取指定主机下的虚拟机的磁盘信息
        {
            CommonFactory::getVirtualMachineRuntimeInfoInstance()->sendgetVirtualMachineDiskStringSignal(msg);
            break;
        }
            /*--------------------------------------------------------VirtualMachineReconfigure类使用---------------------------------------------------------------------------*/

        case MessageType::VirtualMachineCpuReconfig: //对指定主机下的虚拟机的cpu重新配置
        {
            CommonFactory::getVirtualMachineReconfigureInstance()->sendsetVirtualMachineCpuNumsSignal(msg);
            break;
        }

        case MessageType::VirtualMachineMemoryReconfig: //对指定主机下的虚拟机的memroy重新配置
        {
            CommonFactory::getVirtualMachineReconfigureInstance()->sendsetVirtualMachineMemorySizeSignal(msg);
            break;
        }

        case MessageType::VirtualMachineDiskReconfig: //对指定主机下的虚拟机的指定磁盘进行重新配置
        {
            CommonFactory::getVirtualMachineReconfigureInstance()->sendsetVitualMachineDiskSizeSignal(msg);
            break;
        }

        case MessageType::VirtualMachineCpuHotAddAndRemoveEnable://启用指定主机下的指定虚拟机的cpu的热插拔
        {
            CommonFactory::getVirtualMachineReconfigureInstance()->sendsetVMCpuHotAddAndRemoveEnableSignal(msg);
            break;
        }

        case MessageType::VirtualMachineMemoryHotAddEnable://启用指定主机下的指定虚拟机的内存的热增加
        {
            CommonFactory::getVirtualMachineReconfigureInstance()->sendsetVMMemoryHotAddEnableSignal(msg);
            break;
        }
            /*-----------------sitefirewalldefaultpolicy类------------------*/
        case MessageType::enableFirewallDefaultPolicy:
        {
            CommonFactory::getSiteFirewallDefaultPolicyInstance()->sendEnableFirewallDefaultPolicySignals(msg);
            break;
        }
        case MessageType::undoFirewallDefaultPolicy:
        {
            CommonFactory::getSiteFirewallDefaultPolicyInstance()->sendUndoFirewallDefaultPolicySignals(msg);
            break;
        }
            /*-------------------------VNCInfo类-------------------------------------*/
        case MessageType::getVNCInfo:
        {
            CommonFactory::getVNCInfoInstance()->sendGetVNCInfoSignals(msg);
            break;
        }
        }

    }
}

//显示TCP错误信息
void MessageThread::displayErrorSlot(QAbstractSocket::SocketError socketError)
{
    if (socketError == QTcpSocket::RemoteHostClosedError)
    {
        return;
    }
    qDebug()<<"网络出现故障，连接断开";
    //  qDebug()<<tcpClient.errorString();
    tcpClient.close();

}
