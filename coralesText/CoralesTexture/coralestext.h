#ifndef CORALESTEXT_H
#define CORALESTEXT_H

#include <QMainWindow>
#include"momentos.h"
#include <opencv2/opencv.hpp>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<qdebug.h>


using namespace cv;
using namespace std;

namespace Ui {
class CoralesText;
}

class CoralesText : public QMainWindow
{
    Q_OBJECT

public:
    explicit CoralesText(QWidget *parent = 0);
    ~CoralesText();

    momentos mom;
    cv::Mat src;
    cv::Mat srcCopy;

    //data

    cv::Mat data;
    int int_cont;


    cv::Mat Extract(cv::Mat  src0,int verDivisions,int horDivisions);
    cv::Mat Extractpintar(cv::Mat  src0, int verDivisions, int horDivisions, Mat labels);

private slots:
    void on_pushButton_released();

private:
    Ui::CoralesText *ui;
};

#endif // CORALESTEXT_H
