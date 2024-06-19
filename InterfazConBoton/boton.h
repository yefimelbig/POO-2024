#ifndef BOTON_H
#define BOTON_H

#include <QWidget>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Boton; }
QT_END_NAMESPACE

class Boton : public QWidget
{
    Q_OBJECT

public:
    Boton(QWidget *parent = nullptr);
    ~Boton();

    void setTexto(QString texto);
    enum Color { BLANCO, ROJO, AZUL, VERDE };
    void setColor(Color color);

 protected:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *);


private:
    Ui::Boton *ui;
    Color color;

signals:
    void signal_click();
};
#endif // BOTON_H
