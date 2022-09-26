// Coin Change1
#include<bits/stdc++.h>
using namespace std;

class Solution{
    int recursion(vector<int>&arr, int sum, int n){
        int dp[n+1][sum+1];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=sum; j++){
                dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1]){
                    dp[i][j]+=dp[i][j-arr[i-1]];
                }
            }
        }
        return dp[n][sum];
    }
};




int main(){
    return 0;
}