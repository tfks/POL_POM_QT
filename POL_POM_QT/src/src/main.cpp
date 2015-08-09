#include "headers/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setApplicationDisplayName("PlayOnLinux Qt");
    QApplication::setApplicationName("PlayOnLinux");
    QApplication::setApplicationVersion("0.1");
    QApplication::setOrganizationName("TFK");

    MainWindow w;
    w.show();

    return a.exec();
}
