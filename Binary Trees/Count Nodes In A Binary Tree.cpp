/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int cnt;
void preOrder(TreeNode* root)
{
    if(!root)
    return;
    cnt++;
    preOrder(root->left);
    preOrder(root->right);
}
    int countNodes(TreeNode* root)
    {
        //BruteForce
        // cnt=0;
        // preOrder(root);
        // return cnt;
        //Optimal
        if(!root)
        return 0;
        //Find Left Subtree Height And Right Subtree Height For Each Node
        //If Both Left And Right Subtree Height Are Same Then Calculate Number Of Nodes
        //By Using The Formula pow(2,leftHeight)-1
        //So No Need To Traverse To Down
        //If Both Left And Right Subtree Height Are Not Same
        //Then Take 1+ Count For That Node And Go For LeftSubTree And Right SubTree Recursively
        //TC: O(log(N)^2)
        

        int leftHeight=findHeightLeft(root);
        int rightHeight=findHeightRight(root);

        if(leftHeight==rightHeight)
        return pow(2,leftHeight)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int findHeightLeft(TreeNode* root)
    {
        int cnt=0;
        while(root)
        {
            cnt++;
            root=root->left;
        }
        return cnt;
    }
    int findHeightRight(TreeNode* root)
    {
        int cnt=0;
        while(root)
        {
            cnt++;
            root=root->right;
        }
        return cnt;
    }
};
