// Longest increasing subsequence

#include<bits/stdc++.h>
using namespace std;

class Solution{
    // This is the recursion code that we have to solve and now we 
    int LISRecursion(vector<int> &arr, int prev_index, int i){
        if(i==arr.size())return 0;
        int take = 0, nottake = 0;
        if(prev_index==-1 || arr[i]>arr[prev_index]) take =  1 + LISRecursion(arr, i, i+1);
        nottake = LISRecursion(arr, prev_index, i+1);
        return max(take,nottake);
    }
    int LISMemoization(vector<int> &arr, int prev_index, int i, vector<vector<int>>&dp){
        if(i==arr.size())return 0;
        if(dp[i][prev_index+1]!=-1)return dp[i][prev_index+1];
        int take = 0, nottake = 0;
        if(prev_index==(-1) || arr[i]>arr[prev_index])take = 1 + LISMemoization(arr, i, i+1, dp);
        nottake =  LISMemoization(arr, prev_index, i, dp);
        return dp[i][prev_index+1] = max(take, nottake);  
    }
    int LISDynamicprogramming(vector<int> &arr){
        int n = arr.size();
        int dp[n][n+1] = { 0 };

        for(int i = n; i>=0; i--){
            for(int j = i-1; j>=-1; j++){

            }
        }
    }
};

int main(){
    vector<vector<int>>
    return 0;
}