#include<bits/stdc++.h>
using namespace std;

class UnBoundedKnapSack{

    static int recursiveApproach(vector<int>&arr, int n, int sum){
        if(sum==0) return 1;
        if(n<0)return 0;
        int res = recursiveApproach(arr, n-1, sum);
        if(sum-arr[n]>=0){
            res+=recursiveApproach(arr, n, sum-arr[n]);
            
        }
        return res;
    }


    static int dpApproach(vector<int>&arr, int n , int sum){
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if(j>=arr[n-1]){
                    dp[i][j]+=dp[i][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};


int main(){
    vector<int>arr = {};
    return 0;
}