#include "pruebaclust.h"
#include "ui_pruebaclust.h"

pruebaClust::pruebaClust(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pruebaClust)
{
    ui->setupUi(this);
}

pruebaClust::~pruebaClust()
{
    delete ui;
}
