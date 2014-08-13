#ifndef PRUEBACLUST_H
#define PRUEBACLUST_H

#include <QMainWindow>

namespace Ui {
class pruebaClust;
}

class pruebaClust : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit pruebaClust(QWidget *parent = 0);
    ~pruebaClust();
    
private:
    Ui::pruebaClust *ui;
};

#endif // PRUEBACLUST_H
