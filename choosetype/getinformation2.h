#ifndef GETINFORMATION2_H
#define GETINFORMATION2_H

#include <QMainWindow>
#include"commercial1.h"
#include"commercial2.h"
extern float percentage;  // ȫ�ֱ���  �������
extern int year;               //��������
extern  int type;           //���ʽ

namespace Ui {
    class GetInformation2;
}

class GetInformation2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit GetInformation2(QWidget* parent = nullptr);
    ~GetInformation2();
    void paintEvent(QPaintEvent*);

    Commercial1* commercial1 = NULL;
    Commercial2* commercial2 = NULL;

    //  �������ݺ���
    void Pass();

    //  ת����������
    void turn1();
    void turn2();

    //  ���ô�������
    void change();

private:
    Ui::GetInformation2* ui;
};

#endif // GETINFORMATION2_H
