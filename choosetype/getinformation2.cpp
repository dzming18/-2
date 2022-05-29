#include "getinformation2.h"
#include "ui_getinformation2.h"
#include<mypushbutton1.h>
#include<QPainter>
#include<QDebug>
#include <QTimer>
#include<QIntValidator>
#include<QDoubleValidator>
float percentage;
int year;
int type;
GetInformation2::GetInformation2(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::GetInformation2)
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
    ui->lineEdit->setFont(QFont("ui->lineEdit->text()", 12, QFont::Bold));

    QRegExp regx1("[2-8]|[2-8][.]5");   //�������밴�ҳ���
    QValidator* validator1 = new QRegExpValidator(regx1, this);
    ui->lineEdit1->setValidator(validator1);

    QRegExp regx2("[1-9]|1[0-9]|2[0-5]|");   //�������밴������
    QValidator* validator2 = new QRegExpValidator(regx2, this);
    ui->lineEdit2->setValidator(validator2);

    //     QDoubleValidator *validator1 = new QDoubleValidator;    //�������밴�ҳ���
    //     ui->lineEdit1->setValidator(validator1);

    //     QIntValidator *validator2 = new QIntValidator;    // �������밴������
    //     validator2->setRange(1,25);
    //     ui->lineEdit2->setValidator(validator2);

    MyPushButton1* btn1 = new MyPushButton1;
    btn1->setParent(this);
    btn1->setText(" �ȶϢ");
    btn1->resize(180, 50);
    btn1->move(this->width() * 0.4 - btn1->width() * 0.5, this->height() * 0.65);
    btn1->setFont(QFont("�ȶϢ", 15, QFont::Bold));

    MyPushButton1* btn2 = new MyPushButton1;
    btn2->setParent(this);
    btn2->setText(" �ȶ��");
    btn2->resize(180, 50);
    btn2->move(this->width() * 0.6, this->height() * 0.65);
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

    connect(btn3, &MyPushButton1::clicked, [=]() {
        qDebug() << "�������";

        //  ���������Ϣ�Ľ���
        commercial1 = new Commercial1;
        commercial2 = new Commercial2;
        //  ��ʱ������һ������
        QTimer::singleShot(500, this, [=]() {
            //  ����һ����������
            this->hide();
            // ��ʾ�������Ľ���
            if (type == 1)      //  ����ҵ��������������д��һ��
                commercial1->show();
            if (type == 2)
                commercial2->show();
            });
        });

    //   ���ӿ�ʼ���㰴ť�봫������
    connect(btn3, &MyPushButton1::clicked, this, &GetInformation2::Pass);
}
// ���ñ���ͼƬ
void GetInformation2::paintEvent(QPaintEvent*)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void GetInformation2::Pass()
{
    percentage = ui->lineEdit1->text().toFloat();
    year = ui->lineEdit2->text().toInt();
    qDebug() << percentage;
    qDebug() << year;
}

void GetInformation2::turn1()
{
    type = 1;
    qDebug() << type;
}
void GetInformation2::turn2()
{
    type = 2;
    qDebug() << type;
}

void GetInformation2::change()
{
    extern int variety;
    year = ui->lineEdit2->text().toInt();
    if (year <= 5 && variety == 1)
        ui->lineEdit->setText("4.05%");
    else if (year > 5 && variety == 1)
        ui->lineEdit->setText("4.75%");
    else if (year <= 5 && variety == 2)
        ui->lineEdit->setText("2.75%");
    else if (year > 5 && variety == 2)
        ui->lineEdit->setText("3.25%");
}
GetInformation2::~GetInformation2()
{
    delete ui;
}
