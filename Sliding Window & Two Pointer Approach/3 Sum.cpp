class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr)
     {
         int n=arr.size();


        //  sort(nums.begin(),nums.end());
        //  set<int>arr;
        //  vector<vector<int>>result;
        // for(int i=0;i<n-2;i++)
        // {
        //     for(int j=i+1;j<n-1;j++)
        //     {
        //         for(int k=j+1;k<n;k++)
        //         {
        //             if(nums[i]+nums[j]+nums[k]==0 && i!=j && i!=k && j!=k )
        //             {
        //                 arr.insert({nums[i],nums[j],nums[k]});
        //             }
        //         }
        //     }
        // }
        // result(arr.begin(),arr.end());
        
        // set<vector<int>>st;
        // for(int i=0;i<n;i++)
        // {
        //     set<int>hashSet;
        //     for(int j=i+1;j<n;j++)
        //     {
        //         int third=-(arr[i]+arr[j]);
        //         if(hashSet.find(third)!=hashSet.end())
        //         {
        //             vector<int>temp={arr[i],arr[j],third};
        //             sort(temp.begin(),temp.end());    
        //             st.insert(temp);
        //         }
        //         hashSet.insert(arr[j]);


        //     }
        // }
        // vector<vector<int>>ans(st.begin(),st.end());

        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i]==arr[i-1])
            continue;
            int j=i+1;
            int k=arr.size()-1;
            while(j<k)
            {
                int sum=arr[i]+arr[j]+arr[k];
                if(sum<0)
                {
                    j++;
                }
                else if(sum>0)
                {
                    k--;
                }
                else
                {
                    vector<int>temp={arr[i],arr[j],arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && arr[j]==arr[j-1])
                    {
                        j++;
                    }
                    while(j<k && arr[k]==arr[k+1])
                    {
                        k--;
                    }
                }
            }
        }
       
        return ans;
    }
};
