#include "combine1.h"
#include "ui_combine1.h"
#include"getinformation3.h"
#include<qmath.h>
#include<QPainter>
#include<QDebug>
#include<mypushbutton1.h>
#include<QString>
Combine::Combine(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Combine)
{
    //  ������Ϣ����
    ui->setupUi(this);
    this->setFixedSize(800, 600);

    //  ����ͼ��
    setWindowIcon(QIcon(":/image/logol1.jpg"));
    //  ���ñ���
    setWindowTitle("�����Ϣ");
    MyPushButton1* btn = new MyPushButton1;
    btn->setParent(this);
    btn->setText(" ��ʼ����");
    btn->resize(180, 50);
    btn->setFont(QFont("��ʼ����", 15, QFont::Bold));

    //������ɰ�ť ��������
    MyPushButton1* btn4 = new MyPushButton1;
    btn4->setParent(this);
    btn4->setText(" ���");
    btn4->resize(180, 50);
    btn4->move(this->width() - btn4->width(), this->height() - btn4->height());
    btn4->setFont(QFont("���", 15, QFont::Bold));
    connect(btn4, &MyPushButton1::clicked, this, &QWidget::close);

    // ��������������С
    ui->lineEdit1->setFont(QFont("ui->lineEdit1->text()", 12, QFont::Bold));
    ui->lineEdit2->setFont(QFont("ui->lineEdit2->text()", 12, QFont::Bold));
    ui->lineEdit3->setFont(QFont("ui->lineEdit3->text()", 12, QFont::Bold));
    ui->lineEdit4->setFont(QFont("ui->lineEdit4->text()", 12, QFont::Bold));
    ui->lineEdit5->setFont(QFont("ui->lineEdit5->text()", 12, QFont::Bold));


    //  ���źźͲ۵Ļ��Ƶ��ô��ݺͼ��㺯��
    connect(btn, &MyPushButton1::clicked, [=]() {
        pass();
        calculate(Loan1, Loan2, period);
        });
}

// ���ñ���ͼƬ
void Combine::paintEvent(QPaintEvent*)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void Combine::calculate(double Loan1, double Loan2, int period)
{
    double monthsupply1;     //��ҵ���������¹�
    double monthsupply2;    //��������������¹�
    if (period <= 5)
    {
        monthsupply1 = (Loan1 * rate1 * qPow((1 + rate1), period * 12)) / (qPow(1 + rate1, period * 12) - 1);
    }
    if (period > 5)
    {
        monthsupply1 = (Loan1 * rate2 * qPow((1 + rate2), period * 12)) / (qPow(1 + rate2, period * 12) - 1);
    }
    if (period <= 5)
    {
        monthsupply2 = (Loan2 * rate1 * qPow((1 + rate1), period * 12)) / (qPow(1 + rate1, period * 12) - 1);
    }
    if (period > 5)
    {
        monthsupply2 = (Loan2 * rate2 * qPow((1 + rate2), period * 12)) / (qPow(1 + rate2, period * 12) - 1);
    }
    monthsupply = monthsupply1 + monthsupply2;        //�����¹�
    totalloans = Loan1 + Loan2;                                       //�����ܶ�
    sumpaybacks = monthsupply * period * 12;                 //�����ܶ�
    sumrates = sumpaybacks - totalloans;                       //��������Ϣ
    month = period * 12;                                                 //��������

    //��ʾ
    ui->lineEdit1->setText(QString::number((int)round(monthsupply)));
    ui->lineEdit2->setText(QString::number((int)round(totalloans)));
    ui->lineEdit3->setText(QString::number((int)round(sumrates)));
    ui->lineEdit4->setText(QString::number((int)round(sumpaybacks)));
    ui->lineEdit5->setText(QString::number((int)month));
}

void  Combine::pass()
{
    extern float loan1;
    extern float loan2;
    extern int years;
    Loan1 = loan1 * 10000;
    Loan2 = loan2 * 10000;
    period = years;

}
Combine::~Combine()
{
    delete ui;
}
