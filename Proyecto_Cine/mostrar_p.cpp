#include "mostrar_p.h"
#include "ui_mostrar_p.h"

Mostrar_p::Mostrar_p(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mostrar_p)
{
    ui->setupUi(this);


    ui->Info_p->setColumnCount(5);
    ui->Info_p->setHorizontalHeaderLabels(QStringList()<<"Nombre"<<"Año"<<"Director"<<"Rating"<<"Genero");

}


void Mostrar_p::actualizarInformacion(const Movie& pelicula) {
    int row = ui->Info_p->rowCount();
    ui->Info_p->insertRow(row);
    QTableWidgetItem *itemNombre = new QTableWidgetItem(QString::fromStdString(pelicula.getTitle()));
    QTableWidgetItem *itemAnio = new QTableWidgetItem(QString::number(pelicula.getYear()));
    QTableWidgetItem *itemDirector = new QTableWidgetItem(QString::fromStdString(pelicula.getDirector()));
    QTableWidgetItem *itemRating = new QTableWidgetItem(QString::number(pelicula.getRating()));
    QTableWidgetItem *itemGenero = new QTableWidgetItem(QString::fromStdString(pelicula.getGenre()));

    ui->Info_p->setItem(row, 0, itemNombre);
    ui->Info_p->setItem(row, 1, itemAnio);
    ui->Info_p->setItem(row, 2, itemDirector);
    ui->Info_p->setItem(row, 3, itemRating);
    ui->Info_p->setItem(row, 4, itemGenero);
}

void Mostrar_p::cargarImagen(const QString& imagePath)
{
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        pixmap = pixmap.scaled(ui->foto->width(), ui->foto->height(), Qt::KeepAspectRatio);

        ui->foto->setPixmap(pixmap);
    } else {
        ui->foto->setText("Imagen no disponible");
    }
}

void Mostrar_p::setTitulo(const QString& titulo) {
    ui->titulo->setText(titulo);
}


Mostrar_p::~Mostrar_p()
{
    delete ui;
}


