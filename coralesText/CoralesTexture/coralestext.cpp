#include "coralestext.h"
#include "ui_coralestext.h"

CoralesText::CoralesText(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CoralesText)
{
    ui->setupUi(this);
    int_cont=0;
}

CoralesText::~CoralesText()
{
    delete ui;
}


string convertInt(int number)
{
    if (number == 0)
        return "0";
    string temp="";
    string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}


cv::Mat CoralesText::Extract(cv::Mat  src0,int verDivisions,int horDivisions)
{

    cv::Mat src;
    src0.copyTo(src);
//    int int_divisionNumberVer=src.rows/horDivisions;
//    int int_divisionNumberHor=src.cols/verDivisions;
//cv::Mat data(300,5,CV_32F);


int i=0;

//    while(i-int_divisionNumberVer<src.cols-1)
//    {
//         int y=0;

//        while(y<src.rows-1)
//        {



//            if(i+int_divisionNumberVer<src.cols && y+int_divisionNumberHor<src.rows)
//            {

//                Rect cuadrito(i,y,int_divisionNumberVer,int_divisionNumberHor);
//                //rectangle(src,cuadrito,cv::Scalar(250,0,0,0),2,8,0);
//                srcCopy=src(cuadrito);
//                mom.calcularMomentos(srcCopy);
//                data.at<float>(0,int_cont)=mom.media ;
//                data.at<float>(1,int_cont)=mom.segundoMomento;
//                data.at<float>(2,int_cont)=mom.tercerMomento;
//                data.at<float>(3,int_cont)=mom.uniformidad ;
//                data.at<float>(4,int_cont)=mom.entropia;

//                int_cont++;


//            }
//            else if((i+int_divisionNumberVer>src.cols)&& y+int_divisionNumberHor<src.rows)
//            {

//                Rect cuadrito2(src.cols-(src.cols%int_divisionNumberVer),y,(src.cols%int_divisionNumberVer),int_divisionNumberHor);
//               // rectangle(src,cuadrito2,cv::Scalar(250,0,0,0),2,8,0);
//                srcCopy=src(cuadrito2);
//                mom.calcularMomentos(srcCopy);
//                data.at<float>(0,int_cont)=mom.media ;
//                data.at<float>(1,int_cont)=mom.segundoMomento;
//                data.at<float>(2,int_cont)=mom.tercerMomento;
//                data.at<float>(3,int_cont)=mom.uniformidad ;
//                data.at<float>(4,int_cont)=mom.entropia;
//                int_cont++;
//            }

//            else if((y+int_divisionNumberHor>src.rows)&& i+int_divisionNumberVer<src.cols)
//            {

//                Rect cuadrito2(i,src.rows-(src.rows%int_divisionNumberHor),int_divisionNumberVer,(src.rows%int_divisionNumberHor));
//                //threshold(src(cuadrito2),src(cuadrito2),0,255,0);
//               // rectangle(src,cuadrito2,cv::Scalar(250,0,0,0),2,8,0);
//                srcCopy=src(cuadrito2);
//                mom.calcularMomentos(srcCopy);
//                data.at<float>(0,int_cont)=mom.media ;
//                data.at<float>(1,int_cont)=mom.segundoMomento;
//                data.at<float>(2,int_cont)=mom.tercerMomento;
//                data.at<float>(3,int_cont)=mom.uniformidad ;
//                data.at<float>(4,int_cont)=mom.entropia;
//                int_cont++;
//            }

//            else
//            {
//                Rect cuadrito2(src.cols-(src.cols%int_divisionNumberVer),src.rows-(src.rows%int_divisionNumberHor),(src.cols%int_divisionNumberVer),(src.rows%int_divisionNumberHor));
//              // threshold(src(cuadrito2),src(cuadrito2),0,255,0);
//              // rectangle(src,cuadrito2,cv::Scalar(250,0,0,0),2,8,0);
//               srcCopy=src(cuadrito2);
//               mom.calcularMomentos(srcCopy);
//               data.at<float>(0,int_cont)=mom.media ;
//               data.at<float>(1,int_cont)=mom.segundoMomento;
//               data.at<float>(2,int_cont)=mom.tercerMomento;
//               data.at<float>(3,int_cont)=mom.uniformidad ;
//               data.at<float>(4,int_cont)=mom.entropia;
//               int_cont++;
//            }

//            y=y+int_divisionNumberHor;
//           // cv::resize(src,src,cv::Size(500,500));

////            imshow("img",src);
////            qDebug()<<"en mat"<<data.at<float>(0,int_cont-1);
////            qDebug()<<"en mat"<<data.at<float>(1,int_cont-1);
////            qDebug()<<"en mat"<<data.at<float>(2,int_cont-1);
////            qDebug()<<"en mat"<<data.at<float>(3,int_cont-1);
////            qDebug()<<"en mat"<<data.at<float>(4,int_cont-1);
////            qDebug()<<"en mat"<<data.at<float>(5,int_cont-1);
////            qDebug()<<mom.media ;
////            qDebug()<<mom.primerMomento;
////            qDebug()<<mom.segundoMomento ;
////            qDebug()<<mom.tercerMomento ;
////            cv::waitKey(0);
//        }
//        i=i+int_divisionNumberVer;


//    }


momentos mom;

cv::Mat M_media;
cv::Mat M_primerMomento;
cv::Mat M_segundoMomento;
cv::Mat M_tercerMomento;
cv::Mat M_uniformidad;
cv::Mat M_entropia;

//Valores          =cv::Mat::zeros((int)((imagen.cols-10)/10),(int)((imagen.rows-10)/10),CV_32F);
M_media          = cv::Mat::zeros((int)((src.cols-10)/10),(int)((src.rows-10)/10),CV_32F);
M_primerMomento  = cv::Mat::zeros((int)((src.cols-10)/10),(int)((src.rows-10)/10),CV_32F);
M_segundoMomento = cv::Mat::zeros((int)((src.cols-10)/10),(int)((src.rows-10)/10),CV_32F);
M_tercerMomento  = cv::Mat::zeros((int)((src.cols-10)/10),(int)((src.rows-10)/10),CV_32F);
M_uniformidad    = cv::Mat::zeros((int)((src.cols-10)/10),(int)((src.rows-10)/10),CV_32F);
M_entropia       = cv::Mat::zeros((int)((src.cols-10)/10),(int)((src.rows-10)/10),CV_32F);

int Wc=20;
int Hc=20;
int control=5;
int cont=0;
cv::Mat data1((int)((src.rows-Hc)/Hc)*(int)((src.cols-Wc)/Wc),5,CV_32F);

for(int n=0;n<(int)((src.cols-Wc)/Wc);n++)
{
    for(int m=0;m<(int)((src.rows-Hc)/Hc);m++)
    {
        //std::cout<<Valores.at<int>(i,j);
        cv::Mat img = src(cv::Rect(n*Wc,m*Hc,Wc,Hc));
        cv::imshow("pedacido",img);
        //cv::waitKey(0);
        control                         = mom.calcularMomentos(img);
        data1.at<float>(0,cont)          = mom.media;
        data1.at<float>(1,cont)       = mom.entropia;
        data1.at<float>(2,cont) = mom.segundoMomento;
        data1.at<float>(3,cont)  = mom.tercerMomento;
        data1.at<float>(4,cont)    = mom.uniformidad;
        cont++;

    }
}




   data=data1;

    return src;
}




