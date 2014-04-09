#include "coral.h"
#include "ui_coral.h"

Coral::Coral(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Coral)
{
    ui->setupUi(this);
}

Coral::~Coral()
{
    delete ui;
}

void Coral::on_pushButton_clicked()
{
    //ABRE VENTANA CARGA ARCHIVO
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Image"), ".",
    tr("Image Files (*.png *.jpg *.jpeg *.bmp *.tif)"));
    source= cv::imread(fileName.toAscii().data());
    cv::Mat srcRgb;
    cvtColor(source,srcRgb,CV_BGR2RGB);

    //MUESTRA IMAGEN EN INTERFAZ
    QImage img= QImage((const unsigned char*)(srcRgb.data),srcRgb.cols,srcRgb.rows,srcRgb.step,QImage::Format_RGB888);//extrae imagen
    ui->label->setPixmap(QPixmap::fromImage(img));//muestra en label el video
}

void Coral::on_pushButton_2_clicked()
{

    Mat imgMean,Hsv,dst,Resultado,ResultadoRgb;//imagenes a utilizar
    source.copyTo(Resultado);
    vector<cv::Mat> canalesHsv;
    std::vector<std::vector<cv::Point> > contours;
    pyrMeanShiftFiltering(source, imgMean, 20, 40, 2);//algoritmo de Mean shift filtering
    cvtColor(imgMean,Hsv,CV_BGR2HSV);//Cambio de espacio de color a HSV
    //cv::resize(Hsv,Hsv,Size(1000,700));
    cv::split(Hsv,canalesHsv);
    threshold(canalesHsv[1],canalesHsv[1],95,255,CV_THRESH_BINARY | CV_THRESH_OTSU);
    Scontour::GetContourMask(canalesHsv[1],dst,contours,50,1);
    for(int i=0;i<contours.size();i++)
    drawContours(Resultado,contours,i,Scalar(255,255,255),1,8);
    cv::cvtColor(Resultado,ResultadoRgb,CV_BGR2RGB);
   // threshold(canalesHsv[2],canalesHsv[2],100,255,0);
//    imshow("Canal Hue",canalesHsv[0]);
//    imshow("Canal Saturation",canalesHsv[1]);
//    imshow("Canal Value",canalesHsv[2]);

    //MUESTRA IMAGEN EN INTERFAZ
    QImage img= QImage((const unsigned char*)(ResultadoRgb.data),ResultadoRgb.cols,ResultadoRgb.rows,ResultadoRgb.step,QImage::Format_RGB888);//extrae imagen
    ui->label_2->setPixmap(QPixmap::fromImage(img));//muestra en label el video
    cv::waitKey(0);


}
