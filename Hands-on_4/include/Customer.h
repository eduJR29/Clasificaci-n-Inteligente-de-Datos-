#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Customer
{
    public:
        double height; //altura
        double weight; //peso
        string shirtSize; //talla
        //Customer(); //constructor
        Customer(double h, double w, const std::string& size);
};

#endif // CUSTOMER_H
