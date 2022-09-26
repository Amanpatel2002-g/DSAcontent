// Longest Common Subsequence

#include<bits/stdc++.h>
using namespace std;


class Solution{
    int recursive(string x, string y, int n, int m){
        // base condtion
        if(n==0 or m==0)return 0;

        // choice diagram
        if(x[n-1]==y[n-1]){
            return 1 + recursive(x,y, n-1, m-1);
        }
        return max(recursive(x,y,n-1,m),recursive(x,y,n,m-1));
    }
    int dpcode(string x, string y, int n, int m){
        int dp[n+1][m+1];
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i==0 or j==0){
                    dp[i][j] = 0;
                }
                else{
                    if(x[i-1]==y[j-1]){
                        dp[i][j] = 1+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
        return  dp[n][m];
    }
};


int main(){
    
    return 0;
}