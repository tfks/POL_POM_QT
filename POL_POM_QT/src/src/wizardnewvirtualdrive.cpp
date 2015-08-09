#include <QFileDialog>

#include "headers/constants.h"

#include "headers/wizardnewvirtualdrive.h"
#include "ui_wizardnewvirtualdrive.h"


WizardNewVirtualDrive::WizardNewVirtualDrive(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::WizardNewVirtualDrive)
{
    ui->setupUi(this);

    ui->lblValidatorVirtualDriveName->setVisible(false);
}

WizardNewVirtualDrive::~WizardNewVirtualDrive()
{
    delete ui;
}

void WizardNewVirtualDrive::on_pbtnDefaultApplicationLocationBrowse_clicked()
{
    QString fileName = QFileDialog::getExistingDirectory(this,
                                                         QString::fromStdString(POL_OPEN_DEFAULT_APPLICATION_LOCATION),
                                                         QDir::homePath(),
                                                         QFileDialog::ShowDirsOnly);

    if (fileName != "") ui->lblDefaultApplicationLocationSelected->setText(fileName);
}

void WizardNewVirtualDrive::on_bptnVirtualDriveIconBrowse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QString::fromStdString(POL_SELECT_ICON_FOR_VIRTUAL_DRIVE),
                                                    QDir::homePath(),
                                                    QString::fromStdString(POL_FILTERS_ICON_SELECTION));

    if (fileName != "")
    {
        this->selectedIcon = QPixmap(fileName);

        ui->lblVirtualDriveIconSelected->setPixmap(this->selectedIcon);
    }
}

void WizardNewVirtualDrive::on_WizardNewVirtualDrive_finished(int result)
{
    Q_UNUSED(result);
    // Collect all data from dialog elements and store in property.
}
