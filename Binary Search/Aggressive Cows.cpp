bool isPossible(vector<int>&stalls, int k, int dist)
{
    int lastCow=stalls[0];
    int cows=1;
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastCow>=dist)
        {
            cows++;
            lastCow=stalls[i];
        }
    }
    return cows>=k;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[stalls.size()-1]-stalls[0];
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(isPossible(stalls,k,mid))
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return high;
}
