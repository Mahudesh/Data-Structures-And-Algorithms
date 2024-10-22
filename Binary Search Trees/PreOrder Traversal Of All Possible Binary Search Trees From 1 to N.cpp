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
        left=right=nullptr;
    }
};
vector<Node*> generateBST(int start, int end)
{
    vector<Node*>trees;
    if(start>end)
    {
        trees.push_back(nullptr);
        return trees;
    }
    for(int i=start;i<=end;i++)
    {
        vector<Node*>left=generateBST(start,i-1);
        vector<Node*>right=generateBST(i+1,end);
        
        for(Node* l : left)
        {
            for(Node* r : right)
            {
                Node* root=new Node(i);
                root->left=l;
                root->right=r;
                trees.push_back(root);
            }
        }
    }
    return trees;
}
void preOrderTraversal(Node* head)
{
    if(!head)
    return;
    
    cout<<head->data<<" ";
    
    preOrderTraversal(head->left);
    preOrderTraversal(head->right);
}
int main()
{
    int n;
    cin>>n;
   vector<Node*>ans= generateBST(1,n);
 
 cout<<"Preorder traversals of all constructed BSTs are"<<endl;
   for(int i=0;i<ans.size();i++)
   {
       preOrderTraversal(ans[i]);
       cout<<endl;
   }
}
