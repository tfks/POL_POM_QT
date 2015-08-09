#ifndef WIZARDNEWVIRTUALDRIVE_H
#define WIZARDNEWVIRTUALDRIVE_H

#include <QWizard>

namespace Ui {
class WizardNewVirtualDrive;
}

class WizardNewVirtualDrive : public QWizard
{
    Q_OBJECT

public:
    explicit WizardNewVirtualDrive(QWidget *parent = 0);
    ~WizardNewVirtualDrive();

private slots:
    void on_pbtnDefaultApplicationLocationBrowse_clicked();

    void on_bptnVirtualDriveIconBrowse_clicked();

    void on_WizardNewVirtualDrive_finished(int result);

private:
    Ui::WizardNewVirtualDrive *ui;

    QPixmap selectedIcon;
};

#endif // WIZARDNEWVIRTUALDRIVE_H
