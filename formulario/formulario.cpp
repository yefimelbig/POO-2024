#include "formulario.h"
#include "ui_formulario.h"
#include <QMessageBox>

// Implementación de la clase Persona
Persona::Persona(const QString &nombre, const QString &apellido, const QString &dni)
    : nombre(nombre), apellido(apellido), dni(dni) {}

QString Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const QString &nombre) {
    this->nombre = nombre;
}

QString Persona::getApellido() const {
    return apellido;
}

void Persona::setApellido(const QString &apellido) {
    this->apellido = apellido;
}

QString Persona::getDni() const {
    return dni;
}

void Persona::setDni(const QString &dni) {
    this->dni = dni;
}

// Implementación de la clase Formulario
Formulario::Formulario(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &Formulario::onPushButtonRegistrarClicked);
}

Formulario::~Formulario()
{
    delete ui;
}

void Formulario::onPushButtonRegistrarClicked()
{
    QString nombre = ui->LineEditNombre->text();
    QString apellido = ui->lineEditApellido->text();
    QString dni = ui->lineEditDni->text();

    if (nombre.isEmpty() || apellido.isEmpty() || dni.isEmpty()) {
        QMessageBox::warning(this, "Datos incompletos", "Por favor, complete todos los campos.");
        return;
    }

    Persona nuevaPersona(nombre, apellido, dni);
    registroPersonas.append(nuevaPersona);

    emit personaRegistrada(nuevaPersona);

    QMessageBox::information(this, "Registrado", "La persona ha sido registrada exitosamente.");

    ui->LineEditNombre->clear();
    ui->lineEditApellido->clear();
    ui->lineEditDni->clear();
}
