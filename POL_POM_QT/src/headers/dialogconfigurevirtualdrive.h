#ifndef DIALOGCONFIGUREVIRTUALDRIVE_H
#define DIALOGCONFIGUREVIRTUALDRIVE_H

#include <QDialog>

namespace Ui {
class DialogConfigureVirtualDrive;
}

class DialogConfigureVirtualDrive : public QDialog
{
    Q_OBJECT

public:
    explicit DialogConfigureVirtualDrive(QWidget *parent = 0);
    ~DialogConfigureVirtualDrive();

private slots:
    void on_pbtnOk_clicked();
    void on_pbtnCancel_clicked();

private:
    Ui::DialogConfigureVirtualDrive *ui;
};

#endif // DIALOGCONFIGUREVIRTUALDRIVE_H
