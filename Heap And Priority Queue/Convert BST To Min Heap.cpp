#include <bits/stdc++.h> 
/*************************************************************
    
    Following is the Binary Tree node structure:

	class BinaryTreeNode {
		
	public :
		int data;
		BinaryTreeNode* left;
		BinaryTreeNode* right;

		BinaryTreeNode(int data) {
		this -> left = NULL;
		this -> right = NULL;
		this -> data = data;
		}
	};

*************************************************************/
void inorder(BinaryTreeNode* root, vector<int>& inord)
{
	if(!root)
	return;

	inorder(root->left,inord);
	inord.push_back(root->data);
	inorder(root->right,inord);
}
void preorder(BinaryTreeNode* root, vector<int>& inord, int& ind)
{
	if(!root)
	return;

	root->data=inord[ind];
	ind++;
	preorder(root->left,inord,ind);
	preorder(root->right,inord,ind);
}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int>inord;
	inorder(root,inord);
	int ind=0;
	preorder(root,inord,ind);
	return root;
}
