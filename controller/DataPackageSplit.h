#ifndef DATAPACKAGESPLIT_H
#define DATAPACKAGESPLIT_H

#endif // DATAPACKAGESPLIT_H
#include<QString>
#include<QMap>
class DataPackageSplit
{
public:
    DataPackageSplit( );
    DataPackageSplit(QString datapackage);
    int getOperationType(); //获取操作类型
    int getNumber();    //或许序号
    QString getOperationDescribe();//获取操作说明
    QStringList* getInputParameter();//获取客户端参数
    QMap<int, QMap<QString,QString> > getData();    //获取返回数据
private:
    int operationtype;//操作类型
    int number;// 序号
    QString operationdescribe;//操作说明
    QStringList* inputparameter;//获取客户端参数
    QMap<int, QMap<QString,QString> > data;  //返回数据
    QString  msgTypeSplitData;//报文头部和数据的分割符
    QString betweenDataItemSplit; //数据项和数据项的分割符
    QString reqParSplit;//请求参数分割符号
    QString WithinDataItemSplit;// 数据项内部的分隔符
    QString propertySplitValue;//指定属性和值得分割符
    void dealData(QString datapackage);
};

