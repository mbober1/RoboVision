/********************************************************************************
** Form generated from reading UI file 'connectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDIALOG_H
#define UI_CONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEditTcpPort;
    QDialogButtonBox *buttonBox;
    QLabel *label_2;
    QLineEdit *lineEditAdress;
    QLineEdit *lineEditUdpPort;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ConnectionDialog)
    {
        if (ConnectionDialog->objectName().isEmpty())
            ConnectionDialog->setObjectName(QString::fromUtf8("ConnectionDialog"));
        ConnectionDialog->resize(351, 237);
        gridLayout = new QGridLayout(ConnectionDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        lineEditTcpPort = new QLineEdit(ConnectionDialog);
        lineEditTcpPort->setObjectName(QString::fromUtf8("lineEditTcpPort"));
        lineEditTcpPort->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEditTcpPort->sizePolicy().hasHeightForWidth());
        lineEditTcpPort->setSizePolicy(sizePolicy);
        lineEditTcpPort->setMinimumSize(QSize(60, 0));
        lineEditTcpPort->setMaximumSize(QSize(60, 16777215));
        lineEditTcpPort->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditTcpPort->setMaxLength(5);
        lineEditTcpPort->setFrame(true);
        lineEditTcpPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditTcpPort, 4, 2, 1, 1);

        buttonBox = new QDialogButtonBox(ConnectionDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 2, 1, 1);

        label_2 = new QLabel(ConnectionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 4, 1, 1, 1);

        lineEditAdress = new QLineEdit(ConnectionDialog);
        lineEditAdress->setObjectName(QString::fromUtf8("lineEditAdress"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEditAdress->sizePolicy().hasHeightForWidth());
        lineEditAdress->setSizePolicy(sizePolicy1);
        lineEditAdress->setMinimumSize(QSize(0, 0));
        lineEditAdress->setMaximumSize(QSize(500, 16777215));
        lineEditAdress->setMaxLength(50);
        lineEditAdress->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditAdress, 2, 2, 1, 1);

        lineEditUdpPort = new QLineEdit(ConnectionDialog);
        lineEditUdpPort->setObjectName(QString::fromUtf8("lineEditUdpPort"));
        lineEditUdpPort->setEnabled(true);
        sizePolicy.setHeightForWidth(lineEditUdpPort->sizePolicy().hasHeightForWidth());
        lineEditUdpPort->setSizePolicy(sizePolicy);
        lineEditUdpPort->setMinimumSize(QSize(60, 0));
        lineEditUdpPort->setMaximumSize(QSize(60, 16777215));
        lineEditUdpPort->setInputMethodHints(Qt::ImhDigitsOnly);
        lineEditUdpPort->setMaxLength(5);
        lineEditUdpPort->setFrame(true);
        lineEditUdpPort->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEditUdpPort, 3, 2, 1, 1);

        label = new QLabel(ConnectionDialog);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 0, 1, 1);

        label_3 = new QLabel(ConnectionDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);


        retranslateUi(ConnectionDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectionDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectionDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDialog)
    {
        ConnectionDialog->setWindowTitle(QCoreApplication::translate("ConnectionDialog", "Dialog", nullptr));
        lineEditTcpPort->setText(QCoreApplication::translate("ConnectionDialog", "8091", nullptr));
        lineEditTcpPort->setPlaceholderText(QString());
        label_2->setText(QCoreApplication::translate("ConnectionDialog", "TCP PORT", nullptr));
        lineEditAdress->setText(QCoreApplication::translate("ConnectionDialog", "192.168.31.225", nullptr));
        lineEditUdpPort->setText(QCoreApplication::translate("ConnectionDialog", "8090", nullptr));
        lineEditUdpPort->setPlaceholderText(QString());
        label->setText(QCoreApplication::translate("ConnectionDialog", "IP", nullptr));
        label_3->setText(QCoreApplication::translate("ConnectionDialog", "UDP PORT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDialog: public Ui_ConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDIALOG_H
