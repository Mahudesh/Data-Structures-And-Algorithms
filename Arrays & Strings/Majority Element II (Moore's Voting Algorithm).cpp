class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        //Moore's Voting Algorithm Logic
        //For Occurrence Of More Than n/3 Times Atmost 2 Elements Only Will Be Possible
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int ele1=INT_MAX;
        int ele2=INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(cnt1==0 && nums[i]!=ele2)
            {
                cnt1=1;
                ele1=nums[i];
            }
            else if(cnt2==0 && nums[i]!=ele1)
            {
                cnt2=1;
                ele2=nums[i];
            }
            else if(nums[i]==ele1)
            {
                cnt1++;
            }
            else if(nums[i]==ele2)
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        vector<int>ans;
        int one=0;
        int two=0;
        for(int i=0;i<n;i++)
        {
            if(ele1==nums[i])
            one++;
            if(ele2==nums[i])
            two++;
        }
        if(one>(int)(n/3))
        ans.push_back(ele1);

        if(two>(int)(n/3))
        ans.push_back(ele2);

        return ans;

    }
};
