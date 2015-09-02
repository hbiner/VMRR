#include "uiapp.h"
#include<QVBoxLayout>
#include "controller/commonfactory.h"

UIAPP::UIAPP(QWidget *parent) :
    QDialog(parent)
{

    //显示从服务器返回的消息
    showMsgTestEdit=new QTextEdit();

    //10个参数编辑框
    lineEdit00=new QLineEdit();
    lineEdit01=new QLineEdit();
    lineEdit02=new QLineEdit();
    lineEdit03=new QLineEdit();
    lineEdit04=new QLineEdit();
    lineEdit05=new QLineEdit();
    lineEdit06=new QLineEdit();
    lineEdit07=new QLineEdit();
    lineEdit08=new QLineEdit();
    lineEdit09=new QLineEdit();


    //A组

     //AllHostNameAndMOR类测试使用
    { 
        buttonA00=new QPushButton("所有主机名");
        buttonA01=new QPushButton("A01");
        buttonA02=new QPushButton("A02");
        buttonA03=new QPushButton("A03");
        buttonA04=new QPushButton("A04");
        buttonA05=new QPushButton("A05");
        buttonA06=new QPushButton("A06");
        buttonA07=new QPushButton("A07");
        buttonA08=new QPushButton("A08");
        buttonA09=new QPushButton("A09");
        //获取所有主机名
        connect(buttonA00, SIGNAL(clicked()), this, SLOT(buttonA00SLot()));
        connect(CommonFactory::getAllHostNameAndMORInstance(),SIGNAL( getAllHostNameStringSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

    }

    //VMNameAndState类测试使用
   {
        buttonA10=new QPushButton("主机全部VM名");
        buttonA11=new QPushButton("A11");
        buttonA12=new QPushButton("A12");
        buttonA13=new QPushButton("A13");
        buttonA14=new QPushButton("A14");
        buttonA15=new QPushButton("A15");
        buttonA16=new QPushButton("A16");
        buttonA17=new QPushButton("A17");
        buttonA18=new QPushButton("A18");
        buttonA19=new QPushButton("A19");

        //指定主机下全部虚拟机名称的状态
        connect(buttonA10, SIGNAL(clicked()), this, SLOT(buttonA10SLot()));
        connect(CommonFactory::getVMNameAndStateInstance(),SIGNAL( getVMNameAndStateStringSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

    }

    //HostInfo类测试使用
   {
        buttonA20=new QPushButton("指定主机信息");
        buttonA21=new QPushButton("A21");
        buttonA22=new QPushButton("A22");
        buttonA23=new QPushButton("A23");
        buttonA24=new QPushButton("A24");
        buttonA25=new QPushButton("A25");
        buttonA26=new QPushButton("A26");
        buttonA27=new QPushButton("A27");
        buttonA28=new QPushButton("A28");
        buttonA29=new QPushButton("A29");

        //指定主机详情信息
        connect(buttonA20, SIGNAL(clicked()), this, SLOT(buttonA20SLot()));
        connect(CommonFactory::getHostInfoInstance(),SIGNAL( getHostInfoStringSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

    }


    //VirtualMachineInfo类测试使用
    {
        buttonA30=new QPushButton("主机下Vm信息");
        buttonA31=new QPushButton("A31");
        buttonA32=new QPushButton("A32");
        buttonA33=new QPushButton("A33");
        buttonA34=new QPushButton("A34");
        buttonA35=new QPushButton("A35");
        buttonA36=new QPushButton("A36");
        buttonA37=new QPushButton("A37");
        buttonA38=new QPushButton("A38");
        buttonA39=new QPushButton("A39");

        //获取指定主机下指定虚拟机的详情信息
        connect(buttonA30, SIGNAL(clicked()), this, SLOT(buttonA30SLot()));
        connect(CommonFactory::getVirtualMachineInfoInstance(),SIGNAL( getVirtualMachineInfoStringSignal(QString)),
                this,SLOT(getInfoSlot(QString)));
    }

    //HostOperation类测试使用
   {
        buttonA40=new QPushButton("添加主机到集群");
        buttonA41=new QPushButton("主机从集群移除");
        buttonA42=new QPushButton("进入维护模式");
        buttonA43=new QPushButton("退出维护模式");
        buttonA44=new QPushButton("断开连接");
        buttonA45=new QPushButton("重新连接");
        buttonA46=new QPushButton("A46");
        buttonA47=new QPushButton("A47");
        buttonA48=new QPushButton("A48");
        buttonA49=new QPushButton("A49");


         //添加主机到集群
        connect(buttonA40, SIGNAL(clicked()), this, SLOT(buttonA40SLot()));
        connect(CommonFactory::getHostOperationInstance(),SIGNAL( addHostToClusterSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

         //将主机从集群中移除
        connect(buttonA41, SIGNAL(clicked()), this, SLOT(buttonA41SLot()));
        connect(CommonFactory::getHostOperationInstance(),SIGNAL( removeHostFromClusterSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //将主机进入维护模式
        connect(buttonA42, SIGNAL(clicked()), this, SLOT(buttonA42SLot()));
        connect(CommonFactory::getHostOperationInstance(),SIGNAL( enterMaintenanceModeSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //将主机退出维护模式
        connect(buttonA43, SIGNAL(clicked()), this, SLOT(buttonA43SLot()));
        connect(CommonFactory::getHostOperationInstance(),SIGNAL( exitMaintenanceModeSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //断开与主机的连接
        connect(buttonA44, SIGNAL(clicked()), this, SLOT(buttonA44SLot()));
        connect(CommonFactory::getHostOperationInstance(),SIGNAL( disconnectHostSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

         //重新与主机进行连接
        connect(buttonA45, SIGNAL(clicked()), this, SLOT(buttonA45SLot()));
        connect(CommonFactory::getHostOperationInstance(),SIGNAL( reconnectHostSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

    }

    //DatastoresByHost类测试使用
 {
        buttonA50=new QPushButton("主机的存储器");
        buttonA51=new QPushButton("");
        buttonA52=new QPushButton("A52");
        buttonA53=new QPushButton("A53");
        buttonA54=new QPushButton("A54");
        buttonA55=new QPushButton("A55");
        buttonA56=new QPushButton("A56");
        buttonA57=new QPushButton("A57");
        buttonA58=new QPushButton("A58");
        buttonA59=new QPushButton("A59");

        //获取指定主机的存储器
       connect(buttonA50, SIGNAL(clicked()), this, SLOT(buttonA50SLot()));
       connect(CommonFactory::getDatastoresByHostInstance(),SIGNAL( getDataStoresSignal(QString)),
               this,SLOT(getInfoSlot(QString)));


 }

  //IsoFile类测试使用
  {
        buttonA60=new QPushButton("镜像文件");
        buttonA61=new QPushButton("A61");
        buttonA62=new QPushButton("A62");
        buttonA63=new QPushButton("A63");
        buttonA64=new QPushButton("A64");
        buttonA65=new QPushButton("A65");
        buttonA66=new QPushButton("A66");
        buttonA67=new QPushButton("A67");
        buttonA68=new QPushButton("A68");
        buttonA69=new QPushButton("A69");

        //获取镜像文件
       connect(buttonA60, SIGNAL(clicked()), this, SLOT(buttonA60SLot()));
       connect(CommonFactory::getIsoFileInstance(),SIGNAL( getIsoFileSignal(QString)),
               this,SLOT(getInfoSlot(QString)));
  }

//OtherInformation类测试使用
{
        buttonA70=new QPushButton("客户机OS类型");
        buttonA71=new QPushButton("迁移优先级");
        buttonA72=new QPushButton("A72");
        buttonA73=new QPushButton("A73");
        buttonA74=new QPushButton("A74");
        buttonA75=new QPushButton("A75");
        buttonA76=new QPushButton("A76");
        buttonA77=new QPushButton("A77");
        buttonA78=new QPushButton("A78");
        buttonA79=new QPushButton("A79");

        //获取客户机操作系统类型
       connect(buttonA70, SIGNAL(clicked()), this, SLOT(buttonA70SLot()));
       connect(CommonFactory::getOtherInformationInstance(),SIGNAL( getGuestOsIdSignal(QString)),
               this,SLOT(getInfoSlot(QString)));

       //获取虚拟机迁移优先级
      connect(buttonA71, SIGNAL(clicked()), this, SLOT(buttonA71SLot()));
      connect(CommonFactory::getOtherInformationInstance(),SIGNAL( getvMotionPrioritySignal(QString)),
              this,SLOT(getInfoSlot(QString)));
}

    //VMClone类测试使用
    {
            buttonA80=new QPushButton("克隆虚拟机");
            buttonA81=new QPushButton("克隆模板");
            buttonA82=new QPushButton("虚拟机克隆为模板");
            buttonA83=new QPushButton("从模板部署虚拟机");
            buttonA84=new QPushButton("虚拟机转化为模板");
            buttonA85=new QPushButton("模板转化为虚拟机");
            buttonA86=new QPushButton("A86");
            buttonA87=new QPushButton("A87");
            buttonA88=new QPushButton("A88");
            buttonA89=new QPushButton("A89");


            // 克隆虚拟机(开机或关机)
           connect(buttonA80, SIGNAL(clicked()), this, SLOT(buttonA80SLot()));
           connect(CommonFactory::getVMCloneInstance(),SIGNAL( cloneVMSignal(QString)),
                   this,SLOT(getInfoSlot(QString)));

           // 克隆模板 (模板是虚拟机的主镜像)
          connect(buttonA81, SIGNAL(clicked()), this, SLOT(buttonA81SLot()));
          connect(CommonFactory::getVMCloneInstance(),SIGNAL( cloneTemplateSignal(QString)),
                  this,SLOT(getInfoSlot(QString)));

         // 虚拟机克隆为模板
         connect(buttonA82, SIGNAL(clicked()), this, SLOT(buttonA82SLot()));
         connect(CommonFactory::getVMCloneInstance(),SIGNAL( cloneVMToTemplateSignal(QString)),
                 this,SLOT(getInfoSlot(QString)));

         // 从模板部署虚拟机
        connect(buttonA83, SIGNAL(clicked()), this, SLOT(buttonA83SLot()));
        connect(CommonFactory::getVMCloneInstance(),SIGNAL( cloneTemplatToVMSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

       // 将虚拟机转化为模板
       connect(buttonA84, SIGNAL(clicked()), this, SLOT(buttonA84SLot()));
       connect(CommonFactory::getVMCloneInstance(),SIGNAL( vmToTempSignal(QString)),
               this,SLOT(getInfoSlot(QString)));

     // 将模板转化为虚拟机
      connect(buttonA85, SIGNAL(clicked()), this, SLOT(buttonA85SLot()));
      connect(CommonFactory::getVMCloneInstance(),SIGNAL( markAsVMSignal(QString)),
              this,SLOT(getInfoSlot(QString)));
    }

    //VMCreate类测试使用
    {
        buttonA90=new QPushButton("创建虚拟机");
        buttonA91=new QPushButton("A91");
        buttonA92=new QPushButton("A92");
        buttonA93=new QPushButton("A93");
        buttonA94=new QPushButton("A94");
        buttonA95=new QPushButton("A95");
        buttonA96=new QPushButton("A96");
        buttonA97=new QPushButton("A97");
        buttonA98=new QPushButton("A98");
        buttonA99=new QPushButton("A99");

        // 创建虚拟机
         connect(buttonA90, SIGNAL(clicked()), this, SLOT(buttonA90SLot()));
         connect(CommonFactory::getVMCreateInstance(),SIGNAL( createVirtualMachineSignal(QString)),
                 this,SLOT(getInfoSlot(QString)));

    }


    //B组
    //VMOtherOps类测试使用
    {
        buttonB00=new QPushButton("删除虚拟机");
        buttonB01=new QPushButton("移除虚拟机");
        buttonB02=new QPushButton("虚拟机重命名");
        buttonB03=new QPushButton("B03");
        buttonB04=new QPushButton("B04");
        buttonB05=new QPushButton("B05");
        buttonB06=new QPushButton("B06");
        buttonB07=new QPushButton("B07");
        buttonB08=new QPushButton("B08");
        buttonB09=new QPushButton("B09");

        //删除虚拟机
         connect(buttonB00, SIGNAL(clicked()), this, SLOT(buttonB00SLot()));
         connect(CommonFactory::getVMOtherOpsInstance(),SIGNAL( destroyVmSignal(QString)),
                 this,SLOT(getInfoSlot(QString)));

        //从清单中移除虚拟机
          connect(buttonB01, SIGNAL(clicked()), this, SLOT(buttonB01SLot()));
          connect(CommonFactory::getVMOtherOpsInstance(),SIGNAL( unregisterVmSignal(QString)),
                  this,SLOT(getInfoSlot(QString)));

         //虚拟机重命名
           connect(buttonB02, SIGNAL(clicked()), this, SLOT(buttonB02SLot()));
           connect(CommonFactory::getVMOtherOpsInstance(),SIGNAL( renameVmSignal(QString)),
                   this,SLOT(getInfoSlot(QString)));

    }

   //VMotion类测试使用
    {
        buttonB10=new QPushButton("虚拟机迁移");
        buttonB11=new QPushButton("同一主机内重定位");
        buttonB12=new QPushButton("不同主机内重定位");
        buttonB13=new QPushButton("B13");
        buttonB14=new QPushButton("B14");
        buttonB15=new QPushButton("B15");
        buttonB16=new QPushButton("B16");
        buttonB17=new QPushButton("B17");
        buttonB18=new QPushButton("B18");
        buttonB19=new QPushButton("B19");

      // 对虚拟机进行迁移操作
         connect(buttonB10, SIGNAL(clicked()), this, SLOT(buttonB10SLot()));
         connect(CommonFactory::getVMotionInstance(),SIGNAL( migrateVMSignal(QString)),
                 this,SLOT(getInfoSlot(QString)));

        // 对虚拟机在同一主机内进行重定位操作
          connect(buttonB11, SIGNAL(clicked()), this, SLOT(buttonB11SLot()));
          connect(CommonFactory::getVMotionInstance(),SIGNAL( relocateVMOnSameHostSignal(QString)),
                  this,SLOT(getInfoSlot(QString)));

         // 对虚拟机在不同主机内进行重定位操作
           connect(buttonB12, SIGNAL(clicked()), this, SLOT(buttonB12SLot()));
           connect(CommonFactory::getVMotionInstance(),SIGNAL( relocateVMOnDifferentHostSignal(QString)),
                   this,SLOT(getInfoSlot(QString)));
    }

   //VMPowerOps类测试使用
    {
        buttonB20=new QPushButton("打开电源");
        buttonB21=new QPushButton("关闭电源");
        buttonB22=new QPushButton("复位");
        buttonB23=new QPushButton("挂起");
        buttonB24=new QPushButton("重启客户机");
        buttonB25=new QPushButton("关闭客户机");
        buttonB26=new QPushButton("启动客户机待机");
        buttonB27=new QPushButton("B27");
        buttonB28=new QPushButton("B28");
        buttonB29=new QPushButton("B29");


        // 给指定的虚拟机打开电源
           connect(buttonB20, SIGNAL(clicked()), this, SLOT(buttonB20SLot()));
           connect(CommonFactory::getVMPowerOpsInstance(),SIGNAL( powerOnVMSignal(QString)),
                   this,SLOT(getInfoSlot(QString)));

      // 给指定的虚拟机关闭电源
          connect(buttonB21, SIGNAL(clicked()), this, SLOT(buttonB21SLot()));
          connect(CommonFactory::getVMPowerOpsInstance(),SIGNAL( powerOffVMSignal(QString)),
                  this,SLOT(getInfoSlot(QString)));

    // 复位指定的虚拟机
         connect(buttonB22, SIGNAL(clicked()), this, SLOT(buttonB22SLot()));
         connect(CommonFactory::getVMPowerOpsInstance(),SIGNAL( resetVMSignal(QString)),
                 this,SLOT(getInfoSlot(QString)));

        // 挂起指定的虚拟机
            connect(buttonB23, SIGNAL(clicked()), this, SLOT(buttonB23SLot()));
            connect(CommonFactory::getVMPowerOpsInstance(),SIGNAL( suspendVMSignal(QString)),
                    this,SLOT(getInfoSlot(QString)));

      //重启客户机
           connect(buttonB24, SIGNAL(clicked()), this, SLOT(buttonB24SLot()));
           connect(CommonFactory::getVMPowerOpsInstance(),SIGNAL( rebootVMSignal(QString)),
                   this,SLOT(getInfoSlot(QString)));

         // 关闭客户机
              connect(buttonB25, SIGNAL(clicked()), this, SLOT(buttonB25SLot()));
              connect(CommonFactory::getVMPowerOpsInstance(),SIGNAL( shutdownVMSignal(QString)),
                      this,SLOT(getInfoSlot(QString)));

      // 启动客户机操作系统待机
              connect(buttonB26, SIGNAL(clicked()), this, SLOT(buttonB26SLot()));
              connect(CommonFactory::getVMPowerOpsInstance(),SIGNAL( standbyVMSignal(QString)),
                     this,SLOT(getInfoSlot(QString)));

    }

   //VMSnapshot类测试使用
    {
        buttonB30=new QPushButton("创建快照");
        buttonB31=new QPushButton("列举全部快照");
        buttonB32=new QPushButton("恢复到指定快照");
        buttonB33=new QPushButton("恢复到当前快照");
        buttonB34=new QPushButton("删除全部快照");
        buttonB35=new QPushButton("移除指定的快照");
        buttonB36=new QPushButton("B36");
        buttonB37=new QPushButton("B37");
        buttonB38=new QPushButton("B38");
        buttonB39=new QPushButton("B39");

        //创建虚拟机快照
           connect(buttonB30, SIGNAL(clicked()), this, SLOT(buttonB30SLot()));
           connect(CommonFactory::getVMSnapshotInstance(),SIGNAL( createSnapshotSignal(QString)),
                   this,SLOT(getInfoSlot(QString)));

      //列举指定虚拟机的当期的全部快照
          connect(buttonB31, SIGNAL(clicked()), this, SLOT(buttonB31SLot()));
          connect(CommonFactory::getVMSnapshotInstance(),SIGNAL( listSnapshotSignal(QString)),
                  this,SLOT(getInfoSlot(QString)));

      //恢复到指定的快照
         connect(buttonB32, SIGNAL(clicked()), this, SLOT(buttonB32SLot()));
         connect(CommonFactory::getVMSnapshotInstance(),SIGNAL( revertSnapshotSignal(QString)),
                 this,SLOT(getInfoSlot(QString)));

     //恢复到当前快照
        connect(buttonB33, SIGNAL(clicked()), this, SLOT(buttonB33SLot()));
        connect(CommonFactory::getVMSnapshotInstance(),SIGNAL( revertToCurrentSnapshotSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

       //删除全部快照
           connect(buttonB34, SIGNAL(clicked()), this, SLOT(buttonB34SLot()));
           connect(CommonFactory::getVMSnapshotInstance(),SIGNAL( removeAllSnapshotSignal(QString)),
                   this,SLOT(getInfoSlot(QString)));

        //移除指定的快照
          connect(buttonB35, SIGNAL(clicked()), this, SLOT(buttonB35SLot()));
          connect(CommonFactory::getVMSnapshotInstance(),SIGNAL( removeSnapshotSignal(QString)),
                  this,SLOT(getInfoSlot(QString)));
    }


    //sitefirewalldefaultpolicy类测试使用
    {
        buttonB40=new QPushButton("指定主机默认开启防火墙");
        buttonB41=new QPushButton("指定主机默认关闭防火墙");
        buttonB42=new QPushButton("B42");
        buttonB43=new QPushButton("B43");
        buttonB44=new QPushButton("B44");
        buttonB45=new QPushButton("B45");
        buttonB46=new QPushButton("B46");
        buttonB47=new QPushButton("B47");
        buttonB48=new QPushButton("B48");
        buttonB49=new QPushButton("B49");
        //指定主机默认开启防火墙
        connect(buttonB40,SIGNAL(clicked()),this,SLOT(buttonB40Slot()));
        connect(CommonFactory::getSiteFirewallDefaultPolicyInstance(),SIGNAL(enableFirewallDefaultPolicySignals(QString)),
                this,SLOT(getInfoSlot(QString)));
        //指定主机默认关闭防火墙
        connect(buttonB41,SIGNAL(clicked()),this,SLOT(buttonB41Slot()));
        connect(CommonFactory::getSiteFirewallDefaultPolicyInstance(),SIGNAL(undoFirewallDefaultPolicySignals(QString)),
                this,SLOT(getInfoSlot(QString)));
    }



    //VirtualMachineRuntimeInfo类测试使用
   {
        buttonB50=new QPushButton("虚拟机的cpu和memory信息");
        buttonB51=new QPushButton("虚拟机的磁盘信息");
        buttonB52=new QPushButton("B52");
        buttonB53=new QPushButton("B53");
        buttonB54=new QPushButton("B54");
        buttonB55=new QPushButton("B55");
        buttonB56=new QPushButton("B56");
        buttonB57=new QPushButton("B57");
        buttonB58=new QPushButton("B58");
        buttonB59=new QPushButton("B59");

         //获取指定主机下的虚拟机的cpu和memory的信息
        connect(buttonB50,SIGNAL(clicked()),this,SLOT(buttonB50SLot()));
        connect(CommonFactory::getVirtualMachineRuntimeInfoInstance(),SIGNAL(getVirtualMachineCpuAndMemoryStringSignal(QString)),
                this,SLOT(getInfoSlot(QString)));
          //获取指定主机下的虚拟机的磁盘信息
        connect(buttonB51,SIGNAL(clicked()),this,SLOT(buttonB51SLot()));
        connect(CommonFactory::getVirtualMachineRuntimeInfoInstance(),SIGNAL(getVirtualMachineDiskStringSignal(QString)),
                this,SLOT(getInfoSlot(QString)));
    }

    //HostRuntimeInfo类测试使用
    {

        buttonB60=new QPushButton("主机cpu和memory使用率");
        buttonB61=new QPushButton("主机存储器容量及使用率");
        buttonB62=new QPushButton("B62");
        buttonB63=new QPushButton("B63");
        buttonB64=new QPushButton("B64");
        buttonB65=new QPushButton("B65");
        buttonB66=new QPushButton("B66");
        buttonB67=new QPushButton("B67");
        buttonB68=new QPushButton("B68");
        buttonB69=new QPushButton("B69");

        //查询主机cpu和memory大小及使用率
        connect(buttonB60,SIGNAL(clicked()),this,SLOT(buttonB60SLot()));
        connect(CommonFactory::getHostRuntimeInfoInstance(),SIGNAL(getHostRuntimeInfoSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //查询主机存储器容量及使用率
        connect(buttonB61,SIGNAL(clicked()),this,SLOT(buttonB61SLot()));
        connect(CommonFactory::getHostRuntimeInfoInstance(),SIGNAL(getHostDataStoreInfoSignal(QString)),
                this,SLOT(getInfoSlot(QString)));
     }


   //VirtualMachineReconfigure类测试使用
    {
        buttonB70=new QPushButton("虚拟机的cpu重配置");
        buttonB71=new QPushButton("设置虚拟机memory");
        buttonB72=new QPushButton("设置虚拟机虚拟磁盘");
        buttonB73=new QPushButton("启用虚拟机cpu的热插拔");
        buttonB74=new QPushButton("启用虚拟机memory的热增加");
        buttonB75=new QPushButton("B75");
        buttonB76=new QPushButton("B76");
        buttonB77=new QPushButton("B77");
        buttonB78=new QPushButton("B78");
        buttonB79=new QPushButton("B79");

        //对指定主机下的指定虚拟机的cpu重配置
        connect(buttonB70,SIGNAL(clicked()),this,SLOT(buttonB70SLot()));
        connect(CommonFactory::getVirtualMachineReconfigureInstance(),SIGNAL(setVirtualMachineCpuNumsSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //设置虚拟机memory的大小
        connect(buttonB71,SIGNAL(clicked()),this,SLOT(buttonB71SLot()));
        connect(CommonFactory::getVirtualMachineReconfigureInstance(),SIGNAL(setVirtualMachineMemorySizeSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //设置虚拟机虚拟磁盘的大小
        connect(buttonB72,SIGNAL(clicked()),this,SLOT(buttonB72SLot()));
        connect(CommonFactory::getVirtualMachineReconfigureInstance(),SIGNAL(setVitualMachineDiskSizeSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //启用虚拟机cpu的热插拔
        connect(buttonB73,SIGNAL(clicked()),this,SLOT(buttonB73SLot()));
        connect(CommonFactory::getVirtualMachineReconfigureInstance(),SIGNAL(setVMCpuHotAddAndRemoveEnableSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

        //启用虚拟机memory的热增加
        connect(buttonB74,SIGNAL(clicked()),this,SLOT(buttonB74SLot()));
        connect(CommonFactory::getVirtualMachineReconfigureInstance(),SIGNAL(setVMMemoryHotAddEnableSignal(QString)),
                this,SLOT(getInfoSlot(QString)));

     }








    //VNCInfo类测试使用
{
    buttonB80=new QPushButton("获取指定虚拟机VNC信息");
    buttonB81=new QPushButton("B81");
    buttonB82=new QPushButton("B82");
    buttonB83=new QPushButton("B83");
    buttonB84=new QPushButton("B84");
    buttonB85=new QPushButton("B85");
    buttonB86=new QPushButton("B86");
    buttonB87=new QPushButton("B87");
    buttonB88=new QPushButton("B88");
    buttonB89=new QPushButton("B89");
    connect(buttonB80,SIGNAL(clicked()),this,SLOT(buttonB80Slot()));
    connect(CommonFactory::getVNCInfoInstance(),SIGNAL(getVNCInfoSignals(QString)),
            this,SLOT(getInfoSlot(QString)));
}

    buttonB90=new QPushButton("存储器的文件夹");
    buttonB91=new QPushButton("B91");
    buttonB92=new QPushButton("B92");
    buttonB93=new QPushButton("B93");
    buttonB94=new QPushButton("B94");
    buttonB95=new QPushButton("B95");
    buttonB96=new QPushButton("B96");
    buttonB97=new QPushButton("B97");
    buttonB98=new QPushButton("B98");
    buttonB99=new QPushButton("B99");
    //获取存储器的文件夹
   connect(buttonB90, SIGNAL(clicked()), this, SLOT(buttonB90SLot()));
   connect(CommonFactory::getDatastoresByHostInstance(),SIGNAL( getDatastoreSubForderSignal(QString)),
           this,SLOT(getInfoSlot(QString)));
//    buttonC00=new QPushButton("C00");
//    buttonC01=new QPushButton("C01");
//    buttonC02=new QPushButton("C02");
//    buttonC03=new QPushButton("C03");
//    buttonC04=new QPushButton("C04");
//    buttonC05=new QPushButton("C05");
//    buttonC06=new QPushButton("C06");
//    buttonC07=new QPushButton("C07");
//    buttonC08=new QPushButton("C08");
//    buttonC09=new QPushButton("C09");
//    buttonC10=new QPushButton("C10");
//    buttonC11=new QPushButton("C11");
//    buttonC12=new QPushButton("C12");
//    buttonC13=new QPushButton("C13");
//    buttonC14=new QPushButton("C14");
//    buttonC15=new QPushButton("C15");
//    buttonC16=new QPushButton("C16");
//    buttonC17=new QPushButton("C17");
//    buttonC18=new QPushButton("C18");
//    buttonC19=new QPushButton("C19");
//    buttonC20=new QPushButton("C20");
//    buttonC21=new QPushButton("C21");
//    buttonC22=new QPushButton("C22");
//    buttonC23=new QPushButton("C23");
//    buttonC24=new QPushButton("C24");
//    buttonC25=new QPushButton("C25");
//    buttonC26=new QPushButton("C26");
//    buttonC27=new QPushButton("C27");
//    buttonC28=new QPushButton("C28");
//    buttonC29=new QPushButton("C29");
//    buttonC30=new QPushButton("C30");
//    buttonC31=new QPushButton("C31");
//    buttonC32=new QPushButton("C32");
//    buttonC33=new QPushButton("C33");
//    buttonC34=new QPushButton("C34");
//    buttonC35=new QPushButton("C35");
//    buttonC36=new QPushButton("C36");
//    buttonC37=new QPushButton("C37");
//    buttonC38=new QPushButton("C38");
//    buttonC39=new QPushButton("C39");
//    buttonC40=new QPushButton("C40");
//    buttonC41=new QPushButton("C41");
//    buttonC42=new QPushButton("C42");
//    buttonC43=new QPushButton("C43");
//    buttonC44=new QPushButton("C44");
//    buttonC45=new QPushButton("C45");
//    buttonC46=new QPushButton("C46");
//    buttonC47=new QPushButton("C47");
//    buttonC48=new QPushButton("C48");
//    buttonC49=new QPushButton("C49");
//    buttonC50=new QPushButton("C50");
//    buttonC51=new QPushButton("C51");
//    buttonC52=new QPushButton("C52");
//    buttonC53=new QPushButton("C53");
//    buttonC54=new QPushButton("C54");
//    buttonC55=new QPushButton("C55");
//    buttonC56=new QPushButton("C56");
//    buttonC57=new QPushButton("C57");
//    buttonC58=new QPushButton("C58");
//    buttonC59=new QPushButton("C59");
//    buttonC60=new QPushButton("C60");
//    buttonC61=new QPushButton("C61");
//    buttonC62=new QPushButton("C62");
//    buttonC63=new QPushButton("C63");
//    buttonC64=new QPushButton("C64");
//    buttonC65=new QPushButton("C65");
//    buttonC66=new QPushButton("C66");
//    buttonC67=new QPushButton("C67");
//    buttonC68=new QPushButton("C68");
//    buttonC69=new QPushButton("C69");
//    buttonC70=new QPushButton("C70");
//    buttonC71=new QPushButton("C71");
//    buttonC72=new QPushButton("C72");
//    buttonC73=new QPushButton("C73");
//    buttonC74=new QPushButton("C74");
//    buttonC75=new QPushButton("C75");
//    buttonC76=new QPushButton("C76");
//    buttonC77=new QPushButton("C77");
//    buttonC78=new QPushButton("C78");
//    buttonC79=new QPushButton("C79");
//    buttonC80=new QPushButton("C80");
//    buttonC81=new QPushButton("C81");
//    buttonC82=new QPushButton("C82");
//    buttonC83=new QPushButton("C83");
//    buttonC84=new QPushButton("C84");
//    buttonC85=new QPushButton("C85");
//    buttonC86=new QPushButton("C86");
//    buttonC87=new QPushButton("C87");
//    buttonC88=new QPushButton("C88");
//    buttonC89=new QPushButton("C89");
//    buttonC90=new QPushButton("C90");
//    buttonC91=new QPushButton("C91");
//    buttonC92=new QPushButton("C92");
//    buttonC93=new QPushButton("C93");
//    buttonC94=new QPushButton("C94");
//    buttonC95=new QPushButton("C95");
//    buttonC96=new QPushButton("C96");
//    buttonC97=new QPushButton("C97");
//    buttonC98=new QPushButton("C98");
//    buttonC99=new QPushButton("C99");


    QGridLayout *gridLayout=new QGridLayout();
     //A组
    gridLayout->addWidget(buttonA00,0,0,1,1);
    gridLayout->addWidget(buttonA01,0,1,1,1);
    gridLayout->addWidget(buttonA02,0,2,1,1);
    gridLayout->addWidget(buttonA03,0,3,1,1);
    gridLayout->addWidget(buttonA04,0,4,1,1);
    gridLayout->addWidget(buttonA05,0,5,1,1);
    gridLayout->addWidget(buttonA06,0,6,1,1);
    gridLayout->addWidget(buttonA07,0,7,1,1);
    gridLayout->addWidget(buttonA08,0,8,1,1);
    gridLayout->addWidget(buttonA09,0,9,1,1);
    gridLayout->addWidget(buttonA10,1,0,1,1);
    gridLayout->addWidget(buttonA11,1,1,1,1);
    gridLayout->addWidget(buttonA12,1,2,1,1);
    gridLayout->addWidget(buttonA13,1,3,1,1);
    gridLayout->addWidget(buttonA14,1,4,1,1);
    gridLayout->addWidget(buttonA15,1,5,1,1);
    gridLayout->addWidget(buttonA16,1,6,1,1);
    gridLayout->addWidget(buttonA17,1,7,1,1);
    gridLayout->addWidget(buttonA18,1,8,1,1);
    gridLayout->addWidget(buttonA19,1,9,1,1);
    gridLayout->addWidget(buttonA20,2,0,1,1);
    gridLayout->addWidget(buttonA21,2,1,1,1);
    gridLayout->addWidget(buttonA22,2,2,1,1);
    gridLayout->addWidget(buttonA23,2,3,1,1);
    gridLayout->addWidget(buttonA24,2,4,1,1);
    gridLayout->addWidget(buttonA25,2,5,1,1);
    gridLayout->addWidget(buttonA26,2,6,1,1);
    gridLayout->addWidget(buttonA27,2,7,1,1);
    gridLayout->addWidget(buttonA28,2,8,1,1);
    gridLayout->addWidget(buttonA29,2,9,1,1);
    gridLayout->addWidget(buttonA30,3,0,1,1);
    gridLayout->addWidget(buttonA31,3,1,1,1);
    gridLayout->addWidget(buttonA32,3,2,1,1);
    gridLayout->addWidget(buttonA33,3,3,1,1);
    gridLayout->addWidget(buttonA34,3,4,1,1);
    gridLayout->addWidget(buttonA35,3,5,1,1);
    gridLayout->addWidget(buttonA36,3,6,1,1);
    gridLayout->addWidget(buttonA37,3,7,1,1);
    gridLayout->addWidget(buttonA38,3,8,1,1);
    gridLayout->addWidget(buttonA39,3,9,1,1);
    gridLayout->addWidget(buttonA40,4,0,1,1);
    gridLayout->addWidget(buttonA41,4,1,1,1);
    gridLayout->addWidget(buttonA42,4,2,1,1);
    gridLayout->addWidget(buttonA43,4,3,1,1);
    gridLayout->addWidget(buttonA44,4,4,1,1);
    gridLayout->addWidget(buttonA45,4,5,1,1);
    gridLayout->addWidget(buttonA46,4,6,1,1);
    gridLayout->addWidget(buttonA47,4,7,1,1);
    gridLayout->addWidget(buttonA48,4,8,1,1);
    gridLayout->addWidget(buttonA49,4,9,1,1);
    gridLayout->addWidget(buttonA50,5,0,1,1);
    gridLayout->addWidget(buttonA51,5,1,1,1);
    gridLayout->addWidget(buttonA52,5,2,1,1);
    gridLayout->addWidget(buttonA53,5,3,1,1);
    gridLayout->addWidget(buttonA54,5,4,1,1);
    gridLayout->addWidget(buttonA55,5,5,1,1);
    gridLayout->addWidget(buttonA56,5,6,1,1);
    gridLayout->addWidget(buttonA57,5,7,1,1);
    gridLayout->addWidget(buttonA58,5,8,1,1);
    gridLayout->addWidget(buttonA59,5,9,1,1);
    gridLayout->addWidget(buttonA60,6,0,1,1);
    gridLayout->addWidget(buttonA61,6,1,1,1);
    gridLayout->addWidget(buttonA62,6,2,1,1);
    gridLayout->addWidget(buttonA63,6,3,1,1);
    gridLayout->addWidget(buttonA64,6,4,1,1);
    gridLayout->addWidget(buttonA65,6,5,1,1);
    gridLayout->addWidget(buttonA66,6,6,1,1);
    gridLayout->addWidget(buttonA67,6,7,1,1);
    gridLayout->addWidget(buttonA68,6,8,1,1);
    gridLayout->addWidget(buttonA69,6,9,1,1);
    gridLayout->addWidget(buttonA70,7,0,1,1);
    gridLayout->addWidget(buttonA71,7,1,1,1);
    gridLayout->addWidget(buttonA72,7,2,1,1);
    gridLayout->addWidget(buttonA73,7,3,1,1);
    gridLayout->addWidget(buttonA74,7,4,1,1);
    gridLayout->addWidget(buttonA75,7,5,1,1);
    gridLayout->addWidget(buttonA76,7,6,1,1);
    gridLayout->addWidget(buttonA77,7,7,1,1);
    gridLayout->addWidget(buttonA78,7,8,1,1);
    gridLayout->addWidget(buttonA79,7,9,1,1);
    gridLayout->addWidget(buttonA80,8,0,1,1);
    gridLayout->addWidget(buttonA81,8,1,1,1);
    gridLayout->addWidget(buttonA82,8,2,1,1);
    gridLayout->addWidget(buttonA83,8,3,1,1);
    gridLayout->addWidget(buttonA84,8,4,1,1);
    gridLayout->addWidget(buttonA85,8,5,1,1);
    gridLayout->addWidget(buttonA86,8,6,1,1);
    gridLayout->addWidget(buttonA87,8,7,1,1);
    gridLayout->addWidget(buttonA88,8,8,1,1);
    gridLayout->addWidget(buttonA89,8,9,1,1);
    gridLayout->addWidget(buttonA90,9,0,1,1);
    gridLayout->addWidget(buttonA91,9,1,1,1);
    gridLayout->addWidget(buttonA92,9,2,1,1);
    gridLayout->addWidget(buttonA93,9,3,1,1);
    gridLayout->addWidget(buttonA94,9,4,1,1);
    gridLayout->addWidget(buttonA95,9,5,1,1);
    gridLayout->addWidget(buttonA96,9,6,1,1);
    gridLayout->addWidget(buttonA97,9,7,1,1);
    gridLayout->addWidget(buttonA98,9,8,1,1);
    gridLayout->addWidget(buttonA99,9,9,1,1);

    //B组
    gridLayout->addWidget(buttonB00,10,0,1,1);
    gridLayout->addWidget(buttonB01,10,1,1,1);
    gridLayout->addWidget(buttonB02,10,2,1,1);
    gridLayout->addWidget(buttonB03,10,3,1,1);
    gridLayout->addWidget(buttonB04,10,4,1,1);
    gridLayout->addWidget(buttonB05,10,5,1,1);
    gridLayout->addWidget(buttonB06,10,6,1,1);
    gridLayout->addWidget(buttonB07,10,7,1,1);
    gridLayout->addWidget(buttonB08,10,8,1,1);
    gridLayout->addWidget(buttonB09,10,9,1,1);
    gridLayout->addWidget(buttonB10,11,0,1,1);
    gridLayout->addWidget(buttonB11,11,1,1,1);
    gridLayout->addWidget(buttonB12,11,2,1,1);
    gridLayout->addWidget(buttonB13,11,3,1,1);
    gridLayout->addWidget(buttonB14,11,4,1,1);
    gridLayout->addWidget(buttonB15,11,5,1,1);
    gridLayout->addWidget(buttonB16,11,6,1,1);
    gridLayout->addWidget(buttonB17,11,7,1,1);
    gridLayout->addWidget(buttonB18,11,8,1,1);
    gridLayout->addWidget(buttonB19,11,9,1,1);
    gridLayout->addWidget(buttonB20,12,0,1,1);
    gridLayout->addWidget(buttonB21,12,1,1,1);
    gridLayout->addWidget(buttonB22,12,2,1,1);
    gridLayout->addWidget(buttonB23,12,3,1,1);
    gridLayout->addWidget(buttonB24,12,4,1,1);
    gridLayout->addWidget(buttonB25,12,5,1,1);
    gridLayout->addWidget(buttonB26,12,6,1,1);
    gridLayout->addWidget(buttonB27,12,7,1,1);
    gridLayout->addWidget(buttonB28,12,8,1,1);
    gridLayout->addWidget(buttonB29,12,9,1,1);
    gridLayout->addWidget(buttonB30,13,0,1,1);
    gridLayout->addWidget(buttonB31,13,1,1,1);
    gridLayout->addWidget(buttonB32,13,2,1,1);
    gridLayout->addWidget(buttonB33,13,3,1,1);
    gridLayout->addWidget(buttonB34,13,4,1,1);
    gridLayout->addWidget(buttonB35,13,5,1,1);
    gridLayout->addWidget(buttonB36,13,6,1,1);
    gridLayout->addWidget(buttonB37,13,7,1,1);
    gridLayout->addWidget(buttonB38,13,8,1,1);
    gridLayout->addWidget(buttonB39,13,9,1,1);

    gridLayout->addWidget(buttonB40,14,0,1,1);
    gridLayout->addWidget(buttonB41,14,1,1,1);
    gridLayout->addWidget(buttonB42,14,2,1,1);
    gridLayout->addWidget(buttonB43,14,3,1,1);
    gridLayout->addWidget(buttonB44,14,4,1,1);
    gridLayout->addWidget(buttonB45,14,5,1,1);
    gridLayout->addWidget(buttonB46,14,6,1,1);
    gridLayout->addWidget(buttonB47,14,7,1,1);
    gridLayout->addWidget(buttonB48,14,8,1,1);
    gridLayout->addWidget(buttonB49,14,9,1,1);
    gridLayout->addWidget(buttonB80,15,0,1,1);
    gridLayout->addWidget(buttonB81,15,1,1,1);
    gridLayout->addWidget(buttonB82,15,2,1,1);
    gridLayout->addWidget(buttonB83,15,3,1,1);
    gridLayout->addWidget(buttonB84,15,4,1,1);
    gridLayout->addWidget(buttonB85,15,5,1,1);
    gridLayout->addWidget(buttonB86,15,6,1,1);
    gridLayout->addWidget(buttonB87,15,7,1,1);
    gridLayout->addWidget(buttonB88,15,8,1,1);
    gridLayout->addWidget(buttonB89,15,9,1,1);
    gridLayout->addWidget(buttonB90,16,0,1,1);
    gridLayout->addWidget(buttonB91,16,1,1,1);
    gridLayout->addWidget(buttonB92,16,2,1,1);
    gridLayout->addWidget(buttonB93,16,3,1,1);
    gridLayout->addWidget(buttonB94,16,4,1,1);
    gridLayout->addWidget(buttonB95,16,5,1,1);
    gridLayout->addWidget(buttonB96,16,6,1,1);
    gridLayout->addWidget(buttonB97,16,7,1,1);
    gridLayout->addWidget(buttonB98,16,8,1,1);
    gridLayout->addWidget(buttonB99,16,9,1,1);

    gridLayout->addWidget(buttonB50,17,0,1,1);
    gridLayout->addWidget(buttonB51,17,1,1,1);
    gridLayout->addWidget(buttonB52,17,2,1,1);
    gridLayout->addWidget(buttonB53,17,3,1,1);
    gridLayout->addWidget(buttonB54,17,4,1,1);
    gridLayout->addWidget(buttonB55,17,5,1,1);
    gridLayout->addWidget(buttonB56,17,6,1,1);
    gridLayout->addWidget(buttonB57,17,7,1,1);
    gridLayout->addWidget(buttonB58,17,8,1,1);
    gridLayout->addWidget(buttonB59,17,9,1,1);


    gridLayout->addWidget(buttonB60,18,0,1,1);
    gridLayout->addWidget(buttonB61,18,1,1,1);
    gridLayout->addWidget(buttonB62,18,2,1,1);
    gridLayout->addWidget(buttonB63,18,3,1,1);
    gridLayout->addWidget(buttonB64,18,4,1,1);
    gridLayout->addWidget(buttonB65,18,5,1,1);
    gridLayout->addWidget(buttonB66,18,6,1,1);
    gridLayout->addWidget(buttonB67,18,7,1,1);
    gridLayout->addWidget(buttonB68,18,8,1,1);
    gridLayout->addWidget(buttonB69,18,9,1,1);

    gridLayout->addWidget(buttonB70,19,0,1,1);
    gridLayout->addWidget(buttonB71,19,1,1,1);
    gridLayout->addWidget(buttonB72,19,2,1,1);
    gridLayout->addWidget(buttonB73,19,3,1,1);
    gridLayout->addWidget(buttonB74,19,4,1,1);
    gridLayout->addWidget(buttonB75,19,5,1,1);
    gridLayout->addWidget(buttonB76,19,6,1,1);
    gridLayout->addWidget(buttonB77,19,7,1,1);
    gridLayout->addWidget(buttonB78,19,8,1,1);
    gridLayout->addWidget(buttonB79,19,9,1,1);



//    //C组
//    gridLayout->addWidget(buttonC00,20,0,1,1);
//    gridLayout->addWidget(buttonC01,20,1,1,1);
//    gridLayout->addWidget(buttonC02,20,2,1,1);
//    gridLayout->addWidget(buttonC03,20,3,1,1);
//    gridLayout->addWidget(buttonC04,20,4,1,1);
//    gridLayout->addWidget(buttonC05,20,5,1,1);
//    gridLayout->addWidget(buttonC06,20,6,1,1);
//    gridLayout->addWidget(buttonC07,20,7,1,1);
//    gridLayout->addWidget(buttonC08,20,8,1,1);
//    gridLayout->addWidget(buttonC09,20,9,1,1);
//    gridLayout->addWidget(buttonC10,21,0,1,1);
//    gridLayout->addWidget(buttonC11,21,1,1,1);
//    gridLayout->addWidget(buttonC12,21,2,1,1);
//    gridLayout->addWidget(buttonC13,21,3,1,1);
//    gridLayout->addWidget(buttonC14,21,4,1,1);
//    gridLayout->addWidget(buttonC15,21,5,1,1);
//    gridLayout->addWidget(buttonC16,21,6,1,1);
//    gridLayout->addWidget(buttonC17,21,7,1,1);
//    gridLayout->addWidget(buttonC18,21,8,1,1);
//    gridLayout->addWidget(buttonC19,21,9,1,1);
//    gridLayout->addWidget(buttonC20,22,0,1,1);
//    gridLayout->addWidget(buttonC21,22,1,1,1);
//    gridLayout->addWidget(buttonC22,22,2,1,1);
//    gridLayout->addWidget(buttonC23,22,3,1,1);
//    gridLayout->addWidget(buttonC24,22,4,1,1);
//    gridLayout->addWidget(buttonC25,22,5,1,1);
//    gridLayout->addWidget(buttonC26,22,6,1,1);
//    gridLayout->addWidget(buttonC27,22,7,1,1);
//    gridLayout->addWidget(buttonC28,22,8,1,1);
//    gridLayout->addWidget(buttonC29,22,9,1,1);
//    gridLayout->addWidget(buttonC30,23,0,1,1);
//    gridLayout->addWidget(buttonC31,23,1,1,1);
//    gridLayout->addWidget(buttonC32,23,2,1,1);
//    gridLayout->addWidget(buttonC33,23,3,1,1);
//    gridLayout->addWidget(buttonC34,23,4,1,1);
//    gridLayout->addWidget(buttonC35,23,5,1,1);
//    gridLayout->addWidget(buttonC36,23,6,1,1);
//    gridLayout->addWidget(buttonC37,23,7,1,1);
//    gridLayout->addWidget(buttonC38,23,8,1,1);
//    gridLayout->addWidget(buttonC39,23,9,1,1);
//    gridLayout->addWidget(buttonC40,24,0,1,1);
//    gridLayout->addWidget(buttonC41,24,1,1,1);
//    gridLayout->addWidget(buttonC42,24,2,1,1);
//    gridLayout->addWidget(buttonC43,24,3,1,1);
//    gridLayout->addWidget(buttonC44,24,4,1,1);
//    gridLayout->addWidget(buttonC45,24,5,1,1);
//    gridLayout->addWidget(buttonC46,24,6,1,1);
//    gridLayout->addWidget(buttonC47,24,7,1,1);
//    gridLayout->addWidget(buttonC48,24,8,1,1);
//    gridLayout->addWidget(buttonC49,24,9,1,1);
//    gridLayout->addWidget(buttonC50,25,0,1,1);
//    gridLayout->addWidget(buttonC51,25,1,1,1);
//    gridLayout->addWidget(buttonC52,25,2,1,1);
//    gridLayout->addWidget(buttonC53,25,3,1,1);
//    gridLayout->addWidget(buttonC54,25,4,1,1);
//    gridLayout->addWidget(buttonC55,25,5,1,1);
//    gridLayout->addWidget(buttonC56,25,6,1,1);
//    gridLayout->addWidget(buttonC57,25,7,1,1);
//    gridLayout->addWidget(buttonC58,25,8,1,1);
//    gridLayout->addWidget(buttonC59,25,9,1,1);
//    gridLayout->addWidget(buttonC60,26,0,1,1);
//    gridLayout->addWidget(buttonC61,26,1,1,1);
//    gridLayout->addWidget(buttonC62,26,2,1,1);
//    gridLayout->addWidget(buttonC63,26,3,1,1);
//    gridLayout->addWidget(buttonC64,26,4,1,1);
//    gridLayout->addWidget(buttonC65,26,5,1,1);
//    gridLayout->addWidget(buttonC66,26,6,1,1);
//    gridLayout->addWidget(buttonC67,26,7,1,1);
//    gridLayout->addWidget(buttonC68,26,8,1,1);
//    gridLayout->addWidget(buttonC69,26,9,1,1);
//    gridLayout->addWidget(buttonC70,27,0,1,1);
//    gridLayout->addWidget(buttonC71,27,1,1,1);
//    gridLayout->addWidget(buttonC72,27,2,1,1);
//    gridLayout->addWidget(buttonC73,27,3,1,1);
//    gridLayout->addWidget(buttonC74,27,4,1,1);
//    gridLayout->addWidget(buttonC75,27,5,1,1);
//    gridLayout->addWidget(buttonC76,27,6,1,1);
//    gridLayout->addWidget(buttonC77,27,7,1,1);
//    gridLayout->addWidget(buttonC78,27,8,1,1);
//    gridLayout->addWidget(buttonC79,27,9,1,1);
//    gridLayout->addWidget(buttonC80,28,0,1,1);
//    gridLayout->addWidget(buttonC81,28,1,1,1);
//    gridLayout->addWidget(buttonC82,28,2,1,1);
//    gridLayout->addWidget(buttonC83,28,3,1,1);
//    gridLayout->addWidget(buttonC84,28,4,1,1);
//    gridLayout->addWidget(buttonC85,28,5,1,1);
//    gridLayout->addWidget(buttonC86,28,6,1,1);
//    gridLayout->addWidget(buttonC87,28,7,1,1);
//    gridLayout->addWidget(buttonC88,28,8,1,1);
//    gridLayout->addWidget(buttonC89,28,9,1,1);
//    gridLayout->addWidget(buttonC90,29,0,1,1);
//    gridLayout->addWidget(buttonC91,29,1,1,1);
//    gridLayout->addWidget(buttonC92,29,2,1,1);
//    gridLayout->addWidget(buttonC93,29,3,1,1);
//    gridLayout->addWidget(buttonC94,29,4,1,1);
//    gridLayout->addWidget(buttonC95,29,5,1,1);
//    gridLayout->addWidget(buttonC96,29,6,1,1);
//    gridLayout->addWidget(buttonC97,29,7,1,1);
//    gridLayout->addWidget(buttonC98,29,8,1,1);
//    gridLayout->addWidget(buttonC99,29,9,1,1);

    gridLayout->addWidget(lineEdit00,20,0,1,1);
    gridLayout->addWidget(lineEdit01,20,1,1,1);
    gridLayout->addWidget(lineEdit02,20,2,1,1);
    gridLayout->addWidget(lineEdit03,20,3,1,1);
    gridLayout->addWidget(lineEdit04,20,4,1,1);
    gridLayout->addWidget(lineEdit05,20,5,1,1);
    gridLayout->addWidget(lineEdit06,20,6,1,1);
    gridLayout->addWidget(lineEdit07,20,7,1,1);
    gridLayout->addWidget(lineEdit08,20,8,1,1);
    gridLayout->addWidget(lineEdit09,20,9,1,1);

    gridLayout->addWidget(showMsgTestEdit,21,0,3,10);

    setLayout(gridLayout);
    setWindowTitle(tr("APP临时测试界面"));
    setMinimumSize(800,700);
}
