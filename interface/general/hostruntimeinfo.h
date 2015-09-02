#ifndef HOSTRUNTIMEINFO_H
#define HOSTRUNTIMEINFO_H

#include <QObject>

/*
 * 功能：获取指定主机运行是信息
 */
class HostRuntimeInfo : public QObject
{
    Q_OBJECT
public:
    explicit HostRuntimeInfo(QObject *parent = 0);
      static HostRuntimeInfo *getHostRuntimeInfoInstance(); //获取HostRuntimeInfo类的单例

    void getHostRuntimeInfo(QString hostName); //查询主机cpu和memory大小及使用率
    void sendgetHostRuntimeInfoSignal(QString msg); //返回主机cpu和memory大小及使用率

    void getHostDataStoreInfo(QString hostName); //查询主机存储器容量及使用率
    void sendgetHostDataStoreInfoSignal(QString msg);//返回主机存储器容量及使用率



signals:
    void getHostRuntimeInfoSignal(QString msg);
    void getHostDataStoreInfoSignal(QString msg);

public slots:

};

#endif // HOSTRUNTIMEINFO_H
