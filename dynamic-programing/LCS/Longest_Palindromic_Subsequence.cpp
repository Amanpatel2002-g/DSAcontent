// Longest Palindromic Subsequence

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(string &x, string &y, int &m){
        vector<vector<int>>dp(m+1, vector<int>(m+1,0));
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=m; j++){
                if(x[i-1]==y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][m];
    }
    int longestPalindromeSubseq(string s) {
        string c = s;
        reverse(c.begin(),c.end());
        int m = s.size();
        return lcs(s,c,m);
    }
};

int main(){
    return 0;
}