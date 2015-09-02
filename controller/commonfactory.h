#ifndef COMMONFACTORY_H
#define COMMONFACTORY_H

#include <QObject>

#include"interface/general/allhostnameandmor.h"
#include"interface/general/vmnameandstate.h"
#include"interface/general/hostinfo.h"
#include"interface/general/virtualmachineinfo.h"
#include"interface/general/datastoresbyhost.h"
#include"interface/general/isofile.h"
#include"interface/general/otherinformation.h"

#include"interface/host/hostoperation.h"

#include"interface/vm/vmclone.h"
#include"interface/vm/vmcreate.h"
#include"interface/vm/vmotherops.h"
#include"interface/vm/vmotion.h"
#include"interface/vm/vmpowerops.h"
#include"interface/vm/vmsnapshot.h"
#include"interface/general/hostruntimeinfo.h"
#include"interface/general/virtualmachineruntimeinfo.h"
#include"interface/vm/virtualmachinereconfigure.h"
#include<interface/host/sitefirewalldefaultpolicy.h>
#include<interface/general/vncinfo.h>
/*
 * 功能：工厂类
 * 编写时间：2013-04-16
 * 说明:该类的用于获取interface目录下的全部类的单例对象
 */

class CommonFactory : public QObject
{
    Q_OBJECT
public:
    explicit CommonFactory(QObject *parent = 0);

      //获取全部接口类的单例对象

      static  AllHostNameAndMOR* getAllHostNameAndMORInstance();  //获取AllHostNameAndMOR类的单例对象
      static  VMNameAndState* getVMNameAndStateInstance();  //获取VMNameAndState类的单例对象
      static  HostInfo* getHostInfoInstance();  //获取HostInfo类单例对象
      static  VirtualMachineInfo* getVirtualMachineInfoInstance();  //获取VirtualMachineInfo类单例对象

      static  DatastoresByHost* getDatastoresByHostInstance();  //获取DatastoresByHost类单例对象
      static  IsoFile* getIsoFileInstance();  //获取IsoFile类单例对象
      static  OtherInformation* getOtherInformationInstance();  //获取OtherInformation类单例对象

      static  HostOperation* getHostOperationInstance();  //获取HostOperation类单例对象

      static  VMClone* getVMCloneInstance();  //获取VMClone类单例对象
      static  VMCreate* getVMCreateInstance();  //获取VMCreate类单例对象
      static  VMOtherOps* getVMOtherOpsInstance();  //获取VMOtherOps类单例对象
      static  VMotion* getVMotionInstance();  //获取VMotion类单例对象
      static  VMPowerOps* getVMPowerOpsInstance();  //获取VMPowerOps类单例对象
      static  VMSnapshot* getVMSnapshotInstance();  //获取VMSnapshot类单例对象

      static  HostRuntimeInfo* getHostRuntimeInfoInstance();//获取HostRuntimeInfo类单例对象
      static  VirtualMachineReconfigure* getVirtualMachineReconfigureInstance();//获取VirtualMachineReconfigure类单例对象
      static  VirtualMachineRuntimeInfo* getVirtualMachineRuntimeInfoInstance();//获取VirtualMachineRuntimeInfo类单例对象
      static  SiteFirewallDefaultPolicy* getSiteFirewallDefaultPolicyInstance();//获取SiteFirewallDefaultPolicy类单例对象
      static  VNCInfo* getVNCInfoInstance();//获取VNCInfo类单例对象


signals:

public slots:

};

#endif // COMMONFACTORY_H
