#include "isodata.h"

Isodata::Isodata()
{
}

/********************************************************************
Fecha de terminación:
Autor:Alexander Gomez - Sebastian Guzman - German Diez- Jhony Giraldo
Nombre del metodo: kcenter
Descripción: calcula el centro de un vector unidimensional
Parámetros de entrada:vector con datos
Parámetros de salida:centro del cluster
**********************************************************************/

float Isodata::kcenter(std::vector<float> vect)
{
    int int_acum;
    for(int i=0;i< vect.size();i++)
    {
        int_acum+=vect[i];
    }

    return int_acum/(vect.size());

}

/********************************************************************
Fecha de terminación:
Autor:Alexander Gomez - Sebastian Guzman - German Diez- Jhony Giraldo
Nombre del metodo: initialization
Descripción:
Parámetros de entrada:
Parámetros de salida:
**********************************************************************/
void Isodata::initialization()
{

    for(int i=0;i<int_initialClust;i++)
    {
        vect_clustCenter[i]=kcenter(vect_input);
    }

}



Isodata::~Isodata()
{
}

