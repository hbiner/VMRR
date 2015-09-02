#ifndef UIAPP_H
#define UIAPP_H

#include <QDialog>
#include<QTextEdit>
#include<QPushButton>
#include<QGridLayout>
#include<QLineEdit>
#include<QLabel>
 /*
  *功能：该类就是一个测试怎样在UI中使用的例子，同时测试接口是否正确
  *编写时间：2013.4.13
 */

class UIAPP : public QDialog
{
    Q_OBJECT

public:
    explicit UIAPP(QWidget *parent = 0);

private:
    QTextEdit *showMsgTestEdit ; //显示服务器返回信息
     //10个参数编辑框
    QLineEdit *lineEdit00;
    QLineEdit *lineEdit01;
    QLineEdit *lineEdit02;
    QLineEdit *lineEdit03;
    QLineEdit *lineEdit04;
    QLineEdit *lineEdit05;
    QLineEdit *lineEdit06;
    QLineEdit *lineEdit07;
    QLineEdit *lineEdit08;
    QLineEdit *lineEdit09;


    //A组
    QPushButton * buttonA00;
    QPushButton * buttonA01;
    QPushButton * buttonA02;
    QPushButton * buttonA03;
    QPushButton * buttonA04;
    QPushButton * buttonA05;
    QPushButton * buttonA06;
    QPushButton * buttonA07;
    QPushButton * buttonA08;
    QPushButton * buttonA09;

    QPushButton * buttonA10;
    QPushButton * buttonA11;
    QPushButton * buttonA12;
    QPushButton * buttonA13;
    QPushButton * buttonA14;
    QPushButton * buttonA15;
    QPushButton * buttonA16;
    QPushButton * buttonA17;
    QPushButton * buttonA18;
    QPushButton * buttonA19;

    QPushButton * buttonA20;
    QPushButton * buttonA21;
    QPushButton * buttonA22;
    QPushButton * buttonA23;
    QPushButton * buttonA24;
    QPushButton * buttonA25;
    QPushButton * buttonA26;
    QPushButton * buttonA27;
    QPushButton * buttonA28;
    QPushButton * buttonA29;

    QPushButton * buttonA30;
    QPushButton * buttonA31;
    QPushButton * buttonA32;
    QPushButton * buttonA33;
    QPushButton * buttonA34;
    QPushButton * buttonA35;
    QPushButton * buttonA36;
    QPushButton * buttonA37;
    QPushButton * buttonA38;
    QPushButton * buttonA39;

    QPushButton * buttonA40;
    QPushButton * buttonA41;
    QPushButton * buttonA42;
    QPushButton * buttonA43;
    QPushButton * buttonA44;
    QPushButton * buttonA45;
    QPushButton * buttonA46;
    QPushButton * buttonA47;
    QPushButton * buttonA48;
    QPushButton * buttonA49;

    QPushButton * buttonA50;
    QPushButton * buttonA51;
    QPushButton * buttonA52;
    QPushButton * buttonA53;
    QPushButton * buttonA54;
    QPushButton * buttonA55;
    QPushButton * buttonA56;
    QPushButton * buttonA57;
    QPushButton * buttonA58;
    QPushButton * buttonA59;

    QPushButton * buttonA60;
    QPushButton * buttonA61;
    QPushButton * buttonA62;
    QPushButton * buttonA63;
    QPushButton * buttonA64;
    QPushButton * buttonA65;
    QPushButton * buttonA66;
    QPushButton * buttonA67;
    QPushButton * buttonA68;
    QPushButton * buttonA69;

    QPushButton * buttonA70;
    QPushButton * buttonA71;
    QPushButton * buttonA72;
    QPushButton * buttonA73;
    QPushButton * buttonA74;
    QPushButton * buttonA75;
    QPushButton * buttonA76;
    QPushButton * buttonA77;
    QPushButton * buttonA78;
    QPushButton * buttonA79;

    QPushButton * buttonA80;
    QPushButton * buttonA81;
    QPushButton * buttonA82;
    QPushButton * buttonA83;
    QPushButton * buttonA84;
    QPushButton * buttonA85;
    QPushButton * buttonA86;
    QPushButton * buttonA87;
    QPushButton * buttonA88;
    QPushButton * buttonA89;

    QPushButton * buttonA90;
    QPushButton * buttonA91;
    QPushButton * buttonA92;
    QPushButton * buttonA93;
    QPushButton * buttonA94;
    QPushButton * buttonA95;
    QPushButton * buttonA96;
    QPushButton * buttonA97;
    QPushButton * buttonA98;
    QPushButton * buttonA99;

