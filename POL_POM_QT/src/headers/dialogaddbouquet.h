#ifndef DIALOGADDBOUQUET_H
#define DIALOGADDBOUQUET_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class DialogAddBouquet;
}

class DialogAddBouquet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAddBouquet(QWidget *parent = 0);
    ~DialogAddBouquet();

private slots:
    void on_pbtnBrowse_clicked();
    void on_pbtnOk_clicked();
    void on_pbtnCancel_clicked();

private:
    Ui::DialogAddBouquet *ui;

    QPixmap selectedIcon;
};

#endif // DIALOGADDBOUQUET_H
