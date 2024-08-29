#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this->data=data;
        left=right=NULL;
    }
};
void insertNode(Node* &root, int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        
        //Check if the left child is empty
        if(temp->left==NULL)
        {
            temp->left=new Node(val);
            return;
        }
        else
        {
            q.push(temp->left);
        }
        //Check if the right child is empty
        if(temp->right==NULL)
        {
            temp->right=new Node(val);
            return;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
void levelOrderTraversal(Node* root)
{
    if(root==NULL)
    {
        cout<<"No tree exists";
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        
        cout<<temp->data<<" ";
        if(temp->left!=NULL)
        {
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            q.push(temp->right);
        }
    }
}
int main()
{
    Node* root=NULL;
    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        insertNode(root,val);
    }
    levelOrderTraversal(root);
}
