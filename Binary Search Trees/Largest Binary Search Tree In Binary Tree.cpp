class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bool validate(Node* temp, int minValue, int maxValue)
    {
        if(!temp)
        return true;
        if(temp->data>=maxValue || temp->data<=minValue)
        return false;
        
        return validate(temp->left,minValue,temp->data) && validate(temp->right,temp->data,maxValue);
    }
    void countNodes(Node* root,int& cnt)
    {
        if(!root)
        return;
        countNodes(root->left,cnt);
        cnt=cnt+1;
        countNodes(root->right,cnt);
        
        // return cnt;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	queue<Node*>q;
    	q.push(root);
    	int maxCount=0;
    	while(!q.empty())
    	{
    	    Node* temp=q.front();
    	    q.pop();
    	    int minValue=INT_MIN;
    	    int maxValue=INT_MAX;
    	    if(validate(temp,minValue,maxValue))
    	    {
    	        int c=0;
    	         countNodes(temp,c);
    	        maxCount=max(maxCount,c);
    	    }
    	    if(temp->left)
    	    q.push(temp->left);
    	    if(temp->right)
    	    q.push(temp->right);
    	}
    	return maxCount;
    }
//Optimized Approach By Post Order Traversal With A Custom Class
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
class NodesParameters
{
    public:
    int minValue,maxSize,maxValue;
    NodesParameters(int minValue, int maxValue, int maxSize)
    {
        this->minValue=minValue;
        this->maxValue=maxValue;
        this->maxSize=maxSize;
    }
};
NodesParameters helper(TreeNode* root)
{
    if(!root)
    {
        return NodesParameters(INT_MAX,INT_MIN,0);
    }
    NodesParameters left=helper(root->left);
    NodesParameters right=helper(root->right);
    if(left.maxValue<root->data && root->data<right.minValue)
    {
        return NodesParameters(min(root->data,left.minValue),max(root->data,right.maxValue),1+left.maxSize+right.maxSize);
    }
    return NodesParameters(INT_MIN,INT_MAX,max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode * root)
{
    // Write your code here.
   return helper(root).maxSize;

    
}
