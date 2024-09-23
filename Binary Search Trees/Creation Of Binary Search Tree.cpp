#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int data)
    {
        this->data=data;
        left=nullptr;
        right=nullptr;
    }
};
Node* createBST(Node* root,int val)
{
    if(val==-1)
    return nullptr;
    
    if(!root)
    {
        return new Node(val);
    }
    
    if(val<root->data)
    {
        root->left=createBST(root->left,val);
    }
    else if(val>root->data)
    {
        root->right=createBST(root->right,val);
    }
    return root;
}
void traversal(Node* root)
{
    if(!root)
    return;
    
    traversal(root->left);
    cout<<root->data<<" ";
    traversal(root->right);
}
int main()
{
    int val;
    cin>>val;
    Node* root=nullptr;
    if(val!=-1)
    {
        root=createBST(root,val);
    }
    do
    {
        cin>>val;
        if(val==-1)
        break;
        createBST(root,val);
    }while(1);
    traversal(root);
}
