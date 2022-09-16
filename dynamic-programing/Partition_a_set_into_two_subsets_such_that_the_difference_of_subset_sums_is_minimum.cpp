// Partition a set into two subsets such that the difference of subset sums is minimum

#include <bits/stdc++.h>
using namespace std;

    // void static PartitionRecursive(vector<int> &arr, int finalSum, int currSum, int index, int &min)
    // {

    //     if (index < 0)
    //     {
    //         int halfsum = finalSum - currSum;
    //         if (abs(halfsum- currSum) < min)
    //         {
    //             min = abs(halfsum- currSum);
    //         }
    //         return;
    //     }

    //     if (arr[index] + currSum <= finalSum)
    //     {
    //         PartitionRecursive(arr, finalSum, arr[index] + currSum, index - 1, min);
    //     }
    //     PartitionRecursive(arr, finalSum, currSum, index - 1, min);
    // }
class Solution
{
public:
    int partitionDynamicApproach(vector<int> &arr, int sum, int n)
    {
        bool dp[n + 1][sum + 1] = { false };
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (i == 0 and j == 0)dp[0][0] = true;
                    
                else if (j == 0)dp[i][0] = true;
                    
                else if (i == 0)dp[0][j] = false;
                    
                else if (j >= arr[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        int min = INT_MAX;
        for (int i = 0; i <=(sum / 2); i++)
        {
            cout<<"dp["<<n<<"]"<<"["<<i<<"]: "<<dp[n][i]<<endl;
            if(dp[n][i] and sum-(2*i)<min)min = sum - (2*i);
        }
        return min;
    }
};

int main()
{
    // vector<int> arr = {1, 6, 11, 5};
    vector<int> arr = {1, 2, 7};
    int n = arr.size();
    int sum = accumulate(arr.begin(), arr.end(), 0);
    
    Solution minObj;
    int minAns = minObj.partitionDynamicApproach(arr, sum, n);
    cout<<"-------------------Ans--------------------"<<endl;
    cout << "minimum difference of subset sum is: " << minAns << endl;
    return 0;
}