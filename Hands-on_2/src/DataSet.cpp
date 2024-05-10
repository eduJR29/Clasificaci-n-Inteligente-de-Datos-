#include "DataSet.h"
#include "vector"

using namespace std;

DataSet::DataSet() //constructor
{
    //Valores
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.push_back(6);
    x.push_back(7);
    x.push_back(8);
    x.push_back(9);

    y.push_back(2);
    y.push_back(4);
    y.push_back(6);
    y.push_back(8);
    y.push_back(10);
    y.push_back(12);
    y.push_back(14);
    y.push_back(16);
    y.push_back(18);

    predict.push_back(20);
    predict.push_back(55);
    predict.push_back(90);
    predict.push_back(5);
    predict.push_back(15);
}
