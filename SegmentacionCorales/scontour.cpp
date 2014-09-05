#include "scontour.h"

Scontour::Scontour()
{
}

Scontour::~Scontour()
{
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Encuentra la intensidad mayor en la imagen  la coloca en inten,retorna código de error.

***************************************************************************************************/

int Scontour::GetContourMask(const cv::Mat& Mat,cv::Mat& dst,std::vector<std::vector<cv::Point> > &contours, int _Threshold,int ContourMode, int ContourPixels)
{
    /* 0: Binary
       1: Binary Inverted
       2: Threshold Truncated
       3: Threshold to Zero
       4: Threshold to Zero Inverted
     */

    cv::threshold(Mat,dst,_Threshold,255,1);

    cv::Mat element3(3,3,CV_8U,cv::Scalar(1));
    //cout<<element3;
    //cv::dilate(dst,dst,element3,Point(-1,-1),4);
    /*cv::morphologyEx(   dst,
                        dst,
                        MORPH_TOPHAT,
                        element3,
                        Point(-1,-1),
                        100);*/
    //imshow("binarizada",dst);
    //element3.~Mat();

    cv::findContours(   dst,
                        contours, // a vector of contours
                        ContourMode, // retrieve the external contours
                        ContourPixels); // all pixels of each contours
    return 1;
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Encuentra la intensidad mayor en la imagen  la coloca en inten,retorna código de error.

***************************************************************************************************/

int Scontour::GetBiggestContour(std::vector<vector<Point> > &contours, std::vector<Point> &Big, double Area)
{

    //std::cout<<"tamaño: "<<contours.size();
    int keeper=0;
    for(int index=0;index<(int)contours.size();index++)
    {
        if(cv::contourArea(contours[index])>Area)
        {
            Area=cv::contourArea(contours[index]);//calcula el area del contorno
            keeper=index;//captura el indice del contorno de interes
        }
    }
    Big=contours[keeper];
    //cout<<cv::contourArea(Biggest)<<"....."<<endl;
    return 1;
}


/***************************************************************************************************
Metodos

Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Encuentra los 5 ocntornos mas grandes.

***************************************************************************************************/

int Scontour::GetBiggestFiveContour(std::vector<vector<Point> > &contours,std::vector<vector<Point> > &Big, double Area)
{

    //std::cout<<"tamaño: "<<contours.size();
    int num=0;
    for(int index=0;index<(int)contours.size();index++)
    {
        if(cv::contourArea(contours[index])>Area)
        {
            Area=cv::contourArea(contours[index]);//calcula el area del contorno
     	   // Big[num]=contours[index];
	    num++;
	    if(num>4)num=0;		
        }
    }
    
    //cout<<cv::contourArea(Biggest)<<"....."<<endl;
    return 1;
}

/***************************************************************************************************
Metodos
Autor: Alexander Gómez villa - Sebastian Guzman Obando - German Diez Valencia
Descripcion: Encuentra la intensidad mayor en la imagen  la coloca en inten,retorna código de error.

***************************************************************************************************/

int Scontour::AreaBandPass(vector<vector<Point> > &contours, double min, double max)
{
    std::vector<std::vector< cv::Point> >::iterator itc= contours.begin();
    while (itc!=contours.end()) {
    if (itc->size() < min || itc->size() > max)//
    itc = contours.erase(itc);
    else
    ++itc;
    }
    return 1;
}



bool Scontour::widthHeighBandPass(const cv::Mat &a, int widthMin, int widthMax , int heightMin, int heightMax)
{

    if(a.cols>widthMin && a.cols<widthMax)
    {
        if(a.rows>heightMin && a.rows<heightMax)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;

}


