#ifndef COMBINE2_H
#define COMBINE2_H

#include <QMainWindow>

namespace Ui {
    class Combine2;
}

class Combine2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Combine2(QWidget* parent = nullptr);
    ~Combine2();
    void paintEvent(QPaintEvent*);
    void  pass();  //���ݲ���
    void calculate(double Loan1, double Loan2, int period);
    double Loan1;
    double Loan2;
    int period;

private:
    Ui::Combine2* ui;
    double rate1 = 0.0275 / 12;
    double rate2 = 0.0325 / 12;
    long long totalloans;            //  �����ܶ�
    long long fmonthsupply;         //�����¹�
    long  long smonthsupply;      //�����¹�
    float cha;                             //ÿ�µݼ�
    long long sumpaybacks;         //�����ܶ�
    long long sumrates;            // ֧������Ϣ
    int month;                         // ��������
};

#endif // COMBINE2_H
