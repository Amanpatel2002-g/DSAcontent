// Target Sum

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static int targetSumHelper(vector<int>&arr, int n, int sum){
        int dp[n+1][sum+1] = { 0 };
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=sum; j++){
                if(i==0 and j==0)dp[i][j] = 1;
                else if(i==0)dp[i][j] = 0;
                else if(j==0){
                    if(arr[i-1]==0){
                        dp[i][j] = dp[i-1][j]*2;
                    }
                    else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
                else if(j>=arr[i-1]){
                    dp[i][j]+= dp[i-1][j-arr[i-1]]+  dp[i-1][j];
                }
                else dp[i][j] =   dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    static int TargetSum(vector<int>& arr, int n, int target){
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if((sum+target)%2!=0)return 0;
        int toFindSum = (sum+target)/2;
        return targetSumHelper(arr, n, toFindSum);
    }
};

int main()
{
    vector<int> arr = {0,0,0,0,0,0,0,0,1};
    int n = arr.size(), target = 1;
    cout<<Solution().TargetSum(arr, n, target)<<endl;
    return 0;
}