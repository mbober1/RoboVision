#ifndef CONNECTIONDIALOG_HPP
#define CONNECTIONDIALOG_HPP

#include <QDialog>

namespace Ui {
class ConnectionDialog;
}


/**
    @brief Connection pop-up dialog class
*/
class ConnectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectionDialog(QWidget *parent = nullptr);
    ~ConnectionDialog();
    QString getAdress();
    int getUdpPort();
    int getTcpPort();

private:
    Ui::ConnectionDialog *ui;
};

#endif // CONNECTIONDIALOG_HPP
