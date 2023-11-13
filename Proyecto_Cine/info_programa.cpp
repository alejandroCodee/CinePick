#include "info_programa.h"
#include "ui_info_programa.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>

info_programa::info_programa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::info_programa)
{
    ui->setupUi(this);
}

info_programa::~info_programa()
{
    delete ui;
}

void info_programa::on_PeliculasNuevas_clicked()
{

    QFile file("datos_peliculas.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo para lectura.");
        return;
    }

    QTextStream in(&file);
    QString peliculasData = in.readAll();

    QDialog dialog(this);
    QVBoxLayout layout(&dialog);
    QTextEdit textEdit;
    textEdit.setPlainText(peliculasData);
    layout.addWidget(&textEdit);

    dialog.exec();

    file.close();
}





void info_programa::on_Recorridos_clicked()
{

}


void info_programa::on_pushButton_clicked()
{
    arbol->listarCreciente();
}

