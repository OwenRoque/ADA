#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Variación de QuickSort
int kthSmallest(vector<int>& arr, int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int partitionIndex = partition(arr, low, high);

        if (partitionIndex - low == k - 1) {
            return arr[partitionIndex];
        } else if (partitionIndex - low > k - 1) {
            return kthSmallest(arr, low, partitionIndex - 1, k);
        } else {
            return kthSmallest(arr, partitionIndex + 1, high, k - partitionIndex + low - 1);
        }
    }

    return -1; // Si k está fuera de rango, devuelve un valor inválido
}

int main() {
    vector<int> arr = {4, 2, 6, 7, 3, 1, 8};
    int k = 3; // Buscar el tercer menor elemento

    int kthSmallestElement = kthSmallest(arr, 0, arr.size() - 1, k);
    
    if (kthSmallestElement != -1) {
        cout << "El " << k << "-ésimo menor elemento es: " << kthSmallestElement << endl;
    } else {
        cout << "El valor de k está fuera de rango." << endl;
    }

    return 0;
}
