#ifndef COMMERCIAL2_H
#define COMMERCIAL2_H

#include <QMainWindow>

namespace Ui {
    class Commercial2;
}

class Commercial2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Commercial2(QWidget* parent = nullptr);
    ~Commercial2();
    float unit_price, area, percentage1;
    int period;       // �����м������
    void calculate(double unit_price, double area, int period, float percentage1);     // ���㼰��ʾ���
    void  pass();      //���ݲ���
    void paintEvent(QPaintEvent*);
private:
    double rate1 = 0.0405 / 12;    //������1
    double rate2 = 0.0475 / 12;    // ������2
    double rate3 = 0.0275 / 12;    //������3
    double rate4 = 0.0325 / 12;    // ������4
    double sumprice;           //  �ܼ�
    double payment;            // �׸�
    double totalloans;          //  �����ܶ�
    double fmonthsupply;         //�����¹�
    double smonthsupply;         //�����¹�
    double cha;                      // ÿ�µݼ�
    double sumpaybacks;         //�����ܶ�
    double sumrates;            // ֧������Ϣ
    int month;                      // ��������
    Ui::Commercial2* ui;
};

#endif // COMMERCIAL2_H