cv::Mat CoralesText::Extractpintar(cv::Mat  src0,int verDivisions,int horDivisions, cv::Mat labels)
{

    cv::Mat src;
    src0.copyTo(src);



cv::Scalar class1(100,0,0);
cv::Scalar class2(100,0,100);
cv::Scalar class3(100,100,0);
cv::Scalar class4(10,50,0);
cv::Scalar class5(100,0,50);
cv::Scalar class6(10,10,60);
cv::Scalar class7(60,0,200);
cv::Scalar class8(100,200,0);
cv::Scalar class9(100,10,200);
cv::Scalar class10(0,0,0);
cv::Scalar class11(30,30,30);
cv::Scalar class12(100,200,200);
cv::Scalar class13(100,30,30);
cv::Scalar class14(20,0,20);
cv::Scalar class15(200,70,70);


int Wc=20;
int Hc=20;
int cont=0;
for(int n=0;n<(int)((src.cols-Wc)/Wc);n++)
{
    for(int m=0;m<(int)((src.rows-Hc)/Hc);m++)
    {
        cv::imshow("pedacido",src);
       // cv::waitKey(0);


        if(labels.at<int>(cont,0)==0) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class1,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==1) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class2,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==2) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class3,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==3) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class4,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==4) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class5,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==5) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class6,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==6) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class7,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==7) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class8,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==8) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class9,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==9) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class10,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==10) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class11,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==11) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class12,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==12) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class13,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==13) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class14,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        if(labels.at<int>(cont,0)==14) cv::add(src(cv::Rect(n*Wc,m*Hc,Wc,Hc)),class15,src(cv::Rect(n*Wc,m*Hc,Wc,Hc)));
        cont++;



    }
}




