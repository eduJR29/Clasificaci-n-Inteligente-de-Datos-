#ifndef DATASET_H
#define DATASET_H

#include <iostream>
#include <vector>

using namespace std;

class DataSet
{
    public:

        vector<float> x; //vector que almacena los valores de X
        vector<float> y; //vector que almacena los valores de Y
        vector<float> predict; //vector que almacena los valores que haran la prediccion

        DataSet();
};

#endif // DATASET_H
