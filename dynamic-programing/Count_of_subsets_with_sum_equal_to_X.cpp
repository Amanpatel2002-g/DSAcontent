// Count of subsets with sum equal to X

#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    static int countSubSetSum(vector<int> &arr, int sum, int index)
    {
        if (sum == 0)
            return 1;
        if (index < 0)
            return 0;
        if (arr[index] <= sum)
            return countSubSetSum(arr, sum - arr[index], index - 1) + countSubSetSum(arr, sum, index - 1);

        return countSubSetSum(arr, sum, index - 1);
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 1};
    int sum = 1;
    int n = arr.size();
    int res = Solution().countSubSetSum(arr, sum, n-1);
    cout<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    cout<<"The answer is: "<<res<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    return 0;
}