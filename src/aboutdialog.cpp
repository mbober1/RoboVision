#include "aboutdialog.h"
#include "ui_aboutdialog.h"

/**
 * A constructor.
 * @param[in,out] parent QWidget type parent.
 */
AboutProgramDialog::AboutProgramDialog(QWidget *parent) : 
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

/**
 * A destructor.
 */
AboutProgramDialog::~AboutProgramDialog()
{
    delete ui;
}
