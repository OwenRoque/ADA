#include <iostream>
#include <vector>

struct Container {
    int weight;
};

int maxLoadedContainersRec(int capacity, const std::vector<Container>& containers, int n) {
    // base
    if (n == 0 || capacity == 0) {
        return 0;
    }
    // Si es mayor que la capacidad actual
    if (containers[n - 1].weight > capacity) {
        return maxLoadedContainersRec(capacity, containers, n - 1);
    } else {
        int included = 1 + maxLoadedContainersRec(capacity - containers[n - 1].weight, containers, n - 1);
        int excluded = maxLoadedContainersRec(capacity, containers, n - 1);
        return std::max(included, excluded);
    }
}

int maxLoadedContainers(int capacity, const std::vector<Container>& containers) {
    int n = containers.size();
    return maxLoadedContainersRec(capacity, containers, n);
}

int main() {
    int capacity = 10;

    std::vector<Container> containers = {
        {2},
        {3},
        {4},
        {5}
    };

    int maxContainers = maxLoadedContainers(capacity, containers);

    std::cout << "Máximo número de contenedores cargados: " << maxContainers << std::endl;

    return 0;
}
