#include "Customer.h"

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

Customer::Customer(double h, double w, const string& size) //Constructor
        : height(h), weight(w), shirtSize(size) {}
