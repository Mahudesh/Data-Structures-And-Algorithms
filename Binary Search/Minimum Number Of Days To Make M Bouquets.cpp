class Solution {
public:
int makeBokets(vector<int>&bloomDay, int m, int k,int days)
{
    int flowers=0;
    int bok=0;
    for(int i=0;i<bloomDay.size();i++)
    {
        if(bloomDay[i]<=days)
        {
            flowers++;
        }
        else
        {
            flowers=0;
        }
        if(flowers==k)
        {
            bok++;
            flowers=0;
        }
    }
    return bok;
}
int findMax(vector<int>&bloomDay)
{
    int maxi=INT_MIN;
    for(auto it: bloomDay)
    maxi=max(maxi,it);
    return maxi;
}
    int minDays(vector<int>& bloomDay, int m, int k)
     {
        if((long long)m*(long long) k>bloomDay.size()) return -1;
        int low=1;
        int high=findMax(bloomDay);
        while(low<=high)
        {
            int mid=(low+high)/2;
            int bok=makeBokets(bloomDay,m,k,mid);
            if(bok>=m)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
     //   if(low<m) return -1;
        return low;
    }
};
//1 10 3 10 2
