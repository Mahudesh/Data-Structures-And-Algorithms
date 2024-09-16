#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
bool findPath(TreeNode<int>* root, vector<int>&ans, int x)
{
	if(root==nullptr)
	return false;
	ans.push_back(root->data);
	if(root->data==x)
	return true;
	//If any of the left search or right search returns true then u find a path to node x
	//So return true;
	if((findPath(root->left,ans,x) || findPath(root->right,ans,x)))
	return true;
	//If both left path and right path returns false
	//It means it reaches leaf node without getting x node
	//Then backtrack the last inserted element and return false

	ans.pop_back();
	return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.

	vector<int>ans;
	findPath(root,ans,x);
	return ans;
}
