#include <iostream>
#include <vector>

// Modificacion de busqueda binaria
bool indexEqualsValue(const std::vector<int>& arr, int left, int right, int pos) {
    if (left > right)
        return false;

    int mid = left + (right - left) / 2;

    if (arr[mid] == mid) {
        return (mid == pos);
    }
    else if (arr[mid] < mid) {
        return indexEqualsValue(arr, mid + 1, right, pos);
    }
    else {
        return indexEqualsValue(arr, left, mid - 1, pos);
    }
}

bool indexEqualsValue(const std::vector<int>& arr, int pos) {
    return indexEqualsValue(arr, 0, arr.size() - 1, pos);
}

int main() {
    std::vector<int> arr = { 1, 1, 2, 5, 7, 8, 9 };
    int p = 0;
    std::cout << "Ingresa una posicion: ";
    std::cin >> p;
    bool exists = indexEqualsValue(arr, p);

    if (exists) {
        std::cout << "x[" << p<< "] = " << p << std::endl;
    } else {
        std::cout << "x[" << p<< "] != " << p << std::endl;
    }

    return 0;
}
