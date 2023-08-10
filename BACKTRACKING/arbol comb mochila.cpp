#include <iostream>
#include <vector>

using namespace std;

void knapsackBacktracking(int index, int currentWeight, int totalValue, int& maxTotalValue,
                          const vector<int>& weights, const vector<int>& values, int capacity) {
    if (index >= weights.size() || currentWeight > capacity) {
        maxTotalValue = max(maxTotalValue, totalValue);
        return;
    }

    // Incluye el elemento actual si el peso no excede la capacidad
    if (currentWeight + weights[index] <= capacity) {
        knapsackBacktracking(index + 1, currentWeight + weights[index],
                             totalValue + values[index], maxTotalValue, weights, values, capacity);
    }

    // Excluye el elemento actual y pasa al siguiente
    knapsackBacktracking(index + 1, currentWeight, totalValue, maxTotalValue, weights, values, capacity);
}

int main() {
    int capacity = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};

    int maxTotalValue = 0;
    knapsackBacktracking(0, 0, 0, maxTotalValue, weights, values, capacity);

    cout << "El valor máximo que se puede obtener es: " << maxTotalValue << endl;
    return 0;
}
