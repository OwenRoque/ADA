#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    int amount = 11;
    // Valores de los coins
    vector<int> coins = {1, 2, 5};

    int minCoins = coinChange(coins, amount);
    if (minCoins != -1) {
        cout << "La cantidad mínima de monedas necesarias es: " << minCoins << endl;
    } else {
        cout << "No es posible obtener la cantidad exacta con las monedas disponibles." << endl;
    }

    return 0;
}