//int i=0;
//int cont=0;

//    while(i-int_divisionNumberVer<src.cols-1)
//    {
//         int y=0;

//        while(y<src.rows-1)
//        {



//            if(i+int_divisionNumberVer<src.cols && y+int_divisionNumberHor<src.rows)
//            {

//                Rect cuadrito(i,y,int_divisionNumberVer,int_divisionNumberHor);
//                rectangle(src,cuadrito,cv::Scalar(250,0,0,0),2,8,0);
//                if(labels.at<int>(cont,0)==0) cv::add(src(cuadrito),class1,src(cuadrito));
//                 if(labels.at<int>(cont,0)==1) cv::add(src(cuadrito),class2,src(cuadrito));
//                if(labels.at<int>(cont,0)==2) cv::add(src(cuadrito),class3,src(cuadrito));
//                if(labels.at<int>(cont,0)==3) cv::add(src(cuadrito),class4,src(cuadrito));
//                if(labels.at<int>(cont,0)==4) cv::add(src(cuadrito),class5,src(cuadrito));
//                if(labels.at<int>(cont,0)==5) cv::add(src(cuadrito),class6,src(cuadrito));
//                 if(labels.at<int>(cont,0)==6) cv::add(src(cuadrito),class7,src(cuadrito));
//                 if(labels.at<int>(cont,0)==7) cv::add(src(cuadrito),class8,src(cuadrito));
//                 if(labels.at<int>(cont,0)==8) cv::add(src(cuadrito),class9,src(cuadrito));
//                 if(labels.at<int>(cont,0)==9) cv::add(src(cuadrito),class10,src(cuadrito));
//                 if(labels.at<int>(cont,0)==10) cv::add(src(cuadrito),class11,src(cuadrito));
//                 if(labels.at<int>(cont,0)==11) cv::add(src(cuadrito),class12,src(cuadrito));
//                 if(labels.at<int>(cont,0)==12) cv::add(src(cuadrito),class13,src(cuadrito));
//                 if(labels.at<int>(cont,0)==13) cv::add(src(cuadrito),class14,src(cuadrito));
//                 if(labels.at<int>(cont,0)==14) cv::add(src(cuadrito),class15,src(cuadrito));
//                //putText(src(cuadrito),convertInt(labels.at<int>(cont,0)), cv::Point(5,src(cuadrito).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);

//                 putText(src(cuadrito),convertInt(cont), cv::Point(5,src(cuadrito).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);
//                 cont++;
//            }
//            else if((i+int_divisionNumberVer>src.cols)&& y+int_divisionNumberHor<src.rows)
//            {

//                Rect cuadrito2(src.cols-(src.cols%int_divisionNumberVer),y,(src.cols%int_divisionNumberVer),int_divisionNumberHor);
//                rectangle(src,cuadrito2,cv::Scalar(250,0,0,0),2,8,0);


//                if(labels.at<int>(cont,0)==0) cv::add(src(cuadrito2),class1,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==1) cv::add(src(cuadrito2),class2,src(cuadrito2));
//                if(labels.at<int>(cont,0)==2) cv::add(src(cuadrito2),class3,src(cuadrito2));
//                if(labels.at<int>(cont,0)==3) cv::add(src(cuadrito2),class4,src(cuadrito2));
//                if(labels.at<int>(cont,0)==4) cv::add(src(cuadrito2),class5,src(cuadrito2));
//                if(labels.at<int>(cont,0)==5) cv::add(src(cuadrito2),class6,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==6) cv::add(src(cuadrito2),class7,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==7) cv::add(src(cuadrito2),class8,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==8) cv::add(src(cuadrito2),class9,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==9) cv::add(src(cuadrito2),class10,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==10) cv::add(src(cuadrito2),class11,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==11) cv::add(src(cuadrito2),class12,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==12) cv::add(src(cuadrito2),class13,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==13) cv::add(src(cuadrito2),class14,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==14) cv::add(src(cuadrito2),class15,src(cuadrito2));
//                //putText(src(cuadrito2),convertInt(labels.at<int>(cont,0)), cv::Point(5,src(cuadrito2).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);
//                 putText(src(cuadrito2),convertInt(cont), cv::Point(5,src(cuadrito2).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);

//                 srcCopy=src(cuadrito2);
//                cont++;
//            }

//            else if((y+int_divisionNumberHor>src.rows)&& i+int_divisionNumberVer<src.cols)
//            {

//                Rect cuadrito2(i,src.rows-(src.rows%int_divisionNumberHor),int_divisionNumberVer,(src.rows%int_divisionNumberHor));
//                //threshold(src(cuadrito2),src(cuadrito2),0,255,0);
//                rectangle(src,cuadrito2,cv::Scalar(250,0,0,0),2,8,0);
//                if(labels.at<int>(cont,0)==0) cv::add(src(cuadrito2),class1,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==1) cv::add(src(cuadrito2),class2,src(cuadrito2));
//                if(labels.at<int>(cont,0)==2) cv::add(src(cuadrito2),class3,src(cuadrito2));
//                if(labels.at<int>(cont,0)==3) cv::add(src(cuadrito2),class4,src(cuadrito2));
//                if(labels.at<int>(cont,0)==4) cv::add(src(cuadrito2),class5,src(cuadrito2));
//                if(labels.at<int>(cont,0)==5) cv::add(src(cuadrito2),class6,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==6) cv::add(src(cuadrito2),class7,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==7) cv::add(src(cuadrito2),class8,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==8) cv::add(src(cuadrito2),class9,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==9) cv::add(src(cuadrito2),class10,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==10) cv::add(src(cuadrito2),class11,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==11) cv::add(src(cuadrito2),class12,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==12) cv::add(src(cuadrito2),class13,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==13) cv::add(src(cuadrito2),class14,src(cuadrito2));
//                 if(labels.at<int>(cont,0)==14) cv::add(src(cuadrito2),class15,src(cuadrito2));
//                // putText(src(cuadrito2),convertInt(labels.at<int>(cont,0)), cv::Point(5,src(cuadrito2).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);
//                 putText(src(cuadrito2),convertInt(cont), cv::Point(5,src(cuadrito2).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);

//                 cont++;
//            }

