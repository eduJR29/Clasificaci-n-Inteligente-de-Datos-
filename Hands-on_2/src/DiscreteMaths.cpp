#include "DiscreteMaths.h"
#include "DataSet.h"
#include "vector"
#include "iostream"
#include "cmath"

using namespace std;

DiscreteMaths::DiscreteMaths()
{    //Inicializamos la variables
     n = data.x.size(); //tamaño de x
     nPredict = data.predict.size();
     sumX = 0;
     sumY = 0;
     sumXquad = 0;
     sumXY = 0;
}

void DiscreteMaths::calculo()
{
    for(int i = 0; i<n; i++){
        sumX += data.x[i]; //Sumatoria de X
        sumY += data.y[i]; //Sumatoria de Y
        sumXquad += data.x[i]*data.x[i]; //Sumatoria de X^2
        sumYquad += data.y[i]*data.y[i]; //Sumatoria de Y^2
        sumXY += data.x[i]*data.y[i]; //Sumatoria de XY
    }

    B1 = (n * sumXY - sumX * sumY) / (n * sumXquad - sumX * sumX); //SLR
    B0 = (sumY - B1 * sumX) / n;


    cout<<"a = "<<B0<<endl;
    cout<<"b = "<<B1<<endl;
    cout<<"Y = "<<B0<<" + "<<B1<<" X"<<endl;
}

void DiscreteMaths::predict() //Predicciones
{
    for(int i = 0; i < nPredict; i++){
    predicion = B0 + B1 * data.predict[i];
    cout<<"("<<i+1<<") "<<predicion<<" para X = "<<data.predict[i]<<endl;
    }
}

void DiscreteMaths::coeficientes() //Coeficientes
{
    corr = (n*sumXY-sumX*sumY) / (sqrt((n*sumXquad-sumX*sumX)* (n*sumYquad-sumY*sumY))); //R
    cout<<"Correlacion: "<<corr<<endl;
    det = corr*corr; //R^2
    cout<<"Determinacion: "<<det<<endl;
}

