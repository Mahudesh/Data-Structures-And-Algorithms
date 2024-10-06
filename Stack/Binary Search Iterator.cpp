#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class BSTiterator
{
    public:
    stack<TreeNode<int>*>st;
    stack<TreeNode<int>*>prevNode;
    void pushAll(TreeNode<int>* root)
    {
        if(!root)
        return;
        st.push(root);
        pushAll(root->left);
    }
    BSTiterator(TreeNode<int> *root)
    {
        // Write your code here.
        pushAll(root);
    }

    int next()
    {
        // Write your code here.
        TreeNode<int>* node=st.top();
        st.pop();
        int val=node->data;
        prevNode.push(node);
        pushAll(node->right);
        return val;
    }

    bool hasNext()
    {
        // Write your code here.
        if(!st.empty())
        return true;
        return false;
    }

	int prev()
    {
        // Write your code here.
        TreeNode<int>* temp=prevNode.top();
        prevNode.pop();
        return temp->data;
        
    }

    bool hasPrev()
    {
        // Write your code here.
       if(prevNode.empty())
       return false;
       return true;
    }
};
