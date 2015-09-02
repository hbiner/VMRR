#include "uiapp.h"
#include "controller/commonfactory.h"
#include"QDebug"
#include"QMessageBox"
#include"controller/DataPackageSplit.h"
#include<iostream>
using namespace std;


//接收数据
void UIAPP::getInfoSlot(QString msg)
{
//    this->showMsgTestEdit->append(msg);
    DataPackageSplit* da=new DataPackageSplit(msg);
    cout<<"操 作 类 型 : "<<da->getOperationType()<<endl;
    cout<<"序 号 : "<<da->getNumber()<<endl;
    cout<<"操 作 说 明 : "<<da->getOperationDescribe().toStdString()<<endl;
    QStringList* list=da->getInputParameter();
    if(list!=NULL)
    {
        for(int i=0;i<list->length();i++)
        {
            cout<<"客 户 端 参 数 : "<<list->at(i).toStdString()<<"  ";
        }
         cout<<endl;
    }
    else
    {
        cout<<"客 户 端 参 数 : "<<endl;
    }
    QMap<int, QMap<QString,QString> > ma=da->getData();
    cout<<"返 回 数 据 : "<<endl;
    for ( int i=0;i<ma.size();i++ )
    {
        QMap<QString,QString> m2=ma[i];
        QMap<QString,QString>::iterator it; //遍历map
        cout<<"第 "<<i+1<<" 个 数 据 项 "<<endl;
        for ( it = m2.begin(); it != m2.end(); it++ )
        {
            cout<<it.key().toStdString()<<":";
            cout<<it.value().toStdString()<<endl;
        }
    }
}

//buttonA00的槽函数测试枚举类型：GetAllHostName
void  UIAPP::buttonA00SLot()
{
    CommonFactory::getAllHostNameAndMORInstance()->getAllHostNameString();
}


void UIAPP::buttonA10SLot()
{
     //获取主机名
    QString  hostName=lineEdit00->text().trimmed();
    if(hostName!="")
    {
          CommonFactory::getVMNameAndStateInstance()->getVMNameAndStateString(hostName);
    }
    else
    {
        QMessageBox::information(this, tr("系统提示"),tr("请输入第一个文本框中输入主机名称"));
    }

}


 void  UIAPP::buttonA20SLot()
 {
     //获取主机名
    QString  hostName=lineEdit00->text().trimmed();
    if(hostName!="")
    {
          CommonFactory::getHostInfoInstance()->getHostInfoString(hostName);
    }
    else
    {
        QMessageBox::information(this, tr("系统提示"),tr("请输入第一个文本框中输入主机名称"));
    }
 }


 void  UIAPP::buttonA30SLot()
 {
     //获取主机名
     QString  hostName=lineEdit00->text().trimmed();
      QString  vmName=lineEdit01->text().trimmed();
      if(hostName!=""&&vmName!="")
    {
          CommonFactory::getVirtualMachineInfoInstance()->getVirtualMachineInfoString(hostName,vmName);
    }
    else
    {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称"));
    }
 }


 void  UIAPP::buttonA40SLot()
 {
      //参数
     QString  clusterName=lineEdit00->text().trimmed();
     QString  hostName=lineEdit01->text().trimmed();
     QString  userName=lineEdit02->text().trimmed();
     QString  password=lineEdit03->text().trimmed();
     if(clusterName!=""&&hostName!=""&&userName!=""&&password!="")
    {
          CommonFactory::getHostOperationInstance()->addHostToCluster(clusterName,hostName,userName,password);
    }
    else
    {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入集群名车，第二个文本框中输入虚拟机名称,\n第三个文本框中输入主机用户名，第四个文本框中输入主机密码"));
    }
 }
//
 void  UIAPP::buttonA41SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();

    if(hostName!="")
   {
         CommonFactory::getHostOperationInstance()->removeHostFromCluster(hostName);
   }
   else
   {
       QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名."));
   }
 }
//
 void  UIAPP::buttonA42SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();

    if(hostName!="")
   {
         CommonFactory::getHostOperationInstance()->enterMaintenanceMode(hostName);
   }
   else
   {
       QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
   }
 }
//
 void  UIAPP::buttonA43SLot()
{
     //参数
    QString  hostName=lineEdit00->text().trimmed();

    if(hostName!="")
   {
         CommonFactory::getHostOperationInstance()->exitMaintenanceMode(hostName);
   }
   else
   {
      QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
   }
 }
