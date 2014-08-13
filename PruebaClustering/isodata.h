/********************************************************************
Fecha de terminación:
Autor:Alexander Gomez - Sebastian Guzman - German Diez- Jhony Giraldo
Nombre de Clase: Isodata
Descripción:
Parámetros de entrada:
Parámetros de salida:
**********************************************************************/

#ifndef ISODATA_H
#define ISODATA_H
#include <stdio.h>

class Isodata
{
public:
    Isodata();

    //inputs
    std::vector<float> vect_input;//vectores de entrada
    int int_initialClust;//numero inicial de clusters
    int int_desiredClust;//numero aproximado de cluster deseados
    float float_maxStandarDesv;//maxima desviacion estandar por cluster
    float float_mergeDistance;//distancia minima para unir clusters
    int int_minFeaturedVect;//numero minimo de vectores por cluster
    int int_maxMerge;//numero maximo de clusters a ser unidos por iteracion
    int int_maxIteration;//numero max de iteraciones

    //outputs

    int int_numClusters;//numero actual de clusters
    std::vector<int> vect_numVect;//numero de vectores por cluster

    //other
    std::vector<float> vect_clustCenter;


public slots:
    void initialization();
    float kcenter(std::vector<float> vect);

};

#endif // ISODATA_H
