#include "KNN.h"
#include "Customer.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main(){

    vector<Customer> trainingData = { //Datos de entrenamiento
        Customer(158, 58, "M"),
        Customer(158, 59, "M"),
        Customer(158, 63, "M"),
        Customer(160, 59, "M"),
        Customer(160, 60, "M"),
        Customer(163, 60, "M"),
        Customer(163, 61, "M"),
        Customer(160, 64, "L"),
        Customer(163, 64, "L"),
        Customer(165, 61, "L"),
        Customer(165, 62, "L"),
        Customer(165, 65, "L"),
        Customer(168, 62, "L"),
        Customer(168, 63, "L"),
        Customer(168, 66, "L"),
        Customer(170, 63, "L"),
        Customer(170, 64, "L"),
        Customer(170, 68, "L")
    };

    KNN knn(5); //objeto KNN, 5=k vecinos mas cercanos
    knn.fit(trainingData); //almacenamos dentro del objetO KNN

    // Cliente nuevo (Mónica)
    Customer monica(161, 61, ""); //Objeto Monica(Altura, Peso, talla a predecir)
    string predictedShirtSize = knn.predict(monica); //metodo predict

    cout << "La talla de camiseta predicha para Monica es: " << predictedShirtSize << endl; //Imprime la talla predicha

    return 0;
}
