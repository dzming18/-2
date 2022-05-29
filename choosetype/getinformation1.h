#include "getinformation1.h"
#include "ui_getinformation1.h"
#include<QPainter>
#include<QDebug>
#include<mypushbutton1.h>
#include <QTimer>
#include<QDoubleValidator>
float price;    //  cpp�ļ�����Ҫ�ٴζ���
float space;
GetInformation1::GetInformation1(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::GetInformation1)
{
    //  ������Ϣ����
    ui->setupUi(this);
    this->setFixedSize(800, 600);

    //  ����ͼ��
    setWindowIcon(QIcon(":/image/logol1.jpg"));
    //  ���ñ���
    setWindowTitle("��������Ϣ");

    // ��������������С
    ui->lineEdit1->setFont(QFont("ui->lineEdit1->text()", 12, QFont::Bold));
    ui->lineEdit2->setFont(QFont("ui->lineEdit2->text()", 12, QFont::Bold));

    QDoubleValidator* validator1 = new QDoubleValidator;    //�������뷿�ݵ���Ϊ���֣�double�ͣ�
    ui->lineEdit1->setValidator(validator1);

    QDoubleValidator* validator2 = new QDoubleValidator;    // �������뷿�����Ϊ���� ��double�ͣ�
    ui->lineEdit2->setValidator(validator2);

    //  ����ȷ����ť
    MyPushButton1* btn = new MyPushButton1;
    btn->setParent(this);
    btn->setText(" ȷ��");
    btn->resize(180, 50);
    btn->move(this->width() * 0.5 - btn->width() * 0.5, this->height() * 0.7);
    btn->setFont(QFont("ȷ��", 15, QFont::Bold));

    connect(btn, &MyPushButton1::clicked, [=]() {
        qDebug() << "�������";
        //  �����û�������Ϣ�Ľ���
        information2 = new GetInformation2;
        //  ��ʱ������һ������
        QTimer::singleShot(500, this, [=]() {
            //  ����һ����������
            this->hide();
            // ��ʾ�������Ľ���
            information2->show();
            });
        });

    //   ����ȷ����ť�봫������
    connect(btn, &MyPushButton1::clicked, this, &GetInformation1::Pass);
}
// ���ñ���ͼƬ
void GetInformation1::paintEvent(QPaintEvent*)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0, 0, this->width(), this->height(), pix);
}

//  �������ݺ�����ʵ��
void GetInformation1::Pass()
{
    price = ui->lineEdit1->text().toFloat();
    space = ui->lineEdit2->text().toFloat();
    qDebug() << price;
    qDebug() << space;
}
GetInformation1::~GetInformation1()
{
    delete ui;
}
