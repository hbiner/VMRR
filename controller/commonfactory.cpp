#include "commonfactory.h"

CommonFactory::CommonFactory(QObject *parent) :
    QObject(parent)
{
}

 //获取AllHostNameAndMOR类的单例对象
AllHostNameAndMOR* CommonFactory::getAllHostNameAndMORInstance()
{
    return AllHostNameAndMOR::getAllHostNameAndMORInstance();
}



//获取VMNameAndState类的单例对象
VMNameAndState* CommonFactory::getVMNameAndStateInstance()
{
   return VMNameAndState::getVMNameAndStateInstance();
}

//获取HostInfo类单例对象
HostInfo* CommonFactory::getHostInfoInstance()
{
   return HostInfo::getHostInfoInstance();
}
//获取VirtualMachineInfo类单例对象
 VirtualMachineInfo* CommonFactory::getVirtualMachineInfoInstance()
 {
    return  VirtualMachineInfo::getVirtualMachineInfoInstance();
 }
 //获取DatastoresByHost类单例对象
   DatastoresByHost* CommonFactory::getDatastoresByHostInstance()
   {
       return DatastoresByHost::getDatastoresByHostInstance();
   }
   //获取IsoFile类单例对象
   IsoFile* CommonFactory::getIsoFileInstance()
   {
       return  IsoFile::getIsoFileInstance();
   }
    //获取OtherInformation类单例对象
   OtherInformation* CommonFactory::getOtherInformationInstance()
   {
        return  OtherInformation::getOtherInformationInstance();
   }



//获取HostOperation类单例对象
 HostOperation* CommonFactory::getHostOperationInstance()
{
    return HostOperation::getHostOperationInstance();
}

//获取VMClone类单例对象
VMClone*  CommonFactory::getVMCloneInstance()
{
   return VMClone::getVMCloneInstance();
}
//获取VMCreate类单例对象
VMCreate*  CommonFactory::getVMCreateInstance()
{
   return VMCreate::getVMCreateInstance();
}
//获取VMOtherOps类单例对象
VMOtherOps*  CommonFactory::getVMOtherOpsInstance()
{
   return VMOtherOps::getVMOtherOpsInstance();
}
//获取VMotion类单例对象
VMotion*  CommonFactory::getVMotionInstance()
{
   return VMotion::getVMotionInstance();
}
//获取VMPowerOps类单例对象
VMPowerOps*  CommonFactory::getVMPowerOpsInstance()
{
 return VMPowerOps::getVMPowerOpsInstance();
}
//获取VMSnapshot类单例对象
VMSnapshot*  CommonFactory::getVMSnapshotInstance()
{
   return VMSnapshot::getVMSnapshotInstance();
}


//获取HostRuntimeInfo类单例对象
HostRuntimeInfo * CommonFactory::getHostRuntimeInfoInstance()
{
    return HostRuntimeInfo::getHostRuntimeInfoInstance();
}

//获取VirtualMachineReconfigure类单例对象
VirtualMachineReconfigure * CommonFactory::getVirtualMachineReconfigureInstance()
{
    return VirtualMachineReconfigure::getVirtualMachineReconfigureInstance();
}

//获取VirtualMachineRuntimeInfo类单例对象
VirtualMachineRuntimeInfo * CommonFactory::getVirtualMachineRuntimeInfoInstance()
{
    return VirtualMachineRuntimeInfo::getVirtualMachineRuntimeInfoInstance();
}
//获取sitefirewalldefaultpolicy类单例对象
SiteFirewallDefaultPolicy *CommonFactory::getSiteFirewallDefaultPolicyInstance()
{
    return SiteFirewallDefaultPolicy::getSiteFirewallDefaultPolicyInstance();
}
//获取VNCInfo类的单例对象
VNCInfo* CommonFactory::getVNCInfoInstance()
{
    return VNCInfo::getVNCinfoInstance();
}
