#include <QApplication>
#include "pruebaclust.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    pruebaClust w;
    w.show();
    
    return a.exec();
}
