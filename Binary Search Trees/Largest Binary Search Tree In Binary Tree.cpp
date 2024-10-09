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
