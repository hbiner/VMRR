#ifndef HOSTOPERATION_H
#define HOSTOPERATION_H

#include <QObject>

/*
 * 功能：完成主机的基本操作（添加，移除，进入维护模式，推出维护模式，断开，重新连接）
 * 编写时间：2013-04-15
 */

class HostOperation : public QObject
{
    Q_OBJECT
public:
    explicit HostOperation(QObject *parent = 0);
    static  HostOperation* getHostOperationInstance();  //获取单例对象

     void  addHostToCluster(QString clusterName,QString hostName,QString userName,QString password);   //添加主机到集群
     void  sendaddHostToClusterSignal(QString msg);  //发送信号

     void  removeHostFromCluster(QString hostName);   //将主机从集群中移除
      void  sendremoveHostFromClusterSignal(QString msg);  //发送信号

     void  enterMaintenanceMode(QString hostName);    //将主机进入维护模式
      void  sendenterMaintenanceModeSignal(QString msg);  //发送信号

     void  exitMaintenanceMode(QString hostName);  //将主机退出维护模式
      void  sendexitMaintenanceModeSignal(QString msg);  //发送信号

     void  disconnectHost(QString hostName);   //断开与主机的连接
      void  senddisconnectHostSignal(QString msg);  //发送信号

     void  reconnectHost(QString hostName);   //重新与主机进行连接
      void  sendreconnectHostSignal(QString msg);  //发送信号


signals:
     void addHostToClusterSignal(QString);  //添加主机到集群
     void removeHostFromClusterSignal(QString);  //将主机从集群中移除
     void enterMaintenanceModeSignal(QString);  //将主机进入维护模式
     void exitMaintenanceModeSignal(QString);  //将主机退出维护模式
     void disconnectHostSignal(QString);   //断开与主机的连接
     void reconnectHostSignal(QString);    //重新与主机进行连接

public slots:

};

#endif // HOSTOPERATION_H
