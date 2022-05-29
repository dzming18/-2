#include "getinformation3.h"
#include "ui_getinformation3.h"
#include<QPainter>
#include<QDebug>
#include <QTimer>
#include<mypushbutton1.h>
#include<QIntValidator>
float loan1;
float loan2;
int years;
int ctype;
Getinformation3::Getinformation3(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Getinformation3)
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
    ui->lineEdit3->setFont(QFont("ui->lineEdit3->text()", 12, QFont::Bold));
    ui->lineEdit->setFont(QFont("ui->lineEdit->text()", 12, QFont::Bold));

    QIntValidator* validator1 = new QIntValidator;    // ���ƽ������
    ui->lineEdit1->setValidator(validator1);

    QIntValidator* validator2 = new QIntValidator;    // ���ƽ������
    ui->lineEdit2->setValidator(validator2);


    QRegExp regx3("[1-9]|1[0-9]|2[0-5]");   //�������밴������
    QValidator* validator3 = new QRegExpValidator(regx3, this);
    ui->lineEdit3->setValidator(validator3);

    //     QIntValidator *validator3 = new QIntValidator;    // �������밴������
    //     validator3->setRange(1,25);
    //     ui->lineEdit3->setValidator(validator3);

    MyPushButton1* btn1 = new MyPushButton1;
    btn1->setParent(this);
    btn1->setText(" �ȶϢ");
    btn1->resize(180, 50);
    btn1->move(this->width() * 0.4 - btn1->width() * 0.5, this->height() * 0.7);
    btn1->setFont(QFont("�ȶϢ", 15, QFont::Bold));

    MyPushButton1* btn2 = new MyPushButton1;
    btn2->setParent(this);
    btn2->setText(" �ȶ��");
    btn2->resize(180, 50);
    btn2->move(this->width() * 0.6, this->height() * 0.7);
    btn2->setFont(QFont("�ȶ��", 15, QFont::Bold));

    MyPushButton1* btn3 = new MyPushButton1;
    btn3->setParent(this);
    btn3->setText(" ȷ��");
    btn3->resize(180, 50);
    btn3->move(this->width() - btn3->width(), this->height() - btn3->height());
    btn3->setFont(QFont("ȷ��", 15, QFont::Bold));


    //   ���ӻ��ʽ��ť��ת�����ͺ���ʾ����
    connect(btn1, &MyPushButton1::clicked, [=]() {
        turn1();
        change();
        });

    //   ���ӻ��ʽ��ť��ת�����ͺ���ʾ����
    connect(btn2, &MyPushButton1::clicked, [=]() {
        turn2();
        change();
        });

    //   ���ӿ�ʼ���㰴ť�봫������
    connect(btn3, &MyPushButton1::clicked, this, &Getinformation3::Pass);

    connect(btn3, &MyPushButton1::clicked, [=]() {
        qDebug() << "�������";
        //  ���������Ϣ�Ľ���
        combine1 = new Combine;
        combine2 = new Combine2;
        //  ��ʱ������һ������
        QTimer::singleShot(500, this, [=]() {
            //  ����һ����������
            this->hide();
            // ��ʾ�������Ľ���
            if (ctype == 1)      // ����ʹ���ȶϢ����
                combine1->show();
            if (ctype == 2)
                combine2->show();
            });
        });
}

// ���ñ���ͼƬ
void Getinformation3::paintEvent(QPaintEvent*)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void Getinformation3::Pass()
{
    loan1 = ui->lineEdit1->text().toFloat();
    loan2 = ui->lineEdit2->text().toFloat();
    years = ui->lineEdit3->text().toInt();
    qDebug() << loan1;
    qDebug() << loan2;
    qDebug() << years;
}

void Getinformation3::change()
{
    years = ui->lineEdit3->text().toInt();
    if (years <= 5)
        ui->lineEdit->setText("2.75%");
    else
        ui->lineEdit->setText("3.25%");
}

void Getinformation3::turn1()
{
    ctype = 1;
    qDebug() << ctype;
}
void Getinformation3::turn2()
{
    ctype = 2;
    qDebug() << ctype;
}
Getinformation3::~Getinformation3()
{
    delete ui;
}
