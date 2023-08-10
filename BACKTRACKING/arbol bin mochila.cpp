#include <iostream>
#include <vector>

using namespace std;

struct Node 
{
    int index;
    int totalWeight;
    int totalValue;
    Node* left;
    Node* right;
};

int knapsackBinaryTree(const vector<int>& weights, const vector<int>& values, int capacity) {
    Node* root = new Node{0, 0, 0, nullptr, nullptr};
    int maxTotalValue = 0;
    vector<Node*> nodesToExplore;

    nodesToExplore.push_back(root);

    while (!nodesToExplore.empty()) {
        Node* currentNode = nodesToExplore.back();
        nodesToExplore.pop_back();

        if (currentNode->index < weights.size()) {
            // Explora incluyendo el elemento actual
            if (currentNode->totalWeight + weights[currentNode->index] <= capacity) {
                Node* leftNode = new Node{
                    currentNode->index + 1,
                    currentNode->totalWeight + weights[currentNode->index],
                    currentNode->totalValue + values[currentNode->index],
                    nullptr,
                    nullptr
                };
                nodesToExplore.push_back(leftNode);
                currentNode->left = leftNode;
                maxTotalValue = max(maxTotalValue, leftNode->totalValue);
            }

            // Explora excluyendo el elemento actual
            Node* rightNode = new Node{
                currentNode->index + 1,
                currentNode->totalWeight,
                currentNode->totalValue,
                nullptr,
                nullptr
            };
            nodesToExplore.push_back(rightNode);
            currentNode->right = rightNode;
            maxTotalValue = max(maxTotalValue, rightNode->totalValue);
        }
    }

    return maxTotalValue;
}

int main() {
    int capacity = 50;
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};

    int maxTotalValue = knapsackBinaryTree(weights, values, capacity);

    cout << "El valor máximo que se puede obtener es: " << maxTotalValue << endl;

    return 0;
}
