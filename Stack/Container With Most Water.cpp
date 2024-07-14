#LeetCode: 11
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int l=0;
        int r=height.size()-1;
        int ans=-1;
        while(l<r)
        {
            //To Calculate Maximum Area Height*Width Is The Formula
            int width=r-l;
            int h=min(height[l],height[r]);
            if(ans<= (long long)width*h)
            {
                ans=(long long)width*h;
            }
            //Always Move Which Side Has Smaller Length
            //Since How Much Amount Of Water Can Be Stored Can Only Be Determined By Minimum Height

            if(height[l]<height[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
