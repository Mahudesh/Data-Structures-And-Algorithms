#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        next=nullptr;
    }
};
Node* createLL(Node* head, int val)
{
    if(head==nullptr)
    {
        return new Node(val);
    }
    Node* newNode=new Node(val);
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}
void traversal(Node* head)
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int gcd(int a, int b)
{
    if(b<=0)
    return a;
    return gcd(b,a%b);
}
Node* helper(Node* head)
{
    if(!head || head->next==nullptr)
    return head;
    
    Node* temp1=head;
    Node* temp2=head->next;
    while(temp2!=nullptr)
    {
        int num=gcd(temp1->data,temp2->data);
        Node* newNode=new Node(num);
        
        newNode->next=temp1->next;
        temp1->next=newNode;
        
        temp1=temp2;
        temp2=temp2->next;
    }
    return head;
}
int main()
{
    int n;
    cin>>n;
    int val;
    Node* head=nullptr;
    while(n-- > 0)
    {
        cin>>val;
        head = createLL(head,val);
    }
   head =  helper(head);
    traversal(head);
}
