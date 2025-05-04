// int helper(int ind, vector<int>& arr, int n)
// {
//     if(ind>=n-1)
//     return 0;
//     if(arr[ind]==0)
//     return 1e9;
//     int mini=1e9;
//     int ele=arr[ind];
//     for(int i=1;i<=ele;i++)
//     {
//         if(ind+i<n)
//         {
//             int jumps=1+helper(ind+i,arr,n);
//             mini=min(mini,jumps);
//         }
//     }
//     return mini;
// }
int minJumps(vector<int> &arr,int n) 
{

    int curr=0;
    int maxIndex=0;
    int jumps=0;
    for(int i=0;i<n;i++)
    {
        maxIndex=max(maxIndex,i+arr[i]);
        if(curr>=n-1)
        return jumps;
        if(i==curr)
        {
            jumps++;
            curr=maxIndex;
        }
    }
    return -1;
    // Write your code here.
    // vector<int>dp(n,0);

    // dp[n-1]=0;
    // for(int ind=n-2;ind>=0;ind--)
    // {
    //     int ele=arr[ind];
    //     int mini=1e9;
    //     for(int i=1;i<=ele;i++)
    //     {
    //         if(ind+i<n)
    //         {
    //             int jumps=1+dp[ind+i];
    //             mini=min(mini,jumps);
    //         }

    //     }
    //     dp[ind]=mini;
    // }
    // if(dp[0]==1e9)
    // return -1;
    // return dp[0];
    // int a=helper(0,arr,n);
    // if(a==1e9)
    // return -1;
    // return a;
}
