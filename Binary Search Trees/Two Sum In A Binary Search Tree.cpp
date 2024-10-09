#include <bits/stdc++.h> 
// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};
***************/
class BSTIterator
{
    public:
    bool reverse=false;
    stack<BinaryTreeNode<int>*>st;
    void pushAll(BinaryTreeNode<int>* root)
    {
        if(!root)
        return;
        st.push(root);
        if(reverse==false)
        pushAll(root->left);
        else
        pushAll(root->right);
    }
    BSTIterator(BinaryTreeNode<int>* root,bool reverse)
    {
        this->reverse=reverse;
        pushAll(root);
    }
    int nextOrPrev()
    {
        BinaryTreeNode<int>* temp=st.top();
        st.pop();
        int val=temp->data;
        if(reverse==false)
        pushAll(temp->right);
        else
        pushAll(temp->left);
        return temp->data;
    }
};
bool twoSumInBST(BinaryTreeNode<int>* root, int target)
 {
	//Write your code here
    BSTIterator l(root,false);
    BSTIterator r(root,true);
    int a=l.nextOrPrev();
    int b=r.nextOrPrev();
   while(a<b)
   {
         int sum=a+b;
        if(sum==target)
        return true;
        else if(sum<target)
        a=l.nextOrPrev();
        else
        b=r.nextOrPrev();
   }
   return false;
}
