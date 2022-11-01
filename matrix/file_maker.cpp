#include<iostream>
#include<fstream>
using namespace std;
// x
void modefied_String(string &filename){
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
    modefied_String(fileName);
    ofstream Myfile(fileName);
    Myfile<<comment;
    cout<<comment<<" c++ file has been successfully created"<<endl; 
    Myfile.close();
    return 0;
}