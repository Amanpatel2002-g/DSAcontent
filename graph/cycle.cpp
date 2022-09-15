// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
char D[] = {'U', 'D', 'L', 'R'};
char opp[] = {'D', 'U', 'R', 'L'};
int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, -1, 1};
vector<string> ans;
class Solution{
    public:

    
    void solve( int x, int y, vector<vector<int>> m, int n, char last, string path){
        if(x==n or y==n){
            return;
        }
        else if(m[x][y]==0)return;
        else if(x==n-1 and y==n-1){
            ans.push_back(path);
        }
        else{
            for(int i = 0; i<4; i++){
                if(D[i]!=last){
                    solve(x+X[i],y +Y[i], m, n, opp[i],path+D[i]);
                }
            }
        }
        return ;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        solve(0, 0, m, n, 'N', "");
        // sort(ans.begin(), ans.end());
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends