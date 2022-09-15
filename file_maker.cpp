#include<iostream>
#include<fstream>
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
    string fileName = "Partition a set into two subsets such that the difference of subset sums is minimum";
    string comment = "// "+fileName;
    modefiedString(fileName);
    ofstream Myfile(fileName);
    Myfile<<comment;
    cout<<comment<<" c++ file has been successfully created"<<endl; 
    Myfile.close();
    return 0;
}