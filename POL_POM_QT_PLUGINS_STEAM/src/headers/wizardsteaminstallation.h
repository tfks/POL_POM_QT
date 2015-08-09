#ifndef WIZARDSTEAMINSTALLATION_H
#define WIZARDSTEAMINSTALLATION_H

#include <QWizard>

namespace Ui {
class WizardSteamInstallation;
}

class WizardSteamInstallation : public QWizard
{
    Q_OBJECT

public:
    explicit WizardSteamInstallation(QWidget *parent = 0);
    ~WizardSteamInstallation();

private:
    Ui::WizardSteamInstallation *ui;
};

#endif // WIZARDSTEAMINSTALLATION_H
