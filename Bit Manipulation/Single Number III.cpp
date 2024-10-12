class Solution {
public:
    vector<int> singleNumber(vector<int>& nums)
     {
        //BruteForce
        //  map<int,int>Map;
        //  for(auto ele : nums)
        //  {
        //      Map[ele]++;
        //  }  
        //  vector<int>ans;
        //  for(auto pair : Map)
        //  {
        //      if(pair.second==1)
        //      {
        //          ans.push_back(pair.first);
        //      }
        //  }
        //  return ans;
        //Optimal Approach
        long long xorr=0;
        for(auto it: nums)
        xorr=xorr^it;
        int rightMostSetBit=(xorr&(xorr-1))^xorr;
        // rightMostSetBit=rightMostSetBit^xorr;

        //Separate Those Two Distinct Numbers Into Bucket By It's RightMostSetBit
        //If The Index Of RightMostSetBit Of nums[i] Is 1 Then & Will Give A Value
        //If The Index Of RightMostSetBit Of nums[i] Is 0 Then & Will Give Zero
        int b1=0;
        int b2=0;
        for(int i=0;i<nums.size();i++)
        {
            //Do XOR Of Whatever Elements Storing Into The Bucket 1 Or 2
            //Since Ultimately At The End Of Traversal B1 And B2 Stores Every Element Twice Except One
            //The Problem Gets Boils Down Into Single Number I
            //Every Element Appears Twice Except One
            if((nums[i]&rightMostSetBit)!=0)
            b1=b1^nums[i];
            else
            b2=b2^nums[i];
        }
        return {b1,b2};
    }
};
