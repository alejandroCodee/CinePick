#include "welcome.h"
#include "ui_welcome.h"
#include "mainwindow.h"

Welcome::Welcome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);




}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_clicked()
{
    m.show();
    this->hide();
}


void Welcome::on_label_2_linkActivated(const QString &link)
{
    m.show();
    this->hide();
}

