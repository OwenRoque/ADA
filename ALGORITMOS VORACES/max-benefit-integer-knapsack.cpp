#include <iostream>
#include <vector>

struct Container {
    int weight;
};

int maxLoadedWeightRec(int capacity, const std::vector<Container>& containers, int n) {
    // base
    if (n == 0 || capacity == 0) {
        return 0;
    }
    // si es mayor que la capacidad actual, no ingresa
    if (containers[n - 1].weight > capacity) {
        return maxLoadedWeightRec(capacity, containers, n - 1);
    } else {
        // maximo de 2 casos, el que puede ser incluido y el que no
        int included = containers[n - 1].weight + maxLoadedWeightRec(capacity - containers[n - 1].weight, containers, n - 1);
        int excluded = maxLoadedWeightRec(capacity, containers, n - 1);
        return std::max(included, excluded);
    }
}

int maxLoadedWeight(int capacity, const std::vector<Container>& containers) {
    int n = containers.size();
    return maxLoadedWeightRec(capacity, containers, n);
}

int main() {
    int capacity = 50;

    std::vector<Container> containers = { {20}, {13}, {24}, {15}, {28}, {10} };

    int maxWeight = maxLoadedWeight(capacity, containers);

    std::cout << "Máximo peso cargado: " << maxWeight << " toneladas" << std::endl;

    return 0;
}
