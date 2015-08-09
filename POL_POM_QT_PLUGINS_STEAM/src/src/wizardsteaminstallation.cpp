#include "headers/wizardsteaminstallation.h"
#include "ui_wizardsteaminstallation.h"

WizardSteamInstallation::WizardSteamInstallation(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::WizardSteamInstallation)
{
    ui->setupUi(this);
}

WizardSteamInstallation::~WizardSteamInstallation()
{
    delete ui;
}
