#ifndef OTHERINFORMATION_H
#define OTHERINFORMATION_H

#include <QObject>

/*
 * 功能:获取其他信息
 * 编写时间：2013-04-24
 * 信息:客户机操作系统类型,迁移优先级
 */
class OtherInformation : public QObject
{
    Q_OBJECT
public:
    explicit OtherInformation(QObject *parent = 0);
    static  OtherInformation* getOtherInformationInstance();  //获取单例对象

    void  getGuestOsId();  //获取客户机操作类型
    void  sendgetGuestOsIdSignal(QString msg);  //发送getGuestOsIdSignal信号

    void  getvMotionPriority();  //获取迁移优先级
    void  sendgetvMotionPrioritySignal(QString msg);  //发送getvMotionPrioritySignal信号


signals:
      void  getGuestOsIdSignal(QString);  //接收数据
      void  getvMotionPrioritySignal(QString);  //接收数据



public slots:

};

#endif // OTHERINFORMATION_H
