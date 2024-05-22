#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

class Customer {
public:
    double height;
    double weight;
    std::string shirtSize;

    Customer(double h, double w, const std::string& size)
        : height(h), weight(w), shirtSize(size) {}
};

class KNN {
private:
    int k;
    std::vector<Customer> trainingData;

    static double calculateDistance(const Customer& c1, const Customer& c2) {
        return std::sqrt(std::pow(c1.height - c2.height, 2) + std::pow(c1.weight - c2.weight, 2));
    }

    static bool compareDistances(const std::pair<double, std::string>& a, const std::pair<double, std::string>& b) {
        return a.first < b.first;
    }

    std::string getMajorityLabel(const std::vector<std::pair<double, std::string>>& distances) {
        std::map<std::string, int> labelCount;
        for (int i = 0; i < k; ++i) {
            labelCount[distances[i].second]++;
        }

        return std::max_element(labelCount.begin(), labelCount.end(),
                                [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                                    return a.second < b.second;
                                })->first;
    }

public:
    KNN(int k) : k(k) {}

    void fit(const std::vector<Customer>& data) {
        trainingData = data;
    }

    std::string predict(const Customer& c) {
        std::vector<std::pair<double, std::string>> distances;
        for (const auto& trainCustomer : trainingData) {
            double distance = calculateDistance(c, trainCustomer);
            distances.push_back(std::make_pair(distance, trainCustomer.shirtSize));
        }
        std::sort(distances.begin(), distances.end(), compareDistances);
        return getMajorityLabel(distances);
    }
};

int main() {
    // Datos de entrenamiento
    std::vector<Customer> trainingData = {
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

    KNN knn(5);
    knn.fit(trainingData);

    // Cliente nuevo (Mónica)
    Customer monica(161, 61, "");
    std::string predictedShirtSize = knn.predict(monica);

    std::cout << "La talla de camiseta predicha para Mónica es: " << predictedShirtSize << std::endl;

    return 0;
}


