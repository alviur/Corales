#include <QApplication>
#include "coral.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Coral w;
    w.show();
    
    return a.exec();
}
