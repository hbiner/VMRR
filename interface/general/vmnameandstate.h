#ifndef VMNAMEANDSTATE_H
#define VMNAMEANDSTATE_H

#include <QObject>
/*
 * 功能:获取指定主机下的全部虚拟机和模板及其状态
 * 编写时间：2013-04-17
 */

class VMNameAndState : public QObject
{
    Q_OBJECT
public:
    explicit VMNameAndState(QObject *parent = 0);
    static  VMNameAndState* getVMNameAndStateInstance();  //获取单例对象

    void  getVMNameAndStateString(QString hostName);  //获取制定主机下的的全部虚拟机的名称和状态
    void  sendgetVMNameAndStateStringSignal(QString msg);  //发送getVMNameAndStateStringSignal信号


signals:
   void getVMNameAndStateStringSignal(QString);  //接收数据

public slots:

};

#endif // VMNAMEANDSTATE_H


