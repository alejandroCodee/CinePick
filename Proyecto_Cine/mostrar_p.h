#ifndef MOSTRAR_P_H
#define MOSTRAR_P_H
#include "Movie.h"
#include <QDialog>

namespace Ui {
class Mostrar_p;
}

class Mostrar_p : public QDialog
{
    Q_OBJECT

public:
    explicit Mostrar_p(QWidget *parent = nullptr);
    ~Mostrar_p();
    void actualizarInformacion(const Movie& pelicula);

    void cargarImagen(const QString& imagePath);
    void setTitulo(const QString& titulo);



private:
    Ui::Mostrar_p *ui;
};

#endif // MOSTRAR_P_H