//            else
//            {
//                Rect cuadrito2(src.cols-(src.cols%int_divisionNumberVer),src.rows-(src.rows%int_divisionNumberHor),(src.cols%int_divisionNumberVer),(src.rows%int_divisionNumberHor));
//              // threshold(src(cuadrito2),src(cuadrito2),0,255,0);
//               rectangle(src,cuadrito2,cv::Scalar(250,0,0,0),2,8,0);
//               if(labels.at<int>(cont,0)==0) cv::add(src(cuadrito2),class1,src(cuadrito2));
//                if(labels.at<int>(cont,0)==1) cv::add(src(cuadrito2),class2,src(cuadrito2));
//               if(labels.at<int>(cont,0)==2) cv::add(src(cuadrito2),class3,src(cuadrito2));
//               if(labels.at<int>(cont,0)==3) cv::add(src(cuadrito2),class4,src(cuadrito2));
//               if(labels.at<int>(cont,0)==4) cv::add(src(cuadrito2),class5,src(cuadrito2));
//               if(labels.at<int>(cont,0)==5) cv::add(src(cuadrito2),class6,src(cuadrito2));
//                if(labels.at<int>(cont,0)==6) cv::add(src(cuadrito2),class7,src(cuadrito2));
//                if(labels.at<int>(cont,0)==7) cv::add(src(cuadrito2),class8,src(cuadrito2));
//                if(labels.at<int>(cont,0)==8) cv::add(src(cuadrito2),class9,src(cuadrito2));
//                if(labels.at<int>(cont,0)==9) cv::add(src(cuadrito2),class10,src(cuadrito2));
//                if(labels.at<int>(cont,0)==10) cv::add(src(cuadrito2),class11,src(cuadrito2));
//                if(labels.at<int>(cont,0)==11) cv::add(src(cuadrito2),class12,src(cuadrito2));
//                if(labels.at<int>(cont,0)==12) cv::add(src(cuadrito2),class13,src(cuadrito2));
//                if(labels.at<int>(cont,0)==13) cv::add(src(cuadrito2),class14,src(cuadrito2));
//                if(labels.at<int>(cont,0)==14) cv::add(src(cuadrito2),class15,src(cuadrito2));
//               //putText(src(cuadrito2),convertInt(labels.at<int>(cont,0)), cv::Point(5,src(cuadrito2).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);

//                putText(src(cuadrito2),convertInt(cont), cv::Point(5,src(cuadrito2).rows/2),cv::FONT_HERSHEY_COMPLEX,2, cv::Scalar(255,0,255),1,8,false);
//                cont++;
//            }

//            y=y+int_divisionNumberHor;
//           // cv::resize(src,src,cv::Size(500,500));

//              imshow("img",src);
////            qDebug()<<data.at<float>(0,int_cont-1);
////            qDebug()<<data.at<float>(1,int_cont-1);
////            qDebug()<<data.at<float>(2,int_cont-1);
////            qDebug()<<data.at<float>(3,int_cont-1);
////            qDebug()<<data.at<float>(4,int_cont-1);
////            qDebug()<<data.at<float>(5,int_cont-1);
//          cv::waitKey(0);
//        }
//        i=i+int_divisionNumberVer;


//    }



    return src;
}

void CoralesText::on_pushButton_released()
{
    src=cv::imread("coral2.tif");
    Extract(src,20,20);

    int clusterCount = 10;
      Mat labels;
      int attempts = 5;
      Mat centers;
      cv::Mat src2;
      for(int i=3459; i<data.rows-1;i++)qDebug()<<i<<"="<<data.at<int>(i,1);
      kmeans(data, clusterCount, labels, TermCriteria(TermCriteria::COUNT|TermCriteria::EPS, 10000, 0.0001), attempts, KMEANS_PP_CENTERS, centers );
     // for(int i=0; i<data.rows-1;i++)qDebug()<<i<<"="<<data.at<int>(i,0);
      //src2= Extractpintar(src,20,20,labels);
      imshow("result Clust",src);
      cv::waitKey(0);






}
