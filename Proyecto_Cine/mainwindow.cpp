#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ap.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , cartelera(new ArbolB(31))
    , a(*cartelera, this)
    , r(*cartelera, this)
{
    ui->setupUi(this);
    connect(&a, &ap::dialogClosed, this, &MainWindow::showMainWindow);
    connect(&r, &rp::dialogClosed, this, &MainWindow::showMainWindow);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_PB_Insertar_Pelicula_clicked()
{
    a.setCarteleraReference(*cartelera);
    a.show();
    this->hide();
}

void MainWindow::showMainWindow()
{
    this->show();
}


void MainWindow::on_PB_Buscar_Pelicula_clicked()
{
    r.setCarteleraReference(*cartelera);
    r.show();
    this->hide();
}


void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_2_clicked()
{
    ip.show();
    this->hide();

}

