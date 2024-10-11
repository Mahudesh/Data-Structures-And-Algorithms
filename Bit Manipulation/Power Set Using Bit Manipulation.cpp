class Solution {
public:
   void subset(vector<int>&nums,int i,int n,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        subset(nums,i+1,n,temp,ans);
        temp.push_back(nums[i]);
        subset(nums,i+1,n,temp,ans);
        temp.pop_back();

    }
    bool checkForSet(int num, int i)
    {
        if((num&(1<<i))!=0)
        return true;
        return false;
    }
    vector<vector<int>> subsets(vector<int>& nums)
     {
      
        vector<vector<int>> ans;
        // subset(nums,0,nums.size(),temp,ans);
        //Bitwise Approach
        int n=nums.size();
        int size=1<<n;//pow(2,n);
        for(int num=0;num<size;num++)
        {
              vector<int>temp;
              for(int i=0;i<n;i++)
              {
                //check ith bit is set or not
                if((checkForSet(num,i)))
                {
                    temp.push_back(nums[i]);
                }
              }
              ans.push_back(temp);
        }
        return ans;
    }
};
