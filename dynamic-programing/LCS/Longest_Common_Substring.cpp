// Longest Common Substring

#include<bits/stdc++.h>
using namespace std;

class Solution{
    int recursion(string &x, string &y, int n, int m){
        int dp[n+1][m+1];
        int maxstring = -1;
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i==0 or j==0)dp[i][j] = 0;
                else if(x[i-1]==y[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 0;
                }
                maxstring = max(maxstring, dp[i][j]);
            }
        }
        return maxstring;
        
    }
};


int main(){
    return 0;
}