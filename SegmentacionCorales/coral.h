#ifndef CORAL_H
#define CORAL_H

#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include<QFileDialog>
#include <opencv2/opencv.hpp>
#include<scontour.h>

using namespace cv;
using namespace std;

namespace Ui {
class Coral;
}

class Coral : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit Coral(QWidget *parent = 0);
    ~Coral();

    cv::Mat source;//Imagen fuente

    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Coral *ui;

    QString fileName; // Ruta y nombre del archivo
};

#endif // CORAL_H
