#include "iostream"
#include "DiscreteMaths.h"

using namespace std;

int main ()
{
    DiscreteMaths r;

    cout<<"Regresion Lineal Simple"<<endl;
    r.calculo();
    cout<<endl;
    cout<<"5 Predicciones: "<<endl;
    r.predict();
    cout<<endl;
    cout<<"Coeficientes: "<<endl;
    r.coeficientes();
    return 0;
}
