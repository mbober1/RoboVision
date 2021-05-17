
#include <QDialog>

namespace Ui {
class AboutDialog;
}


/*!
*   \file 
*   \brief The file contains the pop-up dialog class.
*/

/**
    @brief About program pop-up dialog class
*/
class AboutProgramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutProgramDialog(QWidget *parent = nullptr);
    ~AboutProgramDialog();

private:
    Ui::AboutDialog *ui;
};

