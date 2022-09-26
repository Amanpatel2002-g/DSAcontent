// Evaluate Expression to True Boolean Parenthesization

// https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38

#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001][2];
class Solution{
    int solve(string s, int i, int j, bool isTrue){
        if(i>j)return 0;
        else if(i==j){
            if(isTrue)return s[i]=='T';
            return s[i]=='F';
        }
        else if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
        int ans = 0;
        for(int k = i+1; k<j; k=k+2){
            int lt = solve(s, i, k-1, true);
            int lf = solve(s, i, k-1, false);
            int rt = solve(s, k+1, j, true);
            int rf = solve(s, k+1, j, false);
            if(s[k]=='&'){
                if(isTrue)ans+=(lt*rt);
                else ans+=((lf*rf) + (lf*rt) + (lt*rf));
            }
            else if(s[k]=='|'){
                if(isTrue) ans+= ((lt*rt) + (lt*rf) + (lf*rt));
                else ans+= (lf*rf);
            }
            else{
                if(isTrue) ans+=((lt*rf)+(lf*rt));
                else ans+=((lt*lf)+(rf*rt));
            }
        }
        dp[i][j][isTrue] = ans;
        return ans;
    }
};


int main(){
    return 0;
}