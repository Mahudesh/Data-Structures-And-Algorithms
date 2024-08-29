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
    }
};
Node* insertNode(Node* root, int val)
{
    //If the tree reaches NULL then we can insert the new node here
    if(root==NULL)
    {
        return new Node(val);
    }
    //If the left child is NULL then we can insert the new node here
    if(root->left==NULL)
    {
        root->left=insertNode(root->left,val);
    }
    //If the right child is NULL then we can insert the new node here
    else if(root->right==NULL)
    {
        root->right=insertNode(root->right,val);
    }
    //If both the left and right child are filled then start inserting the new node from left of the tree
    //Literally it shifts the entire root to the left child so that it again checks for NULL to insert the new node
    else
    {
        root->left=insertNode(root->left,val);
    }
    return root;
    
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
        
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}
int main()
{
    int n;
    cin>>n;
    int val;
    Node* root=NULL;
    for(int i=0;i<n;i++)
    {
        cin>>val;
        root = insertNode(root,val);
    }
    levelOrderTraversal(root);
}
