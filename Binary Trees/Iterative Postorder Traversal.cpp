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
vector<int> postorderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    TreeNode* node=root;
    st1.push(node);
    while(true)
    {
        if(st1.empty())
        break;
        //Push the top of st1 node into st2
        st2.push(st1.top());
        st1.pop();
        //Check for values of the node at st2.top()
        node=st2.top();
        if(node->left!=nullptr)
        st1.push(node->left);
        if(node->right!=nullptr)
        st1.push(node->right);

    }
    vector<int>ans;
    while(!st2.empty())
    {
        node=st2.top();
        ans.push_back(node->data);
        st2.pop();
    }
    return ans;
}
