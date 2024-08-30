#include<bits/stdc++.h>
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
vector<int> preOrder(TreeNode<int> * root)
{
    // Write your code here.
    //Iterative Traversal

    stack<TreeNode<int>*>st;
    st.push(root);
    vector<int>preorder;
    while(!st.empty())
    {
        TreeNode<int>* temp=st.top();
        st.pop();
        preorder.push_back(temp->data);
        //Since it is a stack LIFO first traverse the right
        if(temp->right!=nullptr)
        {
            st.push(temp->right);
        }
        //Then next traverse the left
        if(temp->left!=nullptr)
        {
            st.push(temp->left);
        }
    }
    return preorder;
}
