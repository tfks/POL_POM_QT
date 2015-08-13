#include "../headers/dialogconfigurevirtualdrive.h"
#include "ui_dialogconfigurevirtualdrive.h"

DialogConfigureVirtualDrive::DialogConfigureVirtualDrive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogConfigureVirtualDrive)
{
    ui->setupUi(this);

    this->connect(ui->btnbOkCancel, SIGNAL(accepted()), this, SLOT(on_pbtnOk_clicked()));
    this->connect(ui->btnbOkCancel, SIGNAL(rejected()), this, SLOT(on_pbtnCancel_clicked()));
}

DialogConfigureVirtualDrive::~DialogConfigureVirtualDrive()
{
    delete ui;
}

void DialogConfigureVirtualDrive::on_pbtnOk_clicked()
{
    // Get all data from dialog elements and store in property.

    done(QDialog::Accepted);
}

void DialogConfigureVirtualDrive::on_pbtnCancel_clicked()
{

    done(QDialog::Rejected);
}
