#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

/**
 * @brief Compare function for sorting Item Map based on ratio
 */
bool sortRatio(const std::tuple<int, int>& a, const std::tuple<int, int>& b) 
{
    double ratioA = (double)(get<0>(a)) / get<1>(a);
    double ratioB = (double)(get<0>(b)) / get<1>(b);
    return ratioA > ratioB;
}

/**
 * @brief KnapSack Problem: Greedy algorithm
 * @param ksSize Backpack max. size, limit
 * @param items Vector of items <tuple> (benefit, weight)
*/
void knapsack (int& ksSize, vector<tuple<int, int>>& items)
{
    // Sort map by benefit/weight
    sort(items.begin(), items.end(), sortRatio);
    int maxBenefit = 0;
    for (auto& i : items) 
    {
        // cout << get<0>(i) << ", " << get<1>(i) << endl;
        // Add full item if it still fits in the container
        if (get<1>(i) <= ksSize)
        {
            maxBenefit += get<0>(i);
            ksSize -= get<1>(i);
        }
        // Add fractional item to fill in the remaining space
        else
        {
            // fractional benefit
            maxBenefit += get<0>(i) * ((double)ksSize / get<1>(i));
            // Add fractional item
            ksSize -= get<1>(i) * ((double)ksSize / get<1>(i));
            // Last element is fractional, so break loop
            break;
        }
    }
    auto isFull = [](int s) -> const char* { return s == 0 ? "True" : "False"; };
    cout << "Container is Full? " << isFull(ksSize) << endl;
    cout << "Maximum Benefit: "<< maxBenefit << endl;
}

int main()
{
    int W = 15;
    vector<tuple<int, int>> items;
    items.push_back(make_tuple(5, 1));
    items.push_back(make_tuple(10, 3));
    items.push_back(make_tuple(15, 5));
    items.push_back(make_tuple(7, 4));
    items.push_back(make_tuple(8, 1));
    items.push_back(make_tuple(9, 3));
    items.push_back(make_tuple(4, 2));
    
    knapsack(W, items);
    
    return 0;
}

