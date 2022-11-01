#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;
// x
void modefiedString(string &filename){
    for(auto &s:filename){
        if(s==' '){
            s = '_';
        }
    }
    filename+=".cpp";
}
int main(){
    string fileName;
    getline(cin, fileName);
    string comment = "// "+fileName;
    modefiedString(fileName);
    ofstream Myfile(fileName);
    Myfile<<comment;
    cout<<comment<<" c++ file has been successfully created"<<endl; 
    Myfile.close();
    return 0;
}