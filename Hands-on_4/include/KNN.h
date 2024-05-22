#ifndef KNN_H
#define KNN_H

#include "Customer.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class KNN
{
     private:
         int k; //numero de vecinos
         vector<Customer> trainingData; //objeto de datos de entrenamiento


         //Metodos
         double calculateDistance(const Customer& c1, const Customer& c2) const; //distancia euclidiana entre dos clientes c1 y c2.
         static bool compareDistances(const pair<double, string>& a, const pair<double, string>& b); //Se usa para ordenar. Compara dos pares de distancia y talla de camiseta.
         string getMajorityLabel(const vector<pair<double, string>>& distances); // Encuentra la talla de camiseta mayoritaria entre los k vecinos más cercanos.

    public:
        KNN(int k); //constructor
        void fit(const std::vector<Customer>& data); //Guarda los datos
        string predict(const Customer& c); //Predice la talla de camiseta para un nuevo cliente basado en los k vecinos más cercanos.
};

#endif // KNN_H
