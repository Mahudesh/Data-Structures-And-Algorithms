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

//Method 2
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
Node* createBT(vector<int>&arr)
{
    Node* root=new Node(arr[0]);
    queue<Node*>q;
    q.push(root);
    int ind=1;
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(ind<arr.size())
        {
            temp->left=new Node(arr[ind++]);
            q.push(temp->left);
        }
        if(ind<arr.size())
        {
            temp->right=new Node(arr[ind++]);
            q.push(temp->right);
        }
        
    }
    return root;
}
void traversal(Node* root)
{
    if(root==nullptr)
    return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=nullptr)
        q.push(temp->left);
        if(temp->right!=nullptr)
        q.push(temp->right);
    }
}
int main()
{
    vector<int>arr={1,3,2,4,5,6,7,8};
    Node* root=nullptr;
   root = createBT(arr);
   traversal(root);
    
}
