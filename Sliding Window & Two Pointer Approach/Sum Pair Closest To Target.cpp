olution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) 
    {
        // code here
        sort(arr.begin(),arr.end());
        int l=0;
        int r=arr.size()-1;
        int closest=INT_MAX;
        int maxDiff=INT_MIN;
        vector<int>ans(2,-1);
        while(l<r)
        {
            int sum=arr[l]+arr[r];
            int currclosest=abs(target-sum);
            int currdiff=arr[r]-arr[l];
            if(currclosest<closest || currclosest==closest && currdiff>maxDiff)
            {
                closest=currclosest;
                maxDiff=currdiff;
                ans[0]=arr[l];
                ans[1]=arr[r];
            }
            
            if(sum>target)
            r--;
            else if(sum<target)
            l++;
            else
            break;
          
        }
        if(ans[0]==-1)
        return {};
        return ans;
    }
