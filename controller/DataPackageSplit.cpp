
#include"DataPackageSplit.h"
#include<QStringList>
#include<iostream>
#include"messagethread.h"
using namespace std;

//返回数据处理
void DataPackageSplit::dealData(QString datapackage)
{
    QStringList list= datapackage.split(this->msgTypeSplitData);
    QStringList head=list.at(0).split(this->betweenDataItemSplit);
    this->operationtype= head.at(0).toInt();
    this->number=head.at(1).toInt();
    if(head.at(2)!="")
    {
    this->operationdescribe=head.at(2);
    }
    else
    {
        this->operationdescribe="";
    }
    this->inputparameter=new QStringList();
    if(head.at(3)!="")
    {
        QStringList tempstringlist=head.at(3).split(this->reqParSplit);
        if(tempstringlist.at(tempstringlist.size()-1)=="")
        {
             tempstringlist.removeAt(tempstringlist.size()-1);
        }
    *(this->inputparameter)=tempstringlist;
    }
    else
    {
     this->inputparameter=NULL;
    }
    if(list.at(1)!="")
    {
    QStringList data=list.at(1).split(this->betweenDataItemSplit);

    for(int i=0;i<data.size();i++)
    {
        if(data.at(i)=="")
        {
          continue;
        }QStringList element=data.at(i).split(this->WithinDataItemSplit);
        QMap<QString,QString> temp;
        for(int j=0;j<element.size();j++)
        {
            if(element.at(j).indexOf(this->propertySplitValue)!=-1)
            {

            QStringList value= element.at(j).split(this->propertySplitValue);
            temp[value.at(0)]=value.at(1);
            }
            else
            {
                if(element.at(j)=="")
                {
                 continue;
                }
                temp[element.at(j)]="";
            }
        }
        this->data[i]=temp;
    }
    }
}
DataPackageSplit::DataPackageSplit(){}

DataPackageSplit::DataPackageSplit(QString datapackage)
{
    this->msgTypeSplitData=MessageThread::getMessageThreadInstance()->getMsgTypeSplitData();//MessageThread
    this->betweenDataItemSplit=MessageThread::getMessageThreadInstance()->getBetweenDataItemSplit();
    this->reqParSplit=MessageThread::getMessageThreadInstance()->getReqParSplit();
    this->WithinDataItemSplit=MessageThread::getMessageThreadInstance()->getWithinDataItemSplit();
    this->propertySplitValue=MessageThread::getMessageThreadInstance()->getpropertySplitValue();
    dealData(datapackage);
}

//获取操作类型
int DataPackageSplit::getOperationType()
{
     return this->operationtype;
}
//或许序号
int DataPackageSplit::getNumber()
{
     return this->number;
}
//获取操作说明
QString DataPackageSplit::getOperationDescribe()
{
      return this->operationdescribe;
}
//获取客户端参数
QStringList* DataPackageSplit::getInputParameter()
{
      return this->inputparameter;
}
//获取返回数据
QMap<int, QMap<QString,QString> > DataPackageSplit::getData()
{
      return this->data;
}


