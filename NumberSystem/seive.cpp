#include<bits/stdc++.h>
using namespace std;

void seive(int n){
    int prime[100] = {0};
    for(int i =2; i<=n; i++){
        for(int j = i*i; j<n; j+=i){
            prime[j] = 1;
        }
    }
    for(int i  = 2; i<=n; i++){
        if(prime[i]==0)cout<<i<<" ";
    }

    cout<<endl;
}

int primeFactors(int n){
    int spf[100] = {0};
    for(int i =2;i<=n; i++){
        spf[i] = i;
    }
    for(int i=2; i<=n; i++){
        if(spf[i]==i){
            for(int j=i*i; j<=n; j++){
                spf[j] = i;
            }
        }
    }
    while(n!=1){
        cout<<spf[n]<<" ";
        n = n/spf[n];
    }
}


int main(){
    return 0;
}