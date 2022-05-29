#include "combine2.h"
#include "ui_combine2.h"
#include"getinformation3.h"
#include<qmath.h>
#include<QPainter>
#include<QDebug>
#include<mypushbutton1.h>
#include<QString>
Combine2::Combine2(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::Combine2)
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
    ui->lineEdit6->setFont(QFont("ui->lineEdit6->text()", 12, QFont::Bold));

    //  ���źźͲ۵Ļ��Ƶ��ü��㺯��
    connect(btn, &MyPushButton1::clicked, [=]() {
        pass();
        calculate(Loan1, Loan2, period);
        });
}

// ���ñ���ͼƬ
void Combine2::paintEvent(QPaintEvent*)
{
    QPainter painter1(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter1.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void Combine2::calculate(double Loan1, double Loan2, int period)
{
    double  fmonthsupply1;          //��ҵ���������¹�
    double  smonthsupply1;         //��ҵ��������¹�
    double  sumrates1;                 //��ҵ���������Ϣ
    double fmonthsupply2;        //��������������¹�
    double  smonthsupply2;       //�������������¹�
    double sumrates2;                  //��������������Ϣ
    totalloans = Loan1 + Loan2;      //�����ܶ�
    month = period * 12;                  //��������
    if (period <= 5)
    {
        fmonthsupply1 = (Loan1 / month) + Loan1 * rate1;
        smonthsupply1 = (Loan1 / month) + (Loan1 - Loan1 / month) * rate1;
        sumrates1 = (month + 1) * Loan1 * rate1 / 2;
    }
    if (period <= 5)
    {
        fmonthsupply2 = (Loan2 / month) + Loan2 * rate1;
        smonthsupply2 = (Loan2 / month) + (Loan2 - Loan2 / month) * rate1;
        sumrates2 = (month + 1) * Loan2 * rate1 / 2;
    }
    if (period > 5)
    {
        fmonthsupply1 = (Loan1 / month) + Loan1 * rate2;
        smonthsupply1 = (Loan1 / month) + (Loan1 - Loan1 / month) * rate2;
        sumrates1 = (month + 1) * Loan1 * rate2 / 2;
    }
    if (period > 5)
    {
        fmonthsupply2 = (Loan2 / month) + Loan2 * rate2;
        smonthsupply2 = (Loan2 / month) + (Loan2 - Loan2 / month) * rate2;
        sumrates2 = (month + 1) * Loan2 * rate2 / 2;
    }

    fmonthsupply = fmonthsupply1 + fmonthsupply2;    //�����¹�
    smonthsupply = smonthsupply1 + smonthsupply2;   //�����¹�
    cha = fmonthsupply - smonthsupply;                         //ÿ�µݼ�
    sumrates = sumrates1 + sumrates2;                          //��������Ϣ
    sumpaybacks = sumrates + totalloans;                     //�����ܶ�

    //��ʾ
    ui->lineEdit1->setText(QString::number((int)round(fmonthsupply)));
    ui->lineEdit2->setText(QString::number((int)round(cha)));
    ui->lineEdit3->setText(QString::number((int)round(totalloans)));
    ui->lineEdit4->setText(QString::number((int)round(sumrates)));
    ui->lineEdit5->setText(QString::number((int)round(sumpaybacks)));
    ui->lineEdit6->setText(QString::number((int)month));
}

void  Combine2::pass()
{
    extern float loan1;
    extern float loan2;
    extern int years;
    Loan1 = loan1 * 10000;
    Loan2 = loan2 * 10000;
    period = years;

}

Combine2::~Combine2()
{
    delete ui;
}