//
 void  UIAPP::buttonA44SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();

    if(hostName!="")
   {
         CommonFactory::getHostOperationInstance()->disconnectHost(hostName);
   }
   else
   {
       QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
   }
 }
//
 void  UIAPP::buttonA45SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();

    if(hostName!="")
   {
         CommonFactory::getHostOperationInstance()->reconnectHost(hostName);
   }
   else
   {
       QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
   }
 }

 //获取主机的全部存储器
 void  UIAPP::buttonA50SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();

    if(hostName!="")
   {
         CommonFactory::getDatastoresByHostInstance()->getDataStores(hostName);
   }
   else
   {
       QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
   }
 }

 //获取主机的全部存储器
 void  UIAPP::buttonB90SLot()
 {
     //getDatastoreSubForder
     //参数
     QString  hostName=lineEdit00->text().trimmed();

     if(hostName!="")
     {
         CommonFactory::getDatastoresByHostInstance()->getDatastoreSubForder(hostName);
     }
     else
     {
         QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
     }
 }
//获取镜像文件
 void  UIAPP::buttonA60SLot()
 {

        CommonFactory::getIsoFileInstance()->getIsoFile();

 }


//获取客户机的操作系统类型
 void  UIAPP::buttonA70SLot()
 {
     CommonFactory::getOtherInformationInstance()->getGuestOsId();
 }

//获取迁移优先级
 void  UIAPP::buttonA71SLot()
 {
         CommonFactory::getOtherInformationInstance()->getvMotionPriority();
 }


 // 克隆虚拟机(开机或关机)
 void   UIAPP::buttonA80SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();
    QString  vmName=lineEdit01->text().trimmed();
    QString  cloneName=lineEdit02->text().trimmed();

    if(hostName==""||vmName==""||cloneName=="")
   {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名,第二个文本框中输入虚拟机名称,第三个文本框中输入克隆体名称,"));
   }
   else
   {
         CommonFactory::getVMCloneInstance()->cloneVM(hostName, vmName, cloneName);

   }


 }

// 克隆模板 (模板是虚拟机的主镜像)
 void   UIAPP::buttonA81SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();
    QString  templateName=lineEdit01->text().trimmed();
    QString  cloneName=lineEdit02->text().trimmed();

    if(hostName==""||templateName==""||cloneName=="")
   {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名,第二个文本框中输入模板【虚拟机】名称,第三个文本框中输入克隆体名称,"));
   }
   else
   {
         CommonFactory::getVMCloneInstance()->cloneTemplate(hostName, templateName, cloneName);

   }

 }
// 虚拟机克隆为模板
 void   UIAPP::buttonA82SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();
    QString  vmName=lineEdit01->text().trimmed();
    QString  cloneName=lineEdit02->text().trimmed();

    if(hostName==""||vmName==""||cloneName=="")
   {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名,第二个文本框中输入虚拟机名称,\n第三个文本框中输入克隆体名称,"));
   }
   else
   {
       CommonFactory::getVMCloneInstance()->cloneVMToTemplate(hostName, vmName, cloneName);
   }

 }
// 从模板部署虚拟机
 void   UIAPP::buttonA83SLot()
 {
     //参数
    QString  clusterName=lineEdit00->text().trimmed();
    QString  hostName=lineEdit01->text().trimmed();
    QString  templateName=lineEdit02->text().trimmed();
    QString  cloneName=lineEdit03->text().trimmed();

    if(clusterName==""||hostName==""||templateName==""||cloneName=="")
   {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入集群名称,请在第二个文本框中输入主机名称,\n第三个文本框中输入模板【虚拟机】名称,第四个文本框中输入克隆体名称,"));
   }
   else
   {
       CommonFactory::getVMCloneInstance()->cloneTemplatToVM(clusterName, hostName, templateName, cloneName);
   }

 }
// 将虚拟机转化为模板
 void   UIAPP::buttonA84SLot()
 {
     //参数
    QString  hostName=lineEdit00->text().trimmed();
    QString  vmName=lineEdit01->text().trimmed();
    if(hostName==""||vmName=="")
   {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
   }
   else
   {
      CommonFactory::getVMCloneInstance()->vmToTemp(hostName, vmName);
   }

 }
