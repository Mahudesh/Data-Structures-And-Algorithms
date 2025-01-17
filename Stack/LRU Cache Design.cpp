#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int key;
    int data;
    Node* prev;
    Node* next;
    Node(int key, int data)
    {
        this->key=key;
        this->data=data;
        prev=next=nullptr;
    }
};


class LRUCache
{
    public:
    unordered_map<int,Node*>Map;
    int capacity;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    LRUCache(int cap)
    {
        this->capacity=cap;
        head->next=tail;
        tail->prev=head;
    }
    void delNode(Node* del)
    {
        Node* delPrev=del->prev;
        Node* delNext=del->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
    }
    void addNode(Node* newNode)
    {
        Node* temp=head->next;
        newNode->next=temp;
        newNode->prev=head;
        head->next=newNode;
        temp->prev=newNode;
    }
    
    
    int get(int key)
    {
        if(Map.find(key)!=Map.end())
        {
            Node* temp=Map[key];
            int val=temp->data;
            Map.erase(key);
            delNode(temp);
            addNode(temp);
            Map[key]=head->next;
            cout<<"The Value Is : ";
            return val;
        }
        return -1;
    }
    void put(int key, int val)
    {
        if(Map.find(key)!=Map.end())
        {
            Node* temp=Map[key];
            Map.erase(key);
            delNode(temp);
        }
        else if(Map.size()==capacity)
        {
            Node* temp=tail->prev;
            Map.erase(temp->key);
            delNode(temp);
        }
        
        Node* newNode=new Node(key,val);
        addNode(newNode);
        Map[key]=head->next;
    }
};

int main()
{
    int cap;
    cout<<"Enter Capacity: ";
    cin>>cap;
    LRUCache ob(cap);
    cout<<"Enter Queries: ";
    int q;
    cin>>q;
    while(q--)
    {
        string com;
        cin>>com;
        if(com=="PUT")
        {
            int val,key;
            cout<<"Enter Key And Value: ";
            cin>>key>>val;
            ob.put(key,val);
        }
        else
        {
            int key;
            cin>>key;
            cout<<"The value is "<<ob.get(key)<<endl;
        }
        
    }
}
