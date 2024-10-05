// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int mini=INT_MAX;
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
Node* createBST(Node* root, int val)
{
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
    cout<<(char)root->data<<" ";
    traversal(root->right);
}
int findMinimum(Node* root)
{
    if(root->left==nullptr)
    {
        return root->data;
    }
   return findMinimum(root->left);
}
Node* findLastRightChild(Node* root)
{
    if(root->right==nullptr)
    return root;
    return findLastRightChild(root->right);
}
Node* helper(Node* root)
{
    if(!root->left)
    return root->right;
    if(!root->right)
    return root->left;
    
    Node* rightNode=root->right;
    Node* lastRightChild=findLastRightChild(root->left);
    lastRightChild->right=rightNode;
    return root->left;
}
Node* deleteMinimumElement(Node* root, int miniElement)
{
    if(!root)
    return nullptr;
    Node* temp=root;
    queue<Node*>q;
    q.push(temp);
    while(temp)
    {
        if(miniElement<temp->data)
        {
          if(temp->left!=nullptr && temp->left->data==miniElement)
          {
              temp->left=helper(temp->left);
              break;
          }
          else
          {
              temp=temp->left;
          }
            
        }
        else
        {
            if(temp->right!=nullptr && temp->right->data==miniElement)
            {
                temp->right=helper(temp->right);
                break;
            }
            else
            {
                temp=temp->right;
            }
        }
    }
    return root;
    
}
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        char ch;
        cin>>ch;
        arr[i]=(int)ch;
    }
    Node* root=nullptr;
 
    for(int i=0;i<n;i++)
    {
      root = createBST(root,arr[i]);
    }
   int miniElement =  findMinimum(root);
   root = deleteMinimumElement(root,miniElement);
   cout<<"Inorder traversal after deleting the minimum element:"<<endl;
    traversal(root);
}
