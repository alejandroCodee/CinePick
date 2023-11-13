#ifndef RP_H
#define RP_H
#include "Movie.h"
#include <QDialog>
#include "mostrar_p.h"
#include "arbolb.h"



#include "ap.h";





class ArbolB;
namespace Ui {
class rp;
}

class rp : public QDialog
{
    Q_OBJECT

public:
    explicit rp(ArbolB& ref, QWidget *parent) ;
    ~rp();
    void setCarteleraReference(ArbolB& ref);



private slots:

    void on_pushButton_clicked();

private:
    Ui::rp *ui;

    ArbolB& carteleraRef;

signals:
        void dialogClosed();
};

#endif // RP_H
