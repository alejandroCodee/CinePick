#ifndef WELCOME_H
#define WELCOME_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class Welcome;
}

class Welcome : public QDialog
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = nullptr);
    ~Welcome();

private slots:
    void on_pushButton_clicked();

    void on_label_2_linkActivated(const QString &link);

private:
    Ui::Welcome *ui;
    MainWindow m;
};

#endif // WELCOME_H
