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
Node* p;
Node* q;
Node* createBT(vector<int>&arr)
{
    Node* root=new Node(arr[0]);
    int ind=1;
    queue<Node*>q;
    q.push(root);
    while(!q.empty() && ind<arr.size())
    {
        Node* temp=q.front();
        q.pop();
        if(ind<arr.size() && arr[ind]==-1)
        {
            temp->left=nullptr;
        }
        else
        {
            temp->left=new Node(arr[ind]);
            q.push(temp->left);
        }
        ind++;
        if(ind<arr.size() && arr[ind]==-1)
        {
            temp->right==nullptr;
        }
        else
        {
            temp->right=new Node(arr[ind]);
            q.push(temp->right);
        }
        ind++;
    }
    return root;
}
bool findNodesq(Node* root, int key)
{
    if(root==nullptr)
    return false;
    if(root->data==key)
    {
        q=root;
        return true;
    }
    if((findNodesq(root->left,key)) || (findNodesq(root->right,key)))
    {
        
        return true;
    }
    return false;
}
bool findNodesp(Node* root, int key)
{
    if(root==nullptr)
    return false;
    if(root->data==key)
    {
        p=root;
        return true;
    }
    if((findNodesp(root->left,key)) || (findNodesp(root->right,key)))
    {
        
        return true;
    }
    return false;
}
Node* findLCA(Node* root, Node* p, Node* q)
{
    if(root==nullptr || root==p || root==q)
    {
        return root;
    }
    Node* leftSearch=findLCA(root->left,p,q);
    Node* rightSearch=findLCA(root->right,p,q);
    
    if(leftSearch==nullptr)
    return rightSearch;
    else if(rightSearch==nullptr)
    return leftSearch;
    else
    return root;
}
int main()
{
    vector<int>arr={1,2,3,4,5,6,7};
   Node* root = createBT(arr);
    findNodesp(root,4);
    findNodesq(root,5);
//     cout<<p->data<<" "<<q->data<<" ";
  Node* ans=findLCA(root,p,q);
  cout<<ans->data;
}
