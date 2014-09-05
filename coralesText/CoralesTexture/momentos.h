#ifndef MOMENTOS_H
#define MOMENTOS_H

#include <opencv2/opencv.hpp>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


class momentos
{
public:
    momentos();
    cv::Mat imageGris;
    std::vector<double> *histograma;
    std::vector<double> *histogramaNormalizado;
    double media;
    double primerMomento;
    double segundoMomento;
    double tercerMomento;
    double uniformidad;
    double entropia;

    int calcularMomentos(cv::Mat &image);

};

#endif // MOMENTOS_H
