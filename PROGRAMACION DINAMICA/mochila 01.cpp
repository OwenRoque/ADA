#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsackDP(int W, const vector<int>& weights, const vector<int>& values) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    // mochila 0/1 usando programación dinámica
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    // Capacidad de la mochila
    int W = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};

    int maxValue = knapsackDP(W, weights, values);
    cout << "El valor máximo que se puede obtener es: " << maxValue << endl;

    return 0;
}
