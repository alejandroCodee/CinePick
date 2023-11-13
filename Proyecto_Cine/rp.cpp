#include "rp.h"
#include "mostrar_p.h"
#include "ui_rp.h"
#include <QMessageBox>
#include <string>
#include <QFile>

rp::rp(ArbolB& ref, QWidget *parent) : QDialog(parent), carteleraRef(ref), ui(new Ui::rp)
{
    ui->setupUi(this);

    //Mostrar_p mp;
}
rp::~rp()
{
    delete ui;
}
void rp::setCarteleraReference(ArbolB& ref)
{
    carteleraRef = ref;
}


void rp::on_pushButton_clicked()
{
    QString temp2 = ui->lineEdit->text();

    std::string temp3 = temp2.toStdString();

    Movie *temp = carteleraRef.searchByTitle(temp3);
    if(temp){
        QMessageBox::information(this,"INFO SE ENCONTRO",temp2);

        QString imagePath = "C:/Users/aleja/OneDrive/Documents/Universidad/Estructura de datos II/PROYECYTO/Proyecto_Cine/Proyecto_Cine/POSTERS/" + temp2 + ".jpg";
 QString noImagePath = "C:/Users/aleja/OneDrive/Documents/Universidad/Estructura de datos II/PROYECYTO/Proyecto_Cine/Proyecto_Cine/POSTERS/No.jpg";

        if (QFile::exists(imagePath)) {
            Mostrar_p* mostrarPelicula = new Mostrar_p(this);
            mostrarPelicula->actualizarInformacion(*temp);

            mostrarPelicula->cargarImagen(imagePath);
             mostrarPelicula->setTitulo(temp2);

            mostrarPelicula->exec();
            mostrarPelicula->show();
        } else {


            Mostrar_p* mostrarPelicula = new Mostrar_p(this);
            mostrarPelicula->actualizarInformacion(*temp);
            mostrarPelicula->cargarImagen(noImagePath);
            mostrarPelicula->setTitulo(temp2);
            mostrarPelicula->exec();
            mostrarPelicula->show();
        }

    }else{
        QMessageBox::critical(this,"ERROR", "NO SE ENCONTRO");

        QMessageBox preguntaDialog;
        preguntaDialog.setWindowTitle("Película no encontrada");
            preguntaDialog.setText("¿Desea añadir la película?");
        preguntaDialog.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        preguntaDialog.setDefaultButton(QMessageBox::Yes);

        int respuesta = preguntaDialog.exec();

        if (respuesta == QMessageBox::Yes) {
            //aqui deberia de ir ap xdd

        }
    }


}

