#ifndef DISCRETEMATHS_H
#define DISCRETEMATHS_H

#include <iostream>
#include <vector>
#include <DataSet.h>

using namespace std;

class DiscreteMaths
{
    public:

        DataSet data; //objeto del dataset
        float n; //total de valores
        float nPredict; //total de valores predictivos
        float predicion; //almacena los valores predictivos
        float sumX; //Sumatoria de X
        float sumY; //Sumatoria de Y
        float sumXquad; //X cuadrada
        float sumYquad; //Y cuadrada
        float sumXY; //Sumatoria de XY
        float corr; //coeficiente de correlacion
        float det; //coeficiente de determinacion
        float B1; //Beta 1
        float B0; //Beta 0

        DiscreteMaths();
        void calculo(); //Funcion que realiza los calculos
        void predict(); //Funcion que realiza la prediccion
        void coeficientes(); //Funcion para los coeficientes
};

#endif // DISCRETEMATHS_H
