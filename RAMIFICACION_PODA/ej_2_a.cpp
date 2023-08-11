#include <iostream>
#include <vector>

using namespace std;

int M = 61;
int n = 5;
vector<int> W = {1, 11, 21, 23, 33};
vector<int> B = {11, 21, 31, 33, 43};
int maxValue = 0;

void backtrack(int idx, int currentWeight, int currentValue) {
    if (currentWeight > M) return;
    if (idx == n) {
        if (currentValue > maxValue) {
            maxValue = currentValue;
        }
        return;
    }

    backtrack(idx + 1, currentWeight + W[idx], currentValue + B[idx]);

    backtrack(idx + 1, currentWeight, currentValue);
}

int main() {
    backtrack(0, 0, 0);
    cout << "Mayor beneficio con Backtracking: " << maxValue << endl;
    return 0;
}
