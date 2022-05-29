#include "choosetype.h"
#include "ui_choosetype.h"
#include<mypushbutton1.h>
#include<QPainter>
#include<QDebug>
#include <QTimer>
int variety;
ChooseType::ChooseType(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseType)
{
    //  ������Ϣ����
    ui->setupUi(this);
    this->setFixedSize(800, 600);

    //  ����ͼ��
    setWindowIcon(QIcon(":/image/logol1.jpg"));
    //  ���ñ���
    setWindowTitle("��ѡ���������");

    //  ���ô������Ͱ�ť
    MyPushButton1* btn1 = new MyPushButton1;
    btn1->setParent(this);
    btn1->setText(" ��ҵ����");
    btn1->resize(180, 50);
    btn1->move(this->width() * 0.5 - btn1->width() * 0.5, this->height() * 0.2);
    btn1->setFont(QFont("��ҵ����", 15, QFont::Bold));   //�����˰�ť���ִ�С

    MyPushButton1* btn2 = new MyPushButton1;
    btn2->setParent(this);
    btn2->setText("���������");
    btn2->resize(180, 50);
    btn2->move(this->width() * 0.5 - btn2->width() * 0.5, this->height() * 0.4);
    btn2->setFont(QFont("���������", 15, QFont::Bold));

    MyPushButton1* btn3 = new MyPushButton1;
    btn3->setParent(this);
    btn3->setText(" ����ʹ���");
    btn3->resize(180, 50);
    btn3->move(this->width() * 0.5 - btn3->width() * 0.5, this->height() * 0.6);
    btn3->setFont(QFont("����ʹ���", 15, QFont::Bold));


    //   ���Ӵ������Ͱ�ť��ת������
    connect(btn1, &MyPushButton1::clicked, this, &ChooseType::turn1);
    connect(btn2, &MyPushButton1::clicked, this, &ChooseType::turn2);
    connect(btn3, &MyPushButton1::clicked, this, &ChooseType::turn3);

    connect(btn1, &MyPushButton1::clicked, [=]() {
        qDebug() << "�������";
        //  �����û�������ҵ������Ϣ�Ľ���
        information1 = new GetInformation1;
        //  ��ʱ������һ������
        QTimer::singleShot(500, this, [=]() {
            //  ����һ����������
            this->hide();
            // ��ʾ�������Ľ���
            information1->show();
            });
        });
    connect(btn2, &MyPushButton1::clicked, [=]() {
        qDebug() << "�������";
        //  �����û����빫���������Ϣ�Ľ���
        information1 = new GetInformation1;
        //  ��ʱ������һ������
        QTimer::singleShot(500, this, [=]() {
            //  ����һ����������
            this->hide();
            // ��ʾ�������Ľ���
            information1->show();
            });
        });
    connect(btn3, &MyPushButton1::clicked, [=]() {
        qDebug() << "�������";
        //  �����û���������ʹ�����Ϣ�Ľ���
        information3 = new Getinformation3;
        //  ��ʱ������һ������
        QTimer::singleShot(500, this, [=]() {
            //  ����һ����������
            this->hide();
            // ��ʾ�������Ľ���
            information3->show();
            });
        });
}

// ���ñ���ͼƬ
void ChooseType::paintEvent(QPaintEvent*)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void ChooseType::turn1()
{
    variety = 1;
    qDebug() << variety;
}
void ChooseType::turn2()
{
    variety = 2;
    qDebug() << variety;
}
void ChooseType::turn3()
{
    variety = 3;
    qDebug() << variety;
}
ChooseType::~ChooseType()
{
    delete ui;
}
