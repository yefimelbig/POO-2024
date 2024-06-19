#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "downloadwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    Ui::Login *ui;
    DownloadWindow *downloadWindow;

private slots:
    void on_btnLogin_clicked();
};

#endif // LOGIN_H
