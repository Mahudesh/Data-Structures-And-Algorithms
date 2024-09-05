/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<stack>
bool isLeafNode(TreeNode<int>* root)
{
    if(root->left==nullptr && root->right==nullptr)
    return true;
    return false;
}
void addLeftLeaf(TreeNode<int>* root, vector<int>&ans)
{
    TreeNode<int>* temp=root->left;
    while(temp!=nullptr)
    {
        //If It Is Not A Leaf Node Insert It
        if(!isLeafNode(temp))
        ans.push_back(temp->data);
        if(temp->left!=nullptr)
        temp=temp->left;
        else
        temp=temp->right;
        
    }
}
void addLeafNodes(TreeNode<int>* root, vector<int>&ans)
{
        //If It Is A Leaf Node Insert It8
    if(isLeafNode(root))
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left)
    addLeafNodes(root->left,ans);
    if(root->right)
    addLeafNodes(root->right,ans);
}
void addRightLeaf(TreeNode<int>* root, vector<int>&ans)
{
    TreeNode<int>* temp=root->right;
    //Since I Am Traversing From Front I Need In Anti-Clockwise Direction
    //So Use Stack For Reverse
    stack<int>st;
    while(temp!=nullptr)
    {
        //If It Is Not A Leaf Node Insert It
        if(!isLeafNode(temp))
        st.push(temp->data);
        if(temp->right!=nullptr)
        temp=temp->right;
        else
        temp=temp->left;
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>ans;
    if(root==nullptr)
    return ans;
    if(!isLeafNode(root))
    ans.push_back(root->data);
    //Logic: Traverse All Left Leaves Except Leaf Nodes
    addLeftLeaf(root,ans);
    //Traverse And Store All Leaf Nodes Only By PreOrder/Inorder Traversal
    addLeafNodes(root,ans);
    //Traverse All Right Leaves Except Leaf Nodes
    addRightLeaf(root,ans);
    return ans;
}
