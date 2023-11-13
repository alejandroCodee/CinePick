#ifndef INFO_PROGRAMA_H
#define INFO_PROGRAMA_H

#include "arbolb.h"
#include <QDialog>

namespace Ui {
class info_programa;
}

class info_programa : public QDialog
{
    Q_OBJECT

public:
    explicit info_programa(QWidget *parent = nullptr);
    ~info_programa();

private slots:
    void on_PeliculasNuevas_clicked();

    void on_Recorridos_clicked();

    void on_pushButton_clicked();

private:
    Ui::info_programa *ui;
    ArbolB* arbol;


};

#endif // INFO_PROGRAMA_H
