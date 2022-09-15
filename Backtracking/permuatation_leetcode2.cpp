#include<bits/stdc++.h>
using namespace std;
void printVector(vector<vector<int>> &ans){
    for(int i = 0; i<ans.size(); i++){
        for (int j = 0; j < 7; j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
// void recursion(vector<int> &a, int index, int n, vector<vector<int> >&ans){
//         if(index==n){
//             ans.push_back(a);
//             return;
//         }
//         for(int i = index; i<n; i++){
//             if(i>index and a[i]==a[index])continue;
//             if(i>index and a[i]==a[i-1])continue;
//             swap(a[i], a[index]);
//             recursion(a, index+1, n,ans);
//             swap(a[i], a[index]);
//         }
        
//     }
// vector<vector<int> > permuteUnique(vector<int> &num) {
//     sort(num.begin(), num.end());
//     vector<vector<int> >res;
//     recursion(num, 0, num.size(), res);
//     return res;
// }

      void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
int main(){
    // set<int> s = {-1,2,0,-1,1,0,1};
    // vector<int> v(s.begin(), s.end());
    // for (auto &&i : v)
    // {
    //     cout<<i<<endl;
    // }
    int x = stoi("456");
    cout<<x<<endl;
    return 0;
}