    //B组
    QPushButton * buttonB00;
    QPushButton * buttonB01;
    QPushButton * buttonB02;
    QPushButton * buttonB03;
    QPushButton * buttonB04;
    QPushButton * buttonB05;
    QPushButton * buttonB06;
    QPushButton * buttonB07;
    QPushButton * buttonB08;
    QPushButton * buttonB09;

    QPushButton * buttonB10;
    QPushButton * buttonB11;
    QPushButton * buttonB12;
    QPushButton * buttonB13;
    QPushButton * buttonB14;
    QPushButton * buttonB15;
    QPushButton * buttonB16;
    QPushButton * buttonB17;
    QPushButton * buttonB18;
    QPushButton * buttonB19;
    QPushButton * buttonB20;

    QPushButton * buttonB21;
    QPushButton * buttonB22;
    QPushButton * buttonB23;
    QPushButton * buttonB24;
    QPushButton * buttonB25;
    QPushButton * buttonB26;
    QPushButton * buttonB27;
    QPushButton * buttonB28;
    QPushButton * buttonB29;

    QPushButton * buttonB30;
    QPushButton * buttonB31;
    QPushButton * buttonB32;
    QPushButton * buttonB33;
    QPushButton * buttonB34;
    QPushButton * buttonB35;
    QPushButton * buttonB36;
    QPushButton * buttonB37;
    QPushButton * buttonB38;
    QPushButton * buttonB39;

    QPushButton * buttonB40;
    QPushButton * buttonB41;
    QPushButton * buttonB42;
    QPushButton * buttonB43;
    QPushButton * buttonB44;
    QPushButton * buttonB45;
    QPushButton * buttonB46;
    QPushButton * buttonB47;
    QPushButton * buttonB48;
    QPushButton * buttonB49;

    QPushButton * buttonB50;
    QPushButton * buttonB51;
    QPushButton * buttonB52;
    QPushButton * buttonB53;
    QPushButton * buttonB54;
    QPushButton * buttonB55;
    QPushButton * buttonB56;
    QPushButton * buttonB57;
    QPushButton * buttonB58;
    QPushButton * buttonB59;

    QPushButton * buttonB60;
    QPushButton * buttonB61;
    QPushButton * buttonB62;
    QPushButton * buttonB63;
    QPushButton * buttonB64;
    QPushButton * buttonB65;
    QPushButton * buttonB66;
    QPushButton * buttonB67;
    QPushButton * buttonB68;
    QPushButton * buttonB69;

    QPushButton * buttonB70;
    QPushButton * buttonB71;
    QPushButton * buttonB72;
    QPushButton * buttonB73;
    QPushButton * buttonB74;
    QPushButton * buttonB75;
    QPushButton * buttonB76;
    QPushButton * buttonB77;
    QPushButton * buttonB78;
    QPushButton * buttonB79;

    QPushButton * buttonB80;
    QPushButton * buttonB81;
    QPushButton * buttonB82;
    QPushButton * buttonB83;
    QPushButton * buttonB84;
    QPushButton * buttonB85;
    QPushButton * buttonB86;
    QPushButton * buttonB87;
    QPushButton * buttonB88;
    QPushButton * buttonB89;

    QPushButton * buttonB90;
    QPushButton * buttonB91;
    QPushButton * buttonB92;
    QPushButton * buttonB93;
    QPushButton * buttonB94;
    QPushButton * buttonB95;
    QPushButton * buttonB96;
    QPushButton * buttonB97;
    QPushButton * buttonB98;
    QPushButton * buttonB99;

    //C组
    QPushButton * buttonC00;
    QPushButton * buttonC01;
    QPushButton * buttonC02;
    QPushButton * buttonC03;
    QPushButton * buttonC04;
    QPushButton * buttonC05;
    QPushButton * buttonC06;
    QPushButton * buttonC07;
    QPushButton * buttonC08;
    QPushButton * buttonC09;

    QPushButton * buttonC10;
    QPushButton * buttonC11;
    QPushButton * buttonC12;
    QPushButton * buttonC13;
    QPushButton * buttonC14;
    QPushButton * buttonC15;
    QPushButton * buttonC16;
    QPushButton * buttonC17;
    QPushButton * buttonC18;
    QPushButton * buttonC19;

