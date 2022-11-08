// Implement Stack and Queue using Deque

#include<bits/stdc++.h>
using namespace std;

class QueueUsingDeque{
    deque<int> dq;
    public:
    int front(){
        return dq.front();
    }
    void push(int data){
        dq.push_back(data);
    }
    void pop(){
        dq.pop_front();
    }

};

class StackUsingDeque{
    deque<int> dq;
    public:
    int top(){
        return dq.front();
    }

    void push(int data){
        dq.push_front(data);
    }

    void pop(){
        dq.pop_front();
    }
};

int main(){
    return 0;
}