#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::checkMoney(){
    if (money < 100) ui->pbCoffee->setEnabled(false);
    else ui->pbCoffee->setEnabled(true);
    if (money < 150) ui->pbTea->setEnabled(false);
    else ui->pbTea->setEnabled(true);
    if (money < 200) ui->pbMilk->setEnabled(false);
    else ui->pbMilk->setEnabled(true);
}

void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);
    checkMoney();
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}


void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}


void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}


void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()
{
    int Changes = money;
    int coin500=0, coin100=0, coin50=0, coin10=0;

    if (Changes >= 500) {
        coin500 = Changes / 500;
        Changes -= coin500 * 500;
    }
    if (Changes >= 100) {
        coin100 = Changes / 100;
        Changes -= coin100 * 100;
    }
    if (Changes >= 50) {
        coin50 = Changes / 50;
        Changes -= coin50 * 50;
    }
    if (Changes >= 10) {
        coin10 = Changes / 10;
    }

    char* message;
    sprintf(message, "500 won: %d\n100 won: %d\n50 won: %d\n10 won: %d", coin500, coin100, coin50, coin10);

    QMessageBox mb;
    mb.information(this, "Changes", message);

    money = 0;
    changeMoney(-money);
}

