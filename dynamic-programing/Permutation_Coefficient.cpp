// Permutation Coefficient

#include<bits/stdc++.h>
using namespace std;




int main(){
    vector<int> v = {1, 2,3,4,5,6};
    // cout<<begin(v+1)<<endl;
    cout<<&*v.begin()<<endl;
    auto x = v.begin()+1;
    return 0;
}