#include <bits/stdc++.h>
using namespace std;

bool partitionKSubsets(vector<int> &nums, int k, int currSum, int Sum, int index)
{
    if()
}
bool canPartitionKSubsets(vector<int> &nums, int k)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)return false;
    return partitionKSubsets(nums, k, 0, sum/k, 0);
}

int main()
{
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    sort(nums.begin(), nums.end(), greater<int>());
    cout << canPartitionKSubsets(nums, 4) << endl;
    return 0;
}