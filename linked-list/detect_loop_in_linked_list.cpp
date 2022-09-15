#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int data;
    ListNode* next;
    // making the constructors of the ListNode
    ListNode(){
        data = 0;
        next = NULL;
    }
    ListNode(int x){
        data = x;
        next = NULL;
    }
    ListNode(int x, ListNode*node){
        data =x;
        next = node;
    }
};


// This code is for the loop detection in the linked list
ListNode* floydDetectLoop(ListNode*head){
    if(head==NULL){
        cout<<"Entered Node is null"<<endl;
        return NULL;
    }

    ListNode*fast = head;
    ListNode*slow = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(head==slow){
            cout<<"LOOP IS FOUND"<<endl;
            return slow;
        }
    }
    
    cout<<"LOOP IS NOT FOUND"<<endl;
    return NULL;
}

// finding the starting point of the linked list
// we are using the floyed algorithm for getting the starting point of the linked listNode

ListNode* findstartNode(ListNode*head){
    if(head==NULL){
        cout<<"!sorry head is null"<<endl;
        return NULL;
    }
    ListNode * intersection = floydDetectLoop(head);
    ListNode * slow = head; 
    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

void removeloop(ListNode*head){
    if(head==NULL)
        cout<<"!sorry head is null"<<endl;
        return;
    ListNode *startingpoint = findstartNode(head);
    ListNode *temp = startingpoint;
    while(temp->next!=startingpoint)
        temp = temp->next;
    temp->next = NULL;

}
int main(){
    return 0;
}