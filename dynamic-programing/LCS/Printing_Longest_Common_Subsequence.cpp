// Printing Longest Common Subsequence

// longest common subsequnce code

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    string x, y;
    int n, m;
    int dp[1001][1001];

    Solution(string a, string b)
    {
        x = a;
        y = b;
        m = a.size(), n = b.size();
    }

    void dpApproach()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(i==0 or j==0)dp[i][j] = 0;
                else if(x[i-1]==y[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
    }

    string printLCSubsequence(){
        int i = n-1, j = m-1;
        string ans;
        while(i!=0 and j!=0){
            if(x[i-1]==y[j-1]){
                ans+=x[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>=dp[i][j-1]){
                i = i-1;
            }
            else j = j-1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

};

int main()
{
    return 0;
}
