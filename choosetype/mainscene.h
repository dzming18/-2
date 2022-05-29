#include "mainscene.h"
#include "ui_mainscene.h"
#include<QPainter>
#include<QDebug>
#include<mypushbutton.h>
#include <QTimer>
MainScene::MainScene(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //  ������

    // �̶����ڴ�С
    setFixedSize(800, 600);
    //  ����ͼ��
    setWindowIcon(QIcon(":/image/logol1.jpg"));
    //  ���ñ���
    setWindowTitle("һ���򷿰�");

    // ���밴ť

    MyPushButton* enterbtn = new MyPushButton(":/image/button.jpg");
    enterbtn->setParent(this);
    enterbtn->move(this->width() * 0.5 - enterbtn->width() * 0.5, this->height() * 0.4);

    //   enterbtn->setStyleSheet("border:none");   //������ȥ������ͼƬ�ı߿򣬵���û��ʵ��Ч��

    //    enterbtn->setStyleSheet("border:2px groove gray;border-radius :10px;padding:2px 4px;");
       // enterbtn->setFlat(true);

    connect(enterbtn, &MyPushButton::clicked, [=]() {
        qDebug() << "�������";

        // ��һ����ť�������Ч
        enterbtn->zoom1();
        enterbtn->zoom2();

        //  �����û�ѡ��������͵Ľ���Ľ���
        choosetype = new ChooseType;

        //  ��ʱ������һ������
        QTimer::singleShot(500, this, [=]() {
            //  ����һ����������
            this->hide();
            // ��ʾ�������Ľ���
            choosetype->show();
            });
        });


}
// ���ñ���ͼƬ
void MainScene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/base.jpg");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

MainScene::~MainScene()
{
    delete ui;
}

