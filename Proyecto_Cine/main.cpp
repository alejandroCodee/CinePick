#include "mainwindow.h"
#include "welcome.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Welcome *we = new Welcome();
    MainWindow *mainWindow = new MainWindow;
        we->show();


    int result = a.exec();



    return result;
}
