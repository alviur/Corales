#include "momentos.h"

momentos::momentos()
{
    histograma = new std::vector<double>(256,0);
    histogramaNormalizado = new std::vector<double>(256,0);
    media = 0;
    primerMomento = 0;
    segundoMomento = 0;
    tercerMomento = 0;
    uniformidad = 0;
    entropia = 0;
}

int momentos::calcularMomentos(cv::Mat &image)
{
    std::fill(histograma->begin()           ,histograma->end()           , 0);
    std::fill(histogramaNormalizado->begin(),histogramaNormalizado->end(), 0);
    media           = 0;
    primerMomento   = 0;
    segundoMomento  = 0;
    tercerMomento   = 0;
    uniformidad     = 0;
    entropia        = 0;

    cv::Mat imageGray;
    ////VALIDACION Y CONVERSION A UN CANAL
    if(image.channels() == 3 && image.data != NULL){
        cvtColor(image,imageGray,cv::COLOR_BGR2GRAY);
    }else
    {
        return 0;
    }
    if(image.channels()==1)
    {
        image.copyTo(imageGray);
    }

    //cv::imshow("gris",imageGray);

    for(int i = 0; i < imageGray.rows; i++)
    {
        for(int j = 0; j < imageGray.cols; j++)
        {
            // int intensidad = imageGray.at<uchar>(i,j);
            histograma->at(imageGray.at<uchar>(i,j)) = (double)(histograma->at(imageGray.at<uchar>(i,j))+1);
        }

    }

    for(int i = 0; i < histograma->size(); i++)
    {
        histogramaNormalizado->at(i) = (double)(histograma->at(i) / (imageGray.rows*imageGray.cols));
        media = media + (double)(histogramaNormalizado->at(i)*i);
    }

   for(int i = 0; i < 256; i++)
    {
        primerMomento  = primerMomento  + ((double)(i-media)*(histogramaNormalizado->at(i))); //Debe ser igual a cero
        segundoMomento = segundoMomento + ((double)(pow((i-media),2))*(histogramaNormalizado->at(i))); //Esta es la varianza
        tercerMomento  = tercerMomento  + ((double)(pow((i-media),3))*(histogramaNormalizado->at(i)));
        uniformidad    = uniformidad    + ((double)(pow(histogramaNormalizado->at(i),2)));
        if(histogramaNormalizado->at(i) != 0)
        {
            entropia = (double)entropia - ((double)histogramaNormalizado->at(i)*((double)log(histogramaNormalizado->at(i))/log(2)));
        }
    }
   imageGray.~Mat();
   //std::cout<<media<<" "<<primerMomento <<" " <<segundoMomento<<"\n ";

   return 1;
}
