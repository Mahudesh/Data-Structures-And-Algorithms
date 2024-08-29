/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void InorderTraversal(TreeNode* root,vector<int>&temp)
{
    if(root==nullptr)
    return;

    InorderTraversal(root->left,temp);
    temp.push_back(root->data);
    InorderTraversal(root->right,temp);
}
void PreorderTraversal(TreeNode* root, vector<int>&temp)
{
    if(root==nullptr)
    return;

    temp.push_back(root->data);
    PreorderTraversal(root->left,temp);
    PreorderTraversal(root->right,temp);
}
void PostorderTraversal(TreeNode* root, vector<int>&temp)
{
    if(root==nullptr)
    return;

    PostorderTraversal(root->left,temp);
    PostorderTraversal(root->right,temp);
    temp.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;
    InorderTraversal(root,temp);
    ans.push_back(temp);
    temp.clear();
    PreorderTraversal(root,temp);
    ans.push_back(temp);
    temp.clear();
    PostorderTraversal(root,temp);
    ans.push_back(temp);
    return ans;
}
