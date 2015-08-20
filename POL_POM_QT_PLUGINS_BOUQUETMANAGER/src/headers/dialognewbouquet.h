#ifndef DIALOGNEWBOUQUET_H
#define DIALOGNEWBOUQUET_H

#include <QDialog>
#include <QPixmap>

namespace Ui {
class DialogNewBouquet;
}

class DialogNewBouquet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewBouquet(QWidget *parent = 0);
    ~DialogNewBouquet();

private slots:
    void on_pbtnBrowse_clicked();
    void on_pbtnOk_clicked();
    void on_pbtnCancel_clicked();

private:
    Ui::DialogNewBouquet *ui;

    QPixmap selectedIcon;
};

#endif // DIALOGNEWBOUQUET_H
