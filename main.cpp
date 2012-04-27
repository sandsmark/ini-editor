#include <QtGui/QApplication>
#include "dialog.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
        return -1;
    QApplication a(argc, argv);
    Dialog w(qApp->arguments().at(1));
    w.show();
    
    return a.exec();
}
