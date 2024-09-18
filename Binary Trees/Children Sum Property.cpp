#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) 
{
    // Write your code here.
    if(!root)
    return;
    //While Going Down Check The Left Child And Right Child Values
    int sum=0;
    //Try To Assign The Largest Value To Child Or Root(Current Node) While Going Down
    if(root->left)
    {
        sum=sum+root->left->data;
    }
    if(root->right)
    {
        sum=sum+root->right->data;
    }
    //If Both Sum Is Larger Than Root(Current Node) Then It Is The Larger So Assign It
    if(sum>=root->data)
    {
        root->data=sum;
    }
    //If Both Sum Is Lesser Then Assign The RootNode(Current Node) Value Because It Is The Greater
    else
    {
        if(root->left)
        {
            root->left->data=root->data;
        }
        if(root->right)
        {
            root->right->data=root->data;
        }
    }
    //Traverse LeftWise And RightWise
    changeTree(root->left);
    changeTree(root->right);
    //While Going Up Sum Up The Both Left And Right Child Values
    int tot=0;
    if(root->left)
    {
        tot=tot+root->left->data;
    }
    if(root->right)
    {
        tot=tot+root->right->data;
    }
    //Check If It Is Not A Leaf Node Since The Value Of A Leafnode Should Not Be Changed
    if((root->left!=nullptr) || (root->right!=nullptr))
    root->data=tot;
}  
