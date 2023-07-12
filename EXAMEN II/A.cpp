#include <iostream>
#include <vector>

using namespace std;

vector<long int> a;

long int FindMedian(vector<long int>& arr, int start, int end) 
{
    int size = end - start + 1;
    int mid = start + (size / 2);

    if (size % 2 == 0) 
    {
        long int median = (arr[mid] + arr[mid - 1]) / 2;
        return median;
    } 
    else 
        return arr[mid];
}

void Merge(vector<long int>& arr, int start, int mid, int end) 
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<long int> left(n1);
    vector<long int> right(n2);

    for (int i = 0; i < n1; i++) {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < n2; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = start;

    while (i < n1 && j < n2) 
    {
        if (left[i] <= right[j]) 
        {
            arr[k] = left[i];
            i++;
        } 
        else 
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) 
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) 
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(vector<long int>& arr, int start, int end) 
{
    if (start < end) 
    {
        int mid = start + (end - start) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid, end);
    }
}

int main() {
    int n;
    a.clear();

    while (cin >> n) {
        if (n == 0)
            break;

        a.push_back(n);
        MergeSort(a, 0, a.size() - 1);
        int median = FindMedian(a, 0, a.size() - 1);
        cout << median << endl;
    }
    return 0;
}

// int result[] = {1, 2, 3, 3, 4, 27, 4};