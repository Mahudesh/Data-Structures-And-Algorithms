class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) 
    {
        int maxCustomers=0;
        int n=customers.size();

        int l=0,r=0;
        int currcust=0;
        int left=-1;
        int right=-1;
        // Try To Find The Right Sliding Window Where I Can Use Those Super Power Of 2 Minutes
        while(r<n)
        {
            currcust=currcust+(grumpy[r]*customers[r]);

            if(r-l+1>minutes)
            {
                if(grumpy[l]==1)
                {
                    currcust=currcust-customers[l];
                }
                l++;
            }
            if(maxCustomers<currcust)
            {
                maxCustomers=currcust;
                left=l;
                right=r;
            }
            r++;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(i>=left && i<=right || grumpy[i]==0)
            ans=ans+customers[i];
        }
        return ans;
    }
};
