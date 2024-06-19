#include "ventana.h"
#include <QPainter>
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
    , manager ( new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect (manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(slot_descargaFinalizada(QNetworkReply*)));
    QString sUrl = "https://cert.pa/wp-content/uploads/2021/03/OpenSSL.png";
    manager ->get(QNetworkRequest(QUrl(sUrl)));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::paintEvent(QPaintEvent *)
{
    QPainter painter ( this );

    if ( ! im.isNull())
        painter.drawImage(0,0,im.scaled(this->width(),this->height()));




}

void Ventana::slot_descargaFinalizada(QNetworkReply *reply)
{
   im = QImage::fromData(reply->readAll());
   this->repaint();
}

