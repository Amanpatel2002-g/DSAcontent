// Maximum subsequence sum such that no three are consecutive

#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&v, int i, bool prevtaken){
    // base case
    if(i>=v.size())return 0;
    int sum = 0;
    if(prevtaken){
        sum = max(v[i] + f(v, i+2, false), f(v, i+1, false));
    }
    else sum = f(v, i+1, true);
    return sum;
}

vector<int> maximum(vector<int>&v, bool prevtaken){
    int n = v.size();
    vector<int> arr(n, -1);
    
}

int main(){
    return 0;
}