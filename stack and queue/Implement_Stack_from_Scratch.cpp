// Implement Stack from Scratch

// we are going to implement stack with the help of linked list
// implementing it would be really very easy
#include<iostream>
using namespace std;
struct LinkedList
{
    int data;
    LinkedList *next;
    LinkedList()
    {
        next = nullptr;
    }
    LinkedList(int d)
    {
        data = d;
    }
    LinkedList(int d, LinkedList *ptr)
    {
        data = d;
        next = ptr;
    }
};

struct CustomStack
{
public:
    LinkedList *node = nullptr;
    // int * top = &(node->data);
    bool empty(){
        if(node==nullptr)return true;
        return false;
    }

    void push(int element)
    {
        LinkedList *newtop = new LinkedList(element, node);
        node = newtop;

    }

    void pop()
    {
        if(!node){
            cout<<"There's nothing in the stack"<<endl;
            return;
        }
        else
        {
            auto nextptr = node->next;
            delete node;
            node = nextptr;
        }
    }
};

int main()
{
    CustomStack st;
    st.push(5);
    st.push(15);
    st.push(25);
    // st.pop();
    // cout<<st.node->data<<endl;
    // cout<<*st.top<<endl;
    return 0;
}

