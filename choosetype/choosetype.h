#ifndef CHOOSETYPE_H
#define CHOOSETYPE_H

#include <QMainWindow>
#include"getinformation1.h"
#include"getinformation3.h"
extern int variety;  //ȫ�ֱ���  ��������
namespace Ui {
    class ChooseType;
}

class ChooseType : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseType(QWidget* parent = nullptr);
    ~ChooseType();
    void paintEvent(QPaintEvent*);

    GetInformation1* information1 = NULL;
    Getinformation3* information3 = NULL;


    // ת���������
    void turn1();
    void turn2();
    void turn3();


private:
    Ui::ChooseType* ui;
};

#endif // CHOOSETYPE_H
