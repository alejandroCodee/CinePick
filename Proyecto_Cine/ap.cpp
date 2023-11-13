#include "ap.h"
#include "ui_ap.h"
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>

ap::ap(ArbolB& ref, QWidget *parent) : QDialog(parent), carteleraRef(ref), ui(new Ui::ap)
{
    ui->setupUi(this);


    Movie ElPadrino("El Padrino", "Drama", 1972, "Francis Coppola", 9.2);
    carteleraRef.insertar(&ElPadrino);


    Movie Titanic("Titanic", "Drama", 1997, "James Cameron", 7.8);
    carteleraRef.insertar(&Titanic);


Movie StarWars("Star Wars", "Aventura", 1977, "George Lucas", 8.6);
carteleraRef.insertar(&StarWars);

Movie ElSenorDeLosAnillos("El Senor de los Anillos", "Aventura", 2003, "Peter Jackson", 8.9);
carteleraRef.insertar(&ElSenorDeLosAnillos);

Movie ET("E.T.", "Fantasía", 1982, "Steven Spielberg", 7.8);
carteleraRef.insertar(&ET);


Movie SchindlersList("La lista de Schindler", "Drama", 1993, "Steven Spielberg", 8.9);
carteleraRef.insertar(&SchindlersList);


Movie LoQueElVientoSeLlevo("Lo que el viento se llevó", "Drama", 1939, "Victor Fleming", 8.1);
    carteleraRef.insertar(&LoQueElVientoSeLlevo);


    Movie ForrestGump("ForrestGump", "Drama", 1994, "Robert Zemeckis", 8.8);
    carteleraRef.insertar(&ForrestGump);




}

ap::~ap()
{
    delete ui;

}
void ap::setCarteleraReference(ArbolB& ref)
{
    carteleraRef = ref;
}
void ap::on_PB_anadir_clicked()
{
    QString movieName = ui->QLE_Titulo->text();
    QString movieDir = ui->QLE_Director->text();
    int movieYear = ui->spinBox->value();

    double movieRating = ui->spinBox->value();
    QString movieGenre = "";

    if(ui->accion->isChecked()){
        movieGenre = "accion";
    }else if(ui->aventura->isChecked()){
        movieGenre = "aventura";
    }else if(ui->ciencia->isChecked()){
        movieGenre  = "ciencia";
    }else if(ui->comedia->isChecked()){
        movieGenre = "comedia";
    }else if (ui->drama->isChecked()){
        movieGenre = "drama";
    }else if(ui->fantasia->isChecked()){
        movieGenre = "fantasia";
    }else if (ui->horror->isChecked()){
        movieGenre = "horror";
    }else if (ui->misterio->isChecked()){
        movieGenre = "misterio";
    }else if (ui->thriller->isChecked()){
        movieGenre = "thriller";
    }else{
        movieGenre = "DESCONOCIDO";
    }


    Movie peli(movieName.toStdString(),movieGenre.toStdString(),movieYear,movieDir.toStdString(),movieRating);
    carteleraRef.insertar(&peli);
    ui->QLE_Titulo->clear();
    ui->QLE_Director->clear();
    ui->spinBox->clear();
    ui->doubleSpinBox->clear();
    emit dialogClosed();
    this->hide();


    //EXPORTAR ARCHIVOS
    QFile file("datos_peliculas.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);


        stream << movieName << ";" << movieGenre << ";" << movieYear << ";" << movieDir << ";" << movieRating << "\n";

        file.close();
    } else {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo para escritura.");
    }


}

void ap::on_PB_Ver_clicked()
{



}


void ap::on_PB_imagen_clicked()
{



}

