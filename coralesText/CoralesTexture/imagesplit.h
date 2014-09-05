#ifndef IMAGESPLIT_H
#define IMAGESPLIT_H

#include <opencv2/opencv.hpp>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>



class imageSplit
{
public:
    imageSplit();


    static std::vector<cv::Mat> div(cv::Mat  src0,int verDivisions,int horDivisions);



};

#endif // IMAGESPLIT_H
