#LeetCode: 42

class Solution {
public:
    int trap(vector<int>& height)
     {
        //Formula : min(leftMaximum,rightMaximum)-currentheight
        //Use Prefix Maximum Calculation for leftMaximum
        //Use Suffix Maximum Calculation for rightMaximum

        // int n=height.size();
        // vector<int>leftMaxi(n);
        // vector<int>rightMaxi(n);
        // leftMaxi[0]=height[0];
        // for(int i=1;i<n;i++)
        // {
        //     leftMaxi[i]=max(height[i],leftMaxi[i-1]);
        // }
        // rightMaxi[n-1]=height[n-1];
        // for(int i=n-2;i>=0;i--)
        // {
        //     rightMaxi[i]=max(height[i],rightMaxi[i+1]);
        // }
        // int totalwater=0;
        // for(int i=0;i<n;i++)
        // {
        //     totalwater+=min(leftMaxi[i],rightMaxi[i])-height[i];
        // }
        // return totalwater;

        //Optimal Solution

       int l=0;
       int r=height.size()-1;
       int leftMaxi=0;
       int rightMaxi=0;
       int water=0;
       while(l<=r)
       {
            if(height[l]<=height[r])
            {
                if(height[l]>=leftMaxi)
                {
                    leftMaxi=height[l];
                }
                else
                {
                    water=water+(leftMaxi-height[l]);
                }
                l++;
            }
            else 
            {
                if(height[r]>=rightMaxi)
                {
                    rightMaxi=height[r];
                }
                else
                {
                    water=water+(rightMaxi-height[r]);
                }
                r--;
            }
          
       }
       return water;
    }
};
