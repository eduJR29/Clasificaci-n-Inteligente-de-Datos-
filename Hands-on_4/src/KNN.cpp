#include "KNN.h"

#include "Customer.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;


KNN::KNN(int k) : k(k) {} //constrcutor

void KNN::fit(const vector<Customer>& data) { //Guarda los datos
        trainingData = data;
}

double KNN::calculateDistance(const Customer& c1, const Customer& c2) const {
    return sqrt(pow(c1.height - c2.height, 2) + pow(c1.weight - c2.weight, 2)); //Calcula la distancia euclidiana entre dos clientes c1 y c2 basándose en sus alturas y pesos
}

bool KNN::compareDistances(const pair<double, string>& a, const pair<double, string>& b){ //Compara dos pares de distancia y talla de camiseta,
      return a.first < b.first;                                                     //devolviendo verdadero si la distancia del primer par es menor que la del segundo.
}
string KNN::getMajorityLabel(const vector<pair<double, string>>& distances) {
        map<string, int> labelCount; //Se crea un mapa que tiene como clave una cadena que
                                     //representa la talla de la camiseta y como valor un entero que cuenta cuántas veces aparece cada talla entre los k vecinos más cercanos.
        for (int i = 0; i < k; ++i) { //Se itera sobre los primeros k elementos del vector distances.
            labelCount[distances[i].second]++;
        }

        return max_element(labelCount.begin(), labelCount.end(), //encuentra el elemento con el valor máximo
                                [](const pair<string, int>& a, const pair<string, int>& b) { //comparar los valores en el mapa, que devuelve true si el segundo elemento del par a
                                    return a.second < b.second;                              //es menor que el segundo elemento del par b. Retorna un iterador al par con el mayor valor
                                })->first; //obtiene la etiqueta de la camiseta del par con el mayor conteo.
}

string KNN::predict(const Customer& c) { //Predice la talla de camiseta para un nuevo cliente basado en los k vecinos más cercanos.
        vector<pair<double, string>> distances; //vector de pares
        for (const auto& trainCustomer : trainingData) { //Se calcula la distancia euclidiana entre el nuevo cliente c y el cliente de entrenamiento,
            double distance = calculateDistance(c, trainCustomer);
            distances.push_back(make_pair(distance, trainCustomer.shirtSize)); //se agrega un par que contiene esta distancia y la talla de camiseta del cliente de entrenamiento al vector
        }
        sort(distances.begin(), distances.end(), compareDistances); //Se ordena el vector distances en orden ascendente basado en la distancia
        return getMajorityLabel(distances); //Se llama a la función con el vector ya ordenado.
}
