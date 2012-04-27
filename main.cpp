#include <QtGui/QApplication>
#include <QMessageBox>
#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    if (argc < 2) {
        QMessageBox::critical(0, "No ini file supplied!", "Please supply an ini file to open as first argument.");
        return -1;
    }

    Dialog w(qApp->arguments().at(1));
    w.show();
    
    return a.exec();
}
