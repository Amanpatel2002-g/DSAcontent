#include <bits/stdc++.h>
using namespace std;




struct HuffmanNode
{
    int data;
    HuffmanNode *left, *right;
    HuffmanNode(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};


struct HuffmanNodeSort {
    bool operator()(HuffmanNode*node1, HuffmanNode*node2)
    {
        // return "true" if "p1" is ordered
        // before "p2", for example:
        return node1->data<node2->data;
    }
};

class HuffmanCoding
{
    map<char, int> freq;
    map<HuffmanNode *, char> Nodes;

public:
    void getCodes(string mes)
    {
        for (auto i : mes)
        {
            freq[i]++;
        }
        for (auto &[u, v] : freq)
        {
            auto * newNode= new HuffmanNode(u);
            Nodes[newNode] = u;
        }
    }
    HuffmanNode *getHuffmanCode(string mes)
    {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, HuffmanNodeSort> minheap;
        for(auto &[u, v]: Nodes){
            minheap.push(u);
        }
        while(!minheap.empty()){
            auto *node1 = minheap.top();
            minheap.pop();
            
            if(minheap.empty()){
                minheap.push(node1);
                break;
            }
            auto *node2 = minheap.top();
            minheap.pop();
            auto *newNode = new HuffmanNode(node1->data+node2->data);
            minheap.push(newNode);
            
        }
        return minheap.top();
    }
};

int main()
{
    return 0;
}