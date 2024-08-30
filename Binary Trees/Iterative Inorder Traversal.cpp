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
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    stack<TreeNode*>st;
    // st.push(root);
    while(true)
    {
        if(root!=nullptr)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            if(st.empty())
            break;
            TreeNode* temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            root=temp->right;
        }
    }
    return ans;
}
