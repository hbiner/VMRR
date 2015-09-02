#include <QtGui/QApplication>
#include "UI/uiapp.h"
#include <QtCore>
#include<controller/messagethread.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec *codec = QTextCodec::codecForName("UTF-8"); //获取系统编码
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    //服务器建立TCP连接
    MessageThread::getMessageThreadInstance()->conn();

    UIAPP w;
    w.show();
    return a.exec();
}
