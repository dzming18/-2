#ifndef COMBINE_H
#define COMBINE_H

#include <QMainWindow>

namespace Ui {
    class Combine;
}

class Combine : public QMainWindow
{
    Q_OBJECT

public:
    explicit Combine(QWidget* parent = nullptr);
    ~Combine();
    void paintEvent(QPaintEvent*);
    void  pass();  //���ݲ���
    void calculate(double Loan1, double Loan2, int period);
    double Loan1;    // ��ҵ�����
    double Loan2;    // ����������
    int period;        //��������
private:
    Ui::Combine* ui;
    double rate1 = 0.0275 / 12;     //����1
    double rate2 = 0.0325 / 12;     //����2
    double totalloans;           //  �����ܶ�
    double monthsupply;         //�¹�
    double sumpaybacks;         //�����ܶ�
    double sumrates;            // ֧������Ϣ
    int month;                    // ��������
};

#endif // COMBINE_H
