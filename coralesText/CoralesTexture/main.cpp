#include "coralestext.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CoralesText w;
    w.show();

    return a.exec();
}
