#include <QFileDialog>

#include "headers/constants.h"

#include "headers/dialogaddbouquet.h"
#include "ui_dialogaddbouquet.h"


DialogAddBouquet::DialogAddBouquet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAddBouquet)
{
    ui->setupUi(this);

    this->connect(ui->btnbOkCancel, SIGNAL(accepted()), this, SLOT(on_pbtnOk_clicked()));
    this->connect(ui->btnbOkCancel, SIGNAL(rejected()), this, SLOT(on_pbtnCancel_clicked()));
}

DialogAddBouquet::~DialogAddBouquet()
{
    delete ui;
}

void DialogAddBouquet::on_pbtnBrowse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    QString::fromStdString(POL_SELECT_ICON_FOR_BOUQUET),
                                                    QDir::homePath(),
                                                    QString::fromStdString(POL_FILTERS_ICON_SELECTION));
    if (fileName != "")
    {
        this->selectedIcon = QPixmap(fileName);

        ui->lblIconSelected->setPixmap(this->selectedIcon);
    }
}

void DialogAddBouquet::on_pbtnOk_clicked()
{
    // Get all data from dialog elements and store in property.

    done(QDialog::Accepted);
}

void DialogAddBouquet::on_pbtnCancel_clicked()
{
    done(QDialog::Rejected);
}
