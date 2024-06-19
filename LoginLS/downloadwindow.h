#ifndef DOWNLOADWINDOW_H
#define DOWNLOADWINDOW_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <ui_downloadwindow.h>



QT_BEGIN_NAMESPACE
namespace Ui { class DownloadWindow; }
QT_END_NAMESPACE

class DownloadWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DownloadWindow(QWidget *parent = nullptr);
    ~DownloadWindow();

private slots:
    void on_btnDownload_clicked();
    void fileDownloaded(QNetworkReply* pReply);

private:
    Ui::DownloadWindow *ui;
    QNetworkAccessManager *manager;
};

#endif // DOWNLOADWINDOW_H
