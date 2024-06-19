#include "login.h"
#include "ui_login.h"
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login),
    downloadWindow(new DownloadWindow)
{
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &Login::on_btnLogin_clicked);
}

Login::~Login()
{
    delete ui;
    delete downloadWindow;
}

void Login::on_btnLogin_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if (username == "admin" && password == "1234") {
        this->hide();
        downloadWindow->show();
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect username or password");
    }
}
