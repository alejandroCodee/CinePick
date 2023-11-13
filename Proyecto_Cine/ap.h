#ifndef AP_H
#define AP_H
#include "Movie.h"
#include "arbolb.h"





#include <QDialog>
class ArbolB;
namespace Ui {
class ap;
}

class ap : public QDialog
{
    Q_OBJECT

public:
    explicit ap(ArbolB& ref, QWidget *parent);
    ~ap();
void setCarteleraReference(ArbolB& ref);
private slots:

    void on_PB_anadir_clicked();



    void on_PB_Ver_clicked();

    void on_PB_imagen_clicked();

private:
    Ui::ap *ui;
    ArbolB& carteleraRef;
signals:
    void dialogClosed();
};

#endif // AP_H
