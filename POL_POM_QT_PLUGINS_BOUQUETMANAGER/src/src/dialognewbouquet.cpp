#include <QFileDialog>

#include "headers/constants.h"

#include "../headers/dialognewbouquet.h"
#include "ui_dialognewbouquet.h"


DialogNewBouquet::DialogNewBouquet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNewBouquet)
{
    ui->setupUi(this);

    this->connect(ui->btnbOkCancel, SIGNAL(accepted()), this, SLOT(on_pbtnOk_clicked()));
    this->connect(ui->btnbOkCancel, SIGNAL(rejected()), this, SLOT(on_pbtnCancel_clicked()));
}

DialogNewBouquet::~DialogNewBouquet()
{
    delete ui;
}

void DialogNewBouquet::on_pbtnBrowse_clicked()
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

void DialogNewBouquet::on_pbtnOk_clicked()
{
    // Get all data from dialog elements and store in property.

    done(QDialog::Accepted);
}

void DialogNewBouquet::on_pbtnCancel_clicked()
{
    done(QDialog::Rejected);
}
