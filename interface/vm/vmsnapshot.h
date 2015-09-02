#ifndef VMSNAPSHOT_H
#define VMSNAPSHOT_H

#include <QObject>

/*
 * 功能:完成虚拟的查看快照、创建快照、删除指定快照、删除全部快照、恢复指定快照、恢复到当前快照
 * 编写时间：2013-04-21
 */
class VMSnapshot : public QObject
{
    Q_OBJECT
public:
    explicit VMSnapshot(QObject *parent = 0);
    static  VMSnapshot* getVMSnapshotInstance();  //获取单例对象

    void  createSnapshot(QString hostName,QString vmName,QString snapshotName,QString desc)	;  //创建虚拟机快照
    void  sendcreateSnapshotSignal(QString msg);  //发送createSnapshotSignal信号

    void  listSnapshot(QString hostName, QString vmName)	;  //列举指定虚拟机的当期的全部快照
    void  sendlistSnapshotSignal(QString msg);  //发送listSnapshotSignal信号

    void  revertSnapshot(QString hostName,QString  vmName,QString snapshotName);	  //恢复到指定的快照
    void  sendrevertSnapshotSignal(QString msg);  //发送revertSnapshotSignal信号

    void  revertToCurrentSnapshot(QString hostName,QString  vmName);	 //恢复到当前快照
    void  sendrevertToCurrentSnapshotSignal(QString msg);  //发送revertToCurrentSnapshotSignal信号

    void  removeAllSnapshot(QString hostName,QString vmName);	    //删除全部快照
    void  sendremoveAllSnapshotSignal(QString msg);  //发送removeAllSnapshotSignal信号

    void  removeSnapshot(QString hostName,QString  vmName,QString  snapshotName,QString removeChild);   //移除指定的快照
    void  sendremoveSnapshotSignal(QString msg);  //发送removeSnapshotSignal信号


signals:
       void  createSnapshotSignal(QString);  //接收数据
       void  listSnapshotSignal(QString);  //接收数据
       void  revertSnapshotSignal(QString);  //接收数据
       void  revertToCurrentSnapshotSignal(QString);  //接收数据
       void  removeAllSnapshotSignal(QString);  //接收数据
       void  removeSnapshotSignal(QString);  //接收数据

public slots:

};

#endif // VMSNAPSHOT_H
