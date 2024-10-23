
class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    bool static comp(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int maxDeadline=arr[0].dead;
        for(int i=1;i<n;i++)
        {
            maxDeadline=max(maxDeadline,arr[i].dead);
        }
        vector<int>schedule(maxDeadline+1,-1);
        int maxProfit=0;
        int jobs=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead;j>0;j--)
            {
                if(schedule[j]==-1)
                {
                    schedule[j]=arr[i].id;
                    maxProfit+=arr[i].profit;
                    jobs++;
                    break;
                }
            }
        }
        return {jobs,maxProfit};
    } 
};
