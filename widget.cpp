#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->pbcoffee->setEnabled(false);
    ui->pbtea->setEnabled(false);
    ui->pbgongcha->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changemoney(int n){

    if( money+n < 0 )
        QMessageBox::information(this,"Title","금액이부족합니다.");

        else
        money += n;
        ui->lcdNumber->display(QString::number(money));

        if ( money > 1)
        ui->pbmoneyback->setEnabled(true);
        if ( money >= 100 )
        ui->pbcoffee->setEnabled(true); /// 활성화
        if ( money >= 150 )
        ui->pbtea->setEnabled(true); /// 활성화
        if ( money >= 200 )
        ui->pbgongcha->setEnabled(true); /// 활성화
}

void Widget::on_pb10_clicked()
{
changemoney(10);
}

void Widget::on_pb50_clicked()
{
changemoney(50);
}

void Widget::on_pb100_clicked()
{
changemoney(100);
}


void Widget::on_pb500_clicked()
{
    changemoney(500);
}

void Widget::on_pbcoffee_clicked()
{
    changemoney(-100);
    if ( money < 100 )
    ui->pbcoffee->setEnabled(false);
    if ( money < 150 )
    ui->pbtea->setEnabled(false);
    if ( money < 200 )
    ui->pbgongcha->setEnabled(false);
}

void Widget::on_pbtea_clicked()
{
    changemoney(-150);
    if ( money < 100 )
    ui->pbcoffee->setEnabled(false);
    if ( money < 150 )
    ui->pbtea->setEnabled(false);
    if ( money < 200 )
    ui->pbgongcha->setEnabled(false);
}

void Widget::on_pbgongcha_clicked()
{
    changemoney(-200);
    if ( money < 100 )
    ui->pbcoffee->setEnabled(false);
    if ( money < 150 )
    ui->pbtea->setEnabled(false);
    if ( money < 200 )
    ui->pbgongcha->setEnabled(false);
}

void Widget::on_pushButton_clicked()
{

}

void Widget::on_pbmoneyback_clicked()
{
    QMessageBox::information(this,"Title","반환완료.");
    money -= money;
}

void Widget::on_pbmnbk_clicked()
{
    QMessageBox::information(this,"Title","%반환완료.");
    money -= money;
}
