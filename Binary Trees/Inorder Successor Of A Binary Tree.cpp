/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/
// bool found=false;
void helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>*target,BinaryTreeNode<int>*& ans, bool& found)
{
    if(!root)
    return;

    helper(root->left,target,ans,found);
    // inorder.push_back(root);
    //The Very Next Node
    if(found==true && !ans )
    {
        ans=root;
        return;
    }
    //If We Found The Target Node
    //Then The Very Next Node Printing In Inorder Traversal Will Be It's Successor

    if(root==target)
    {
        found=true;
    }
    helper(root->right,target,ans,found);
}

BinaryTreeNode<int> *inorderSuccesor(BinaryTreeNode<int> *root, BinaryTreeNode<int> *node)
{
    // Write your code here.
    BinaryTreeNode<int>*ans=nullptr;
    bool found=false;
    vector<BinaryTreeNode<int>*>inorder;
    helper(root,node,ans,found);
    // for(int i=0;i<inorder.size()-1;i++)
    // {
    //     if(inorder[i]==node)
    //     {
    //         return inorder[i+1];
    //     }
    // }
    return ans;
    // return nullptr;
    // return find(inorder,node);
    // return inorder[a];
}
