// Evaluate Expression to True Boolean Parenthesization

// https://www.youtube.com/watch?v=pGVguAcWX4g&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=38

// #include<bits/stdc++.h>
// using namespace std;
// int dp[1001][1001][2];
// class Solution{
//     int solve(string s, int i, int j, bool isTrue){
//         if(i>j)return 0;
//         else if(i==j){
//             if(isTrue)return s[i]=='T';
//             return s[i]=='F';
//         }
//         else if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
//         int ans = 0;
//         for(int k = i+1; k<j; k=k+2){
//             int lt = solve(s, i, k-1, true);
//             int lf = solve(s, i, k-1, false);
//             int rt = solve(s, k+1, j, true);
//             int rf = solve(s, k+1, j, false);
//             if(s[k]=='&'){
//                 if(isTrue)ans+=(lt*rt);
//                 else ans+=((lf*rf) + (lf*rt) + (lt*rf));
//             }
//             else if(s[k]=='|'){
//                 if(isTrue) ans+= ((lt*rt) + (lt*rf) + (lf*rt));
//                 else ans+= (lf*rf);
//             }
//             else{
//                 if(isTrue) ans+=((lt*rf)+(lf*rt));
//                 else ans+=((lt*lf)+(rf*rt));
//             }
//         }
//         dp[i][j][isTrue] = ans;
//         return ans;
//     }
// };
// class SolutionRecursive{
//     int solve(string s, int i, int j, bool isTrue){
//         if(i>j)return 0;
//         else if(i==j){
//             if(isTrue)return s[i]=='T';
//             return s[i]=='F';
//         }
//         // else if(dp[i][j][isTrue]!=-1)return dp[i][j][isTrue];
//         int ans = 0;
//         for(int k = i+1; k<j; k=k+2){
//             int lt = solve(s, i, k-1, true);
//             int lf = solve(s, i, k-1, false);
//             int rt = solve(s, k+1, j, true);
//             int rf = solve(s, k+1, j, false);
//             if(s[k]=='&'){
//                 if(isTrue)ans+=(lt*rt);
//                 else ans+=((lf*rf) + (lf*rt) + (lt*rf));
//             }
//             else if(s[k]=='|'){
//                 if(isTrue) ans+= ((lt*rt) + (lt*rf) + (lf*rt));
//                 else ans+= (lf*rf);
//             }
//             else{
//                 if(isTrue) ans+=((lt*rf)+(lf*rt));
//                 else ans+=((lt*lf)+(rf*rt));
//             }
//         }
//         // dp[i][j][isTrue] = ans;
//         return ans;
//     }
// };

// int main(){
//     return 0;
// }

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
int dp[1001][1001][2];
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
            // int lt = solve(s, i, k-1, true, dp);
            // int lf = solve(s, i, k-1, false, dp);
            // int rt = solve(s, k+1, j, true, dp);
            // int rf = solve(s, k+1, j, false, dp);
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
                else ans+=((lt*rt)+(rf*lf));
            }
        }
        dp[i][j][isTrue] = ans;
        return ans;
    }
    int countWays(int N, string S){
        memset(dp, -1, sizeof(dp));
        // vector<vector<vector<int>>>dp(100, vector<int>(100, vector<int>(2,-1)));
        return solve(S, 0, N-1, true);
        // return solve(S, 0, N-1, true, dp);
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    // int t;
    // cin>>t;
    // while(t--){
        cout<<"come here"<<endl;
        int N = 35;
        // cin>>N;
        string S = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";

        // cin>>S;
        
        Solution ob;
        cout<<"come here"<<endl;
        cout<<ob.countWays(N, S)<<"\n";
    // }
    return 0;
}
// } Driver Code Ends