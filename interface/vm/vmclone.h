#ifndef VMCLONE_H
#define VMCLONE_H

#include <QObject>

/*
 * 功能:完成虚拟的克隆,从模板部署虚拟机
 * 编写时间：2013-04-21
 * 具体功能:
 *               |克隆
 *        |开机->|
 * 虚拟机->|       |克隆为模板
 *        |      |克隆
 *        |关机->| 克隆为模板
 *               |转化为模板
 *       | 克隆
 * 模板->| 转化为虚拟机
 *       |从该模板中部署虚拟机
 */

class VMClone : public QObject
{
    Q_OBJECT
public:
    explicit VMClone(QObject *parent = 0);
    static  VMClone* getVMCloneInstance();  //获取单例对象

    void cloneVM(QString hostName, QString  vmName, QString cloneName);  // 克隆虚拟机(开机或关机)
    void  sendcloneVMSignal(QString msg);  //发送cloneVMSignal信号

    void cloneTemplate(QString hostName,QString  templateName, QString cloneName); // 克隆模板 (模板是虚拟机的主镜像)
    void  sendcloneTemplateSignal(QString msg);  //发送cloneTemplateSignal信号

    void cloneVMToTemplate(QString hostName,QString  vmName, QString cloneName) ; // 虚拟机克隆为模板
    void  sendcloneVMToTemplateSignal(QString msg);  //发送cloneVMToTemplateSignal信号

    void cloneTemplatToVM(QString clusterName, QString hostName,QString  templateName, QString cloneName) ; // 从模板部署虚拟机
    void  sendcloneTemplatToVMSignal(QString msg);  //发送cloneTemplatToVMSignal信号

    void vmToTemp( QString hostName,QString  vmName); // 将虚拟机转化为模板
    void  sendvmToTempSignal(QString msg);  //发送vmToTempSignal信号

    void markAsVM(QString clusterName,QString hostName, QString templateName); // 将模板转化为虚拟机
    void  sendmarkAsVMSignal(QString msg);  //发送markAsVMSignal信号


signals:
     void  cloneVMSignal(QString);  //接收数据
     void  cloneTemplateSignal(QString);  //接收数据
     void  cloneVMToTemplateSignal(QString);  //接收数据
     void  cloneTemplatToVMSignal(QString);  //接收数据
     void  vmToTempSignal(QString);  //接收数据
     void  markAsVMSignal(QString);  //接收数据




public slots:

};

#endif // VMCLONE_H
