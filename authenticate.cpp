#include "authenticate.h"
#include "ui_authenticate.h"
#include "mainwindow.h"

using namespace GW2;

authenticate::authenticate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authenticate)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Dialog);

    QRegExp authRx("^\\s*[\\d]*[\\s]*$");
    QValidator *authVal = new QRegExpValidator(authRx, this);
    ui->authCode->setValidator(authVal);
}

authenticate::~authenticate()
{
    delete ui;
}

QString authenticate::getAuthCode()
{
    return ui->authCode->text().trimmed();
}

void authenticate::on_authMe_pressed()
{
    accept();
}
