#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton();
    //  ���캯��  ����1  ������ʾ��ͼƬ·��   ����2  ���º���ʾ��ͼƬ·��
    MyPushButton(QString  normalImg, QString  pressImg = "");

    //  ��Ա����  �����û������Ĭ����ʾ·��  �Լ����º���ʾ��ͼƬ·��
    QString normalImagPath;
    QString  prsssImgPath;

    //  ������Ч
    void zoom1();  //  ������
    void zoom2();  //  ������
};

#endif // MYPUSHBUTTON_H
