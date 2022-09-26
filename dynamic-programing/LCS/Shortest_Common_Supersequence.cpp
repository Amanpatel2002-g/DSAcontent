// Shortest Common Supersequence

#include<bits/stdc++.h>
using namespace std;

class Solution{
    // In order to find the length of the supersequence we have to use the 
    // Longest common subsequence
public:
    int dpLongestCommonSequence(string &x, string &y, int m, int n){
        int dp[m+1][n+1];
        for(int i = 0; i<=m; i++){
            for(int j = 0; j<=n; j++){
                if(i==0 or j==0)dp[i][j] = 0;
                else if(x[i-1]==y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    int lenghtofShortestCommonSupersequence(string &x, string &y, int m, int n){
        Solution sol;
        int lengthofLCS = sol.dpLongestCommonSequence(x,y,m,n);
        return m+n-lengthofLCS;
    }
};

int main(){
    return 0;
}