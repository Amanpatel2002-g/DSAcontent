// Infix To Postfix Using Stack


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string infinixToPostfix(string str){
        map<char, int> p;
        p['*'] = 2;
        p['/'] = 2;
        p['+'] = 1;
        p['-'] = 1;
        stack<char> st;
        string ans;
        for(int i:str){
            if(i=='-' or i=='*' or i=='+' or i=='/'){
                if(st.empty()){
                    st.push(i);
                }
                else{
                    cout<<st.top()<<endl;
                    while(!st.empty() and p[st.top()]>=p[i]){
                        ans+=st.top();
                        st.pop();
                    }
                    st.push(i);
                }
            }
            else{
                ans+=i;
            }
        }
        while(not st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


int main(){
    string expression = "a+b-c*d+e/f*g";
    // string expression = "a+b*c";
    Solution sol;
    cout<<sol.infinixToPostfix(expression)<<endl;
    return 0;
}