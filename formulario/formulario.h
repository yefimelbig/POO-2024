#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QVector>
#include <QString>

namespace Ui {
class Formulario;
}

class Persona {
public:
    Persona(const QString &nombre = "", const QString &apellido = "", const QString &dni = "");
    QString getNombre() const;
    void setNombre(const QString &nombre);
    QString getApellido() const;
    void setApellido(const QString &apellido);
    QString getDni() const;
    void setDni(const QString &dni);

private:
    QString nombre;
    QString apellido;
    QString dni;
};

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);
    ~Formulario();

signals:
    void personaRegistrada(const Persona &persona);

private slots:
    void onPushButtonRegistrarClicked();

private:
    Ui::Formulario *ui;
    QVector<Persona> registroPersonas;
};

#endif // FORMULARIO_H
