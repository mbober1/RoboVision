#include "connectiondialog.h"
#include "ui_connectiondialog.h"

ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    ui->lineEditTcpPort->setInputMask("99000");
    ui->lineEditUdpPort->setInputMask("99000");
    ui->lineEditAdress->setInputMask("900.900.900.900");
}

ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}


QString ConnectionDialog::getAdress() {
    return ui->lineEditAdress->text();
}


int ConnectionDialog::getUdpPort() {
    return ui->lineEditUdpPort->text().toInt();
}

int ConnectionDialog::getTcpPort() {
    return ui->lineEditTcpPort->text().toInt();
}