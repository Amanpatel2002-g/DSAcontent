// Implementation of queue

using namespace std;
#include<iostream>
struct LinkedListNode
{
    int data;
    LinkedListNode *next;
    LinkedListNode()
    {
        this->next = nullptr;
    }
    LinkedListNode(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Queue
{
    LinkedListNode *back;

public:
    LinkedListNode *front;
    Queue()
    {
        front = nullptr;
        back = nullptr;
    }
    void push(int data);
    void pop();
};

void Queue::push(int data)
{
    if (!front)
    {
        front = new LinkedListNode(data);
        back = front;
    }
    else
    {
        back->next = new LinkedListNode(data);
        back = back->next;
    }
}

void Queue::pop()
{
    if(front){
        auto *temp = front->next;
        delete(front);
        front = temp;
    }
    else
    {
        cout<<"No element in the queue"<<endl;
    }
    
}

int main()
{
    Queue q;
    for (int i = 1; i < 10; i++)
    {
        q.push(i);
        q.push(i*2);
        cout<<i<<" "<<2*i<<" ";
    }
    cout<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    if(!q.front)cout<<"front is here"<<endl;
    cout<<q.front->data<<endl;

    return 0;
}