    QPushButton * buttonC20;
    QPushButton * buttonC21;
    QPushButton * buttonC22;
    QPushButton * buttonC23;
    QPushButton * buttonC24;
    QPushButton * buttonC25;
    QPushButton * buttonC26;
    QPushButton * buttonC27;
    QPushButton * buttonC28;
    QPushButton * buttonC29;

    QPushButton * buttonC30;
    QPushButton * buttonC31;
    QPushButton * buttonC32;
    QPushButton * buttonC33;
    QPushButton * buttonC34;
    QPushButton * buttonC35;
    QPushButton * buttonC36;
    QPushButton * buttonC37;
    QPushButton * buttonC38;
    QPushButton * buttonC39;

    QPushButton * buttonC40;
    QPushButton * buttonC41;
    QPushButton * buttonC42;
    QPushButton * buttonC43;
    QPushButton * buttonC44;
    QPushButton * buttonC45;
    QPushButton * buttonC46;
    QPushButton * buttonC47;
    QPushButton * buttonC48;
    QPushButton * buttonC49;

    QPushButton * buttonC50;
    QPushButton * buttonC51;
    QPushButton * buttonC52;
    QPushButton * buttonC53;
    QPushButton * buttonC54;
    QPushButton * buttonC55;
    QPushButton * buttonC56;
    QPushButton * buttonC57;
    QPushButton * buttonC58;
    QPushButton * buttonC59;

    QPushButton * buttonC60;
    QPushButton * buttonC61;
    QPushButton * buttonC62;
    QPushButton * buttonC63;
    QPushButton * buttonC64;
    QPushButton * buttonC65;
    QPushButton * buttonC66;
    QPushButton * buttonC67;
    QPushButton * buttonC68;
    QPushButton * buttonC69;

    QPushButton * buttonC70;
    QPushButton * buttonC71;
    QPushButton * buttonC72;
    QPushButton * buttonC73;
    QPushButton * buttonC74;
    QPushButton * buttonC75;
    QPushButton * buttonC76;
    QPushButton * buttonC77;
    QPushButton * buttonC78;
    QPushButton * buttonC79;

    QPushButton * buttonC80;
    QPushButton * buttonC81;
    QPushButton * buttonC82;
    QPushButton * buttonC83;
    QPushButton * buttonC84;
    QPushButton * buttonC85;
    QPushButton * buttonC86;
    QPushButton * buttonC87;
    QPushButton * buttonC88;
    QPushButton * buttonC89;

    QPushButton * buttonC90;
    QPushButton * buttonC91;
    QPushButton * buttonC92;
    QPushButton * buttonC93;
    QPushButton * buttonC94;
    QPushButton * buttonC95;
    QPushButton * buttonC96;
    QPushButton * buttonC97;
    QPushButton * buttonC98;
    QPushButton * buttonC99;

signals:


public slots:

    void getInfoSlot(QString msg);  //接收数据

     void buttonA00SLot();

     void buttonA10SLot();

    void  buttonA20SLot();

    void  buttonA30SLot();

    void  buttonA40SLot();
    void  buttonA41SLot();
    void  buttonA42SLot();
    void  buttonA43SLot();
    void  buttonA44SLot();
    void  buttonA45SLot();

    void  buttonA50SLot();

    void  buttonA60SLot();

    void  buttonA70SLot();
    void  buttonA71SLot();

    void  buttonA80SLot();
    void  buttonA81SLot();
    void  buttonA82SLot();
    void  buttonA83SLot();
    void  buttonA84SLot();
    void  buttonA85SLot();

    void buttonA90SLot();

    void buttonB00SLot();
    void buttonB01SLot();
    void buttonB02SLot();


    void buttonB10SLot();
    void buttonB11SLot();
    void buttonB12SLot();


    void buttonB20SLot();
    void buttonB21SLot();
    void buttonB22SLot();
    void buttonB23SLot();
    void buttonB24SLot();
    void buttonB25SLot();
    void buttonB26SLot();

    void buttonB30SLot();
    void buttonB31SLot();
    void buttonB32SLot();
    void buttonB33SLot();
    void buttonB34SLot();
    void buttonB35SLot();

    void buttonB40Slot();
    void buttonB41Slot();

    void buttonB50SLot();
    void buttonB51SLot();

    void buttonB60SLot();
    void buttonB61SLot();

    void buttonB70SLot();
    void buttonB71SLot();
    void buttonB72SLot();
    void buttonB73SLot();
    void buttonB74SLot();

    void buttonB80Slot();
     void buttonB90SLot();
};

#endif // UIAPP_H
