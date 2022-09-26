// Minimum number of deletions and insertions to transform one string into another
// This is also one of the type of the LCS (Longest common substring)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static int lcs(string &x, string &y, int m, int n){
        int dp[m+1][n+1];
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n;j++){
                if(i==0 or j==0)dp[0][0] = 0;
                else if(x[m-1]==y[n-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

};


int main()
{   string x, y;
    int len = Solution().lcs(x, y, x.size(), y.size());
    cout<<"The number of deletions equal to: "<<x.size()-len;
    cout<<"The number of insertions equal to: "<<y.size() - len;
    return 0;
}