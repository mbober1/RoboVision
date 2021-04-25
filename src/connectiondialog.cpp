#include "connectiondialog.h"
#include "ui_connectiondialog.h"


/**
 * A constructor.
 * @param parent QWidget type parent.
 */
ConnectionDialog::ConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConnectionDialog)
{
    ui->setupUi(this);
    ui->lineEditTcpPort->setInputMask("99000");
    ui->lineEditUdpPort->setInputMask("99000");
    ui->lineEditAdress->setInputMask("900.900.900.900");
}


/**
 * A destructor.
 */
ConnectionDialog::~ConnectionDialog()
{
    delete ui;
}


/**
 * Get adress for connection.
 * @return IP address of server.
 */
QString ConnectionDialog::getAdress() {
    return ui->lineEditAdress->text();
}


/**
 * Get UDP port
 * @return UDP server port.
 */
int ConnectionDialog::getUdpPort() {
    return ui->lineEditUdpPort->text().toInt();
}


/**
 * Get TCP port
 * @return TCP server port.
 */
int ConnectionDialog::getTcpPort() {
    return ui->lineEditTcpPort->text().toInt();
}