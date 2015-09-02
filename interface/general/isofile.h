#ifndef ISOFILE_H
#define ISOFILE_H

#include <QObject>

/*
 * 功能:用于获取创建虚拟机时所需要的镜像文件
 * 编写时间：2013-04-24
 */

class IsoFile : public QObject
{
    Q_OBJECT
public:
    explicit IsoFile(QObject *parent = 0);
    static  IsoFile* getIsoFileInstance();  //获取单例对象

    void  getIsoFile();  //获取全部镜像文件
    void  sendgetIsoFileSignal(QString msg);  //发送getIsoFileSignal信号


signals:
       void  getIsoFileSignal(QString);  //接收数据

public slots:

};

#endif // ISOFILE_H
