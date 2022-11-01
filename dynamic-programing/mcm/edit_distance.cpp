// edit distance
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int lcs(string s, string t){
      int n = s.size(), m = t.size();
      int dp[n+1][m+1];
      for(int i =0; i<=n; i++){
          for(int j = 0; j<=m; j++){
              if(i==0 or j==0)dp[i][j] = 0;
              else if(s[i]==t[j])dp[i][j] = 1+dp[i-1][j-1];
              else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
          }
      }
    //   cout<<"come here"<<endl;
      int i = n, j = m;
      int ans = 0;
      vector<int> vs;
      vector<int> vt;
      while(i!=0 and j!=0){
          if(s[i-1]==t[j-1]){
            //   ans+=s[i-1];
              vs.push_back(i);
              vt.push_back(j);
              i--;
              j--;
          }
          else if(dp[i-1][j]>dp[i][j-1]){
              i--;
          }
          else j--;
      }
    //   cout<<"come here"<<endl;
      for(int i = 1; i<vs.size(); i++){
          int s_ch = vs[i-1]-vs[i] - 1;
          int t_ch = vt[i-1]-vt[i] - 1;
          cout<<"s_ch at "<<i<<" is: "<<s_ch<<endl;
          cout<<"t_ch at "<<i<<" is: "<<t_ch<<endl;
          ans+=(min(s_ch,t_ch)+ abs(s_ch-t_ch));
      }
      return ans;
  }
    int editDistance(string s, string t) {
        // Code here
        int ans =  lcs(s,t);
        // return (s.size()-lcsString.size()) + (t.size()-lcsString.size());
        // return 0;
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // int T;
    // cin >> T;
    // while (T--) {
        string s = "ecfbefdcfca", t = "badfcbebbf";
        // cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    // }
    return 0;
}

// } Driver Code Ends