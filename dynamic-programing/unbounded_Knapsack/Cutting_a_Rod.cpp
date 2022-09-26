// Cutting a Rod
#include<bits/stdc++.h>
using namespace std;

class Solution{
    // Memonization soultion;
    int RodcuttingMemonization(vector<int>&arr, int n, int sum){
        if(sum==0)return 1;
        int res = RodcuttingMemonization(arr, n-1,sum);
        if(sum>=arr[n-1]){
            res+=RodcuttingMemonization(arr, n, sum-arr[n]);
        }
        return res;
    } 

    // Dynamic Programming Solution
    int RodCuttingDP(vector<int>&arr, int n, int sum){
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i = 1; i<=n;i++){
            for(int j=1; j<=sum; j++){
                dp[i][j] = dp[i-1][sum];
                if(j>=arr[n-1]){
                    dp[i][j]+=dp[i][sum-arr[n]];
                }
            }
        }
        return dp[n][sum];
    }
};




int main(){
    vector<int> arr = {};

    return 0;
}