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
bool preOrderTraversal(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    if(root1==nullptr && root2==nullptr)
    return true;
    if(root1==nullptr || root2==nullptr)
    return false;
    if(root1->data!=root2->data)
    return false;
   return preOrderTraversal(root1->left,root2->left)&& preOrderTraversal(root1->right,root2->right);
}

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
 {
    // Write your code here. 	 
    return preOrderTraversal(root1,root2);
}