// 将模板转化为虚拟机
 void   UIAPP::buttonA85SLot()
 {
     //参数
    QString  clusterName=lineEdit00->text().trimmed();
    QString  hostName=lineEdit01->text().trimmed();
    QString  templateName=lineEdit02->text().trimmed();
    if(clusterName==""||hostName==""||templateName=="""")
   {
        QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入集群名称,请在第二个文本框中输入主机名称,\n第三个文本框中输入模板【虚拟机】名称."));
   }
   else
   {
      CommonFactory::getVMCloneInstance()->markAsVM(clusterName, hostName, templateName);
   }


 }


 //创建虚拟机
 void UIAPP::buttonA90SLot()
  {
      //参数
     QString  hostname=lineEdit00->text().trimmed();
     QString  vmName=lineEdit01->text().trimmed();
     QString  guestOsId=lineEdit02->text().trimmed();

     QString  numCpus=lineEdit03->text().trimmed();
     QString  diskSize=lineEdit04->text().trimmed();
     QString  vmMemorySize=lineEdit05->text().trimmed();

     QString  numNics=lineEdit06->text().trimmed();
     QString  dataStore=lineEdit07->text().trimmed();
     QString  iso=lineEdit08->text().trimmed();

     QString  startVM=lineEdit09->text().trimmed();

     if(     hostname==""||vmName==""||guestOsId==""
          ||numCpus==""||diskSize==""||vmMemorySize==""
          ||numNics==""||dataStore==""||iso==""
          || startVM==""   )


    {
         QMessageBox::information(this, tr("系统提示"),
                                  tr("请在第一个文本框中输入主机名称名称\n第二个文本框中输入虚拟机名称\n第三个文本框中输入客户系统类型名称\n请在第四个文本框中输入cpu个数\n第五个文本框中输入硬盘大小(kB)\n第六个文本框中输入内存大小(MB) \n第七个文本框中输入网卡数量\n第八个文本框中输入目的存储器\n第九个文本框中输入镜像 \n第十个文本框中输入是否启动虚拟机."));
    }
    else
    {
          CommonFactory::getVMCreateInstance()->createVirtualMachine(hostname,vmName,guestOsId
                                                                                                                   ,numCpus,diskSize,vmMemorySize
                                                                                                                   ,numNics,dataStore,iso
                                                                                                                   ,startVM);
    }

  }


 //删除虚拟机
  void UIAPP::buttonB00SLot()
  {
      //参数
     QString  hostName=lineEdit00->text().trimmed();
     QString  vmName=lineEdit01->text().trimmed();
     if(hostName==""||vmName=="")
    {
         QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
    }
    else
    {
       CommonFactory::getVMOtherOpsInstance()->destroyVm(hostName,vmName);
    }
  }
   //从清单中移除虚拟机
  void UIAPP::buttonB01SLot()
  {
      //参数
      QString  hostName=lineEdit00->text().trimmed();
      QString  vmName=lineEdit01->text().trimmed();
      if(hostName==""||vmName=="")
     {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
     }
     else
     {
        CommonFactory::getVMOtherOpsInstance()->unregisterVm(hostName,vmName);
     }

  }
   //虚拟机重命名
  void UIAPP::buttonB02SLot()
  {
      //参数
      QString  hostName=lineEdit00->text().trimmed();
      QString  vmName=lineEdit01->text().trimmed();
       QString  newVmName=lineEdit02->text().trimmed();

       if(hostName==""||vmName==""||newVmName=="")
     {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,第二个文本框中输入虚拟机名称，\n第三个文本框中输入虚拟机的新名称"));
     }
     else
     {
        CommonFactory::getVMOtherOpsInstance()->renameVm(hostName,vmName,newVmName);
     }

  }


// 对虚拟机进行迁移操作
  void UIAPP::buttonB10SLot()
  {
         QString vmname=lineEdit00->text().trimmed();
         QString tcluster=lineEdit01->text().trimmed();
         QString tHost=lineEdit02->text().trimmed();
         QString srcHost=lineEdit03->text().trimmed();
         QString priority=lineEdit04->text().trimmed();

         if(vmname==""||tcluster==""||tHost==""||srcHost==""||priority=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入虚拟机名称,请在第二个文本框中输入目的集群名称.请在第三个文本框中输入目的主机名称，\n请在第四个文本框中输入源主机名称.请在第五个文本框中输入迁移优先级"));

       }
       else
       {
          CommonFactory::getVMotionInstance()->migrateVM(vmname,tcluster,tHost,srcHost,priority);
       }

  }
  // 对虚拟机在同一主机内进行重定位操作
  void UIAPP::buttonB11SLot()
  {
          QString vmname=lineEdit00->text().trimmed();
         QString tcluster=lineEdit01->text().trimmed();
         QString tDS=lineEdit02->text().trimmed();
         QString srcHost=lineEdit03->text().trimmed();
         QString priority=lineEdit04->text().trimmed();

         if(vmname==""||tcluster==""||tDS==""||srcHost==""||priority=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入虚拟机名称,请在第二个文本框中输入目的集群名称.请在第三个文本框中输入目的存储器名称，\n请在第四个文本框中输入源主机名称.请在第五个文本框中输入迁移优先级"));

       }
       else
       {
          CommonFactory::getVMotionInstance()->relocateVMOnSameHost(vmname,tcluster,tDS,srcHost,priority);
       }
  }
  // 对虚拟机在不同主机内进行重定位操作
  void UIAPP::buttonB12SLot()
  {
          QString vmname=lineEdit00->text().trimmed();
         QString tcluster=lineEdit01->text().trimmed();
         QString tHost=lineEdit02->text().trimmed();
         QString tDS=lineEdit03->text().trimmed();
         QString srcHost=lineEdit04->text().trimmed();
         QString priority=lineEdit05->text().trimmed();

         if(vmname==""||tcluster==""||tHost==""||tDS==""||srcHost==""||priority=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入虚拟机名称,请在第二个文本框中输入目的集群名称.请在第三个文本框中输入目的主机名称,\n请在第三个文本框中输入目的存储器名称,请在第四个文本框中输入源主机名称,请在第五个文本框中输入迁移优先级"));


       }
       else
       {
          CommonFactory::getVMotionInstance()->relocateVMOnDifferentHost(vmname,tcluster,tHost,tDS,srcHost,priority);
       }
  }


// 给指定的虚拟机打开电源
  void UIAPP::buttonB20SLot()
  {
          //参数
         QString  hostName=lineEdit00->text().trimmed();
         QString  vmName=lineEdit01->text().trimmed();
         if(hostName==""||vmName=="")
        {
             QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
        }
        else
        {
           CommonFactory::getVMPowerOpsInstance()->powerOnVM(hostName,vmName);
        }
  }
   // 给指定的虚拟机关闭电源
  void UIAPP::buttonB21SLot()
  {
          //参数
         QString  hostName=lineEdit00->text().trimmed();
         QString  vmName=lineEdit01->text().trimmed();
         if(hostName==""||vmName=="")
        {
             QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
        }
        else
        {
           CommonFactory::getVMPowerOpsInstance()->powerOffVM(hostName,vmName);
        }
  }
   // 复位指定的虚拟机
  void UIAPP::buttonB22SLot()
  {
          //参数
         QString  hostName=lineEdit00->text().trimmed();
         QString  vmName=lineEdit01->text().trimmed();
         if(hostName==""||vmName=="")
        {
             QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
        }
        else
        {
           CommonFactory::getVMPowerOpsInstance()->resetVM(hostName,vmName);
        }
  }
  // 挂起指定的虚拟机
  void UIAPP::buttonB23SLot()
  {
          //参数
         QString  hostName=lineEdit00->text().trimmed();
         QString  vmName=lineEdit01->text().trimmed();
         if(hostName==""||vmName=="")
        {
             QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
        }
        else
        {
           CommonFactory::getVMPowerOpsInstance()->suspendVM(hostName,vmName);
        }
  }
//重启客户机
  void UIAPP::buttonB24SLot()
  {
          //参数
         QString  hostName=lineEdit00->text().trimmed();
         QString  vmName=lineEdit01->text().trimmed();
         if(hostName==""||vmName=="")
        {
             QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
        }
        else
        {
           CommonFactory::getVMPowerOpsInstance()->rebootVM(hostName,vmName);
        }
  }
  // 关闭客户机
  void UIAPP::buttonB25SLot()
  {
          //参数
          QString  hostName=lineEdit00->text().trimmed();
          QString  vmName=lineEdit01->text().trimmed();
          if(hostName==""||vmName=="")
         {
              QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
         }
         else
         {
            CommonFactory::getVMPowerOpsInstance()->shutdownVM(hostName,vmName);
         }

  }
  // 启动客户机操作系统待机
  void UIAPP::buttonB26SLot()
   {
          //参数
          QString  hostName=lineEdit00->text().trimmed();
          QString  vmName=lineEdit01->text().trimmed();
          if(hostName==""||vmName=="")
         {
              QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));
         }
         else
         {
            CommonFactory::getVMPowerOpsInstance()->standbyVM(hostName,vmName);
         }

   }


 //创建虚拟机快照
  void UIAPP::buttonB30SLot()
  {
          QString hostName=lineEdit00->text().trimmed();
         QString vmName=lineEdit01->text().trimmed();
         QString snapshotName=lineEdit02->text().trimmed();
         QString desc=lineEdit03->text().trimmed();

         if(hostName==""||vmName==""||snapshotName==""||desc=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称.\n请在第三个文本框中输入快照名称,请在第四个文本框中输入快照描述。"));


       }
       else
       {
          CommonFactory::getVMSnapshotInstance()->createSnapshot(hostName,vmName,snapshotName,desc);
       }

  }
  //列举指定虚拟机的当期的全部快照
  void UIAPP::buttonB31SLot()
  {

          QString hostName=lineEdit00->text().trimmed();
         QString vmName=lineEdit01->text().trimmed();


         if(hostName==""||vmName=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称。"));


       }
       else
       {
          CommonFactory::getVMSnapshotInstance()->listSnapshot(hostName, vmName);
       }

  }
  //恢复到指定的快照
  void UIAPP::buttonB32SLot()
  {
          QString hostName=lineEdit00->text().trimmed();
         QString vmName=lineEdit01->text().trimmed();
         QString snapshotName=lineEdit02->text().trimmed();

         if(hostName==""||vmName==""||snapshotName=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称.\n请在第三个文本框中输入快照名称"));


       }
       else
       {
          CommonFactory::getVMSnapshotInstance()->revertSnapshot(hostName, vmName,snapshotName);
       }


  }
  //恢复到当前快照
  void UIAPP::buttonB33SLot()
  {
          QString hostName=lineEdit00->text().trimmed();
         QString vmName=lineEdit01->text().trimmed();


         if(hostName==""||vmName=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称"));


       }
       else
       {
          CommonFactory::getVMSnapshotInstance()->revertToCurrentSnapshot(hostName, vmName);
       }


  }
   //删除全部快照
  void UIAPP::buttonB34SLot()
  {

          QString hostName=lineEdit00->text().trimmed();
         QString vmName=lineEdit01->text().trimmed();


         if(hostName==""||vmName=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称."));


       }
       else
       {
          CommonFactory::getVMSnapshotInstance()->removeAllSnapshot(hostName, vmName);
       }

  }
   //移除指定的快照
  void UIAPP::buttonB35SLot()
  {
          QString hostName=lineEdit00->text().trimmed();
         QString vmName=lineEdit01->text().trimmed();
         QString snapshotName=lineEdit02->text().trimmed();
         QString removeChild=lineEdit03->text().trimmed();

         if(hostName==""||vmName==""||snapshotName==""||removeChild=="")
       {
            QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名称,请在第二个文本框中输入虚拟机名称.\n请在第三个文本框中输入快照名称,请在第四个文本框中输入是否同时删除其子快照。"));


       }
       else
       {
          CommonFactory::getVMSnapshotInstance()->removeSnapshot(hostName, vmName, snapshotName, removeChild);
       }

  }
  //防火墙默认策略permit
  void UIAPP::buttonB40Slot()
  {
      QString  hostName=lineEdit00->text().trimmed();

      if(hostName!="")
     {
           CommonFactory::getSiteFirewallDefaultPolicyInstance()->enableFirewallDefaultPolicy(hostName);
     }
     else
     {
         QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
     }
  }
  //防火墙默认策略deny
  void UIAPP::buttonB41Slot()
  {
      QString  hostName=lineEdit00->text().trimmed();

      if(hostName!="")
     {
           CommonFactory::getSiteFirewallDefaultPolicyInstance()->undoFirewallDefaultPolicy(hostName);
     }
     else
     {
         QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
     }
  }

  //获取VNCInfo信息
  void UIAPP::buttonB80Slot()
  {
      QString hostName=lineEdit00->text().trimmed();
      QString vmName=lineEdit01->text().trimmed();
      if(hostName==""||vmName=="")
     {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名,请在第二个文本框中输入虚拟机名称"));
     }
     else
     {
          CommonFactory::getVNCInfoInstance()->getVNCInfo(hostName,vmName);
     }
  }

 //获取指定主机下的虚拟机的cpu和memory的信息
  void  UIAPP::buttonB50SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      QString vmName = lineEdit01->text().trimmed();
      if(hostName != "" && vmName != "")
      {
          CommonFactory::getVirtualMachineRuntimeInfoInstance()->getVirtualMachineCpuAndMemoryString(hostName,vmName);
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称"));
      }
  }
  //获取指定主机下的虚拟机的磁盘信息
  void  UIAPP::buttonB51SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      QString vmName = lineEdit01->text().trimmed();
      if(hostName != "" && vmName != "")
      {
          CommonFactory::getVirtualMachineRuntimeInfoInstance()->getVirtualMachineDiskString(hostName,vmName);
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称"));
      }
  }


//查询主机cpu和memory大小及使用率
  void  UIAPP::buttonB60SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      if(hostName != "")
      {
          CommonFactory::getHostRuntimeInfoInstance()->getHostRuntimeInfo(hostName);
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
      }
  }
//查询主机存储器容量及使用率
  void  UIAPP::buttonB61SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      if(hostName != "")
      {
          CommonFactory::getHostRuntimeInfoInstance()->getHostDataStoreInfo(hostName);
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名"));
      }
  }


//对指定主机下的指定主机的cpu重配置
  void  UIAPP::buttonB70SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      QString vmName = lineEdit01->text().trimmed();
      QString cpuNum = lineEdit02->text().trimmed();
      if(hostName != "" && vmName != "" && cpuNum != "")
      {
          CommonFactory::getVirtualMachineReconfigureInstance()->setVirtualMachineCpuNums(hostName,vmName,cpuNum.toInt());
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称,第三个文本框中输入cpu的个数"));
      }
  }
//设置虚拟机memory的大小
  void  UIAPP::buttonB71SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      QString vmName = lineEdit01->text().trimmed();
      QString memorySizeMB = lineEdit02->text().trimmed();
      if(hostName != "" && vmName != "" && memorySizeMB != "")
      {
          CommonFactory::getVirtualMachineReconfigureInstance()->setVirtualMachineMemorySize(hostName,vmName,memorySizeMB.toLong());
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称,第三个文本框中输入内存大小"));
      }

  }
//设置虚拟机虚拟磁盘的大小
  void UIAPP::buttonB72SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      QString vmName = lineEdit01->text().trimmed();
      QString diseSizeGB = lineEdit02->text().trimmed();
      QString diskName = lineEdit03->text().trimmed();
      if(hostName != "" && vmName != "" && diseSizeGB != ""&&diskName !="")
      {
          CommonFactory::getVirtualMachineReconfigureInstance()->setVitualMachineDiskSize(hostName,vmName,diseSizeGB.toInt(),diskName);
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称,第三个文本框中输入磁盘大小"));
      }
  }
//启用虚拟机cpu的热插拔
  void  UIAPP::buttonB73SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      QString vmName = lineEdit01->text().trimmed();
      if(hostName != "" && vmName != "")
      {
          CommonFactory::getVirtualMachineReconfigureInstance()->setVMCpuHotAddAndRemoveEnable(hostName,vmName);
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称"));
      }

  }
//启用虚拟机memory的热增加
  void  UIAPP::buttonB74SLot()
  {
      QString hostName = lineEdit00->text().trimmed();
      QString vmName = lineEdit01->text().trimmed();
      if(hostName != "" && vmName != "")
      {
          CommonFactory::getVirtualMachineReconfigureInstance()->setVMMemoryHotAddEnable(hostName,vmName);
      }
      else
      {
          QMessageBox::information(this, tr("系统提示"),tr("请在第一个文本框中输入主机名，第二个文本框中输入虚拟机名称"));
      }
  }




























