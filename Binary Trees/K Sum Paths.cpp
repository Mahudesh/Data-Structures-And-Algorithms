Solution {
  public:
  void helper(unordered_map<int,int>& Map, int sum, int& count, int k, Node* root)
  {
      if(!root)
      return;
      
      sum=sum+root->data;
      int rem=sum-k;
      if(Map.find(rem)!=Map.end())
      {
          count=count+Map[rem];
      }
      Map[sum]++;
      helper(Map,sum,count,k,root->left);
      helper(Map,sum,count,k,root->right);
      
      //BackTrack The Current Sum Since It Reaches The Leaf Node
      Map[sum]--;
  }
    int sumK(Node *root, int k) 
    {
        unordered_map<int,int>Map;
        Map[0]=1;
        int sum=0;
        int count=0;
        helper(Map,sum,count,k,root);
        return count;
    }

};
