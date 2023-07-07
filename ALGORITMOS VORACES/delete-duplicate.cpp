#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> removeDuplicates(vector<int> nums)
{
    sort(nums.begin(), nums.end());     // nlogn
    vector<int> result;
    int i = 0, n = nums.size();
    while (i < n) {                     // n
        result.push_back(nums[i]);
        while (i < n - 1 && nums[i] == nums[i + 1])
            i = i + 1;
        i = i + 1;
    }
    return result;
}

int main() {
    vector<int> nums = {4, 2, 4, 6, 8, 7, 3, 2, 1, 8};

    cout << "Vector original: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    vector<int> result = removeDuplicates(nums);

    cout << "Vector sin duplicados: ";
    for (int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
