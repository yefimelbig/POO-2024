#include "downloadwindow.h"
#include "ui_downloadwindow.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QPixmap>
#include <QMessageBox>


DownloadWindow::DownloadWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DownloadWindow),
    manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    connect(ui->btnDownload, &QPushButton::clicked, this, &DownloadWindow::on_btnDownload_clicked);
    connect(manager, &QNetworkAccessManager::finished, this, &DownloadWindow::fileDownloaded);
}

DownloadWindow::~DownloadWindow()
{
    delete ui;
}

void DownloadWindow::on_btnDownload_clicked()
{
    QUrl url(ui->lineEditURL->text());
    QNetworkRequest request(url);
    manager->get(request);
}

void DownloadWindow::fileDownloaded(QNetworkReply* pReply)
{
    if (pReply->error() == QNetworkReply::NoError) {
        QByteArray data = pReply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(data);
        ui->labelImage->setPixmap(pixmap);
    } else {
        QMessageBox::warning(this, "Download Failed", "Failed to download the image");
    }
    pReply->deleteLater();
}
