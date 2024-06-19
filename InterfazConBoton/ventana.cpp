#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    ui->boton1->setTexto("Boton 1");
    ui->boton2->setTexto("Boton 2");
    ui->boton3->setTexto("Boton 3");
    ui->boton4->setTexto("Boton 4");
    ui->boton5->setTexto("Cerrar");

    ui->boton1->setColor(Boton::AZUL);
    ui->boton2->setColor(Boton::VERDE);
    ui->boton3->setColor(Boton::AZUL);
    ui->boton4->setColor(Boton::BLANCO);
    ui->boton5->setColor(Boton::ROJO);

    connect(ui->boton5,SIGNAL(signal_click()),this,SLOT(close()));


}

Ventana::~Ventana()
{
    delete ui;
}

