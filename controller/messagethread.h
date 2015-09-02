#ifndef MESSAGETHREAD_H
#define MESSAGETHREAD_H

#include <QObject>
#include<QTcpSocket>

/*
 * 功能：构建与指定主机的一条TCP链接，同时负责接收和发送数据
 * 编写时间：2013-04-15
 * 说明:该类的单例会在整个应用程序运行的过程中一直运行，不会被释放掉
 */

class MessageThread : public QObject
{
    Q_OBJECT
public:
    explicit MessageThread(QObject *parent = 0);
    static  MessageThread * getMessageThreadInstance();//获取单例对象

    void conn();  //与服务器进行连接
    void closeConn();//与服务器断开连接
    void sendData(QString data); //发送数据
    qint64  getNumberOfCommand();//获取序列号
    QString  getMsgTypeSplitData();//获取报文头部和数据的分割符
    QString  getBetweenDataItemSplit();//获取数据项和数据项的分割符
    QString  getReqParSplit();//获取请求参数分割符号
    QString  getWithinDataItemSplit();// 数据项内部的分隔符
    QString  getpropertySplitValue();//指定属性和值得分割符


private:
    QString  IP;  //服务器IP地址
    int port;      //端口号
    QTcpSocket tcpClient; //socket对象
    QByteArray outBlock;//发送数据的字节数组
    QByteArray inBlock; //接受数据的字节数组
    bool connState; //连接状态

    QString  msgTypeSplitData;//报文头部和数据的分割符
    QString betweenDataItemSplit; //数据项和数据项的分割符
    QString reqParSplit;//请求参数分割符号
    QString WithinDataItemSplit; // 数据项内部的分隔符
    QString propertySplitValue;//指定属性和值得分割符
    qint64 numberOfCommand;  //消息序列号

 //   static MessageThread *messageThread;   //定义单例对象

signals:

public slots:
    void successconnectedSlot();  ////与服务器连接成功
    void successSendDataSlot(qint64 numBytes);//显示已经成功发送发送数据
    void receiveDataSlot();//接受数据
    void displayErrorSlot(QAbstractSocket::SocketError socketError); //显示TCP错误信息



};

#endif // MESSAGETHREAD_H
