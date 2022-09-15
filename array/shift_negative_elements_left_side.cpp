#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void shift_negative_left(int arr[], int n){
    int i = 0, j = n-1;
    while(i<j){
        if(arr[i]>0 and arr[j]<0){
            // swaping the element from right to left
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        if(arr[i]<0)i++;
        if(arr[j]>0)j--;
    }
}

int main(){
    int n = 9;
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    shift_negative_left(arr, n);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}