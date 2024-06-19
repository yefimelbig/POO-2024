#include "boton.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Boton w;
    w.setTexto( "Boton 1");
    w.setColor(Boton::ROJO);
    w.show();
    return a.exec();
}
