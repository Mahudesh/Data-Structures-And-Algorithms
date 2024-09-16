
class Solution {
  public:
  bool findPaths(Node* root, vector<vector<int>>&ans, vector<int>&temp)
  {
      if(root==nullptr)
      return false;
      
      temp.push_back(root->data);
      
     if(root->left==nullptr && root->right==nullptr)
     {
       ans.push_back(temp);
     }
     else
     {
         findPaths(root->left,ans,temp);
         findPaths(root->right,ans,temp);
     }
      
      temp.pop_back();
      return false;
  }
    vector<vector<int>> Paths(Node* root) 
    {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        findPaths(root,ans,temp);
        return ans;
    }
};
