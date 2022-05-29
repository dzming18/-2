#ifndef COMMERCIAL1_H
#define COMMERCIAL1_H

#include <QMainWindow>

namespace Ui {
    class Commercial1;
}

class Commercial1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Commercial1(QWidget* parent = nullptr);
    ~Commercial1();
    float unit_price, area, percentage1;
    int period;       // �����м������
    void calculate(double unit_price, double area, int period, float percentage1);   // ���㼰��ʾ���
    void paintEvent(QPaintEvent*);
    void  pass();       //���ݲ���
private:
    double rate1 = 0.0405 / 12;    //������1
    double rate2 = 0.0475 / 12;    // ������2
    double rate3 = 0.0275 / 12;    //������3
    double rate4 = 0.0325 / 12;    // ������4
    double sumprice;           //  �ܼ�
    double payment;            // �׸�
    double totalloans;          //  �����ܶ�
    double monthsupply;         //�¹�
    double sumpaybacks;         //�����ܶ�
    double sumrates;            // ֧������Ϣ
    int month;                   // ��������
    Ui::Commercial1* ui;
};

#endif // COMMERCIAL1_H
