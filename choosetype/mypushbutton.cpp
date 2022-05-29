#include "mypushbutton.h"
#include<QDebug>
#include<QPropertyAnimation>
MyPushButton::MyPushButton(QString  normalImg, QString  pressImg)
{
    this->normalImagPath = normalImg;
    this->prsssImgPath = pressImg;
    QPixmap  pix;
    bool  ret = pix.load(normalImg);
    if (!ret)
    {
        qDebug() << "ͼƬ����ʧ�ܣ�";
    }
    //  ����ͼƬ�̶���С

    this->setFixedSize(pix.width(), pix.height());

    // ������ͼƬ����ʽ

    this->setStyleSheet("QPushButton{border:none;}");  //  ��ȱ�ݣ�����  ͼƬ�߿�û�۵�
    //  ����ͼ��

    this->setIcon(pix);

    // ����ͼ���С
    this->setIconSize(QSize(pix.width() * 0.5, pix.height() * 0.9));
}
void MyPushButton::zoom1()  //  ������
{
    //  ������̬����
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    //  ����ʱ����
    animation->setDuration(200);
    //  ��ʼλ��

    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    //  ���õ�������
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // ִ�ж���
    animation->start();
}
void MyPushButton::zoom2()  //  ������
{
    //  ������̬����
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    //  ����ʱ����
    animation->setDuration(200);
    //  ��ʼλ��

    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //  ���õ�������
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // ִ�ж���
    animation->start();
}

