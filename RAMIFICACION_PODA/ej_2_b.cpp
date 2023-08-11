#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    int level;
    int weight;
    int value;
};

bool operator<(const Node& a, const Node& b) {
    return static_cast<double>(a.value) / a.weight > static_cast<double>(b.value) / b.weight;
}

int M = 61;
int n = 5;
vector<int> W = {1, 11, 21, 23, 33};
vector<int> B = {11, 21, 31, 33, 43};
int maxValue = 0;

int bound(Node u) {
    int j = u.level + 1;
    int totalWeight = u.weight;
    int boundValue = u.value;

    while (j < n && totalWeight + W[j] <= M) {
        totalWeight += W[j];
        boundValue += B[j];
        j++;
    }

    if (j < n) {
        boundValue += (M - totalWeight) * static_cast<double>(B[j]) / W[j];
    }

    return boundValue;
}

void branchAndBound() {
    priority_queue<Node> pq;

    Node u, v;
    u.level = -1;
    u.value = u.weight = 0;
    pq.push(u);

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        if (u.level == n - 1) continue;

        v.level = u.level + 1;
        v.weight = u.weight + W[v.level];
        v.value = u.value + B[v.level];

        if (v.weight <= M && v.value > maxValue) {
            maxValue = v.value;
        }

        if (bound(v) > maxValue) {
            pq.push(v);
        }

        v.weight = u.weight;
        v.value = u.value;

        if (bound(v) > maxValue) {
            pq.push(v);
        }
    }
}

int main() {
    branchAndBound();
    cout << "Mayor beneficio con Ramificacion y Poda: " << maxValue << endl;
    return 0;
}
