#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ap.h"
#include "rp.h"
#include <QMainWindow>
#include "arbolb.h"
#include "Movie.h"
#include "info_programa.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ArbolB* cartelera;
    friend class ap;
    friend class rp;

private slots:
    void on_PB_Insertar_Pelicula_clicked();
    void on_PB_Buscar_Pelicula_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    info_programa ip;
    ap a;
    rp r;

    void showMainWindow();

};
#endif // MAINWINDOW_H
