
class Knapsack
{
    public:
    double val;
    double wt;
};
class Solution {
  bool static comp(Knapsack a, Knapsack b)
  {
      double c=a.val/a.wt;
      double d=b.val/b.wt;
      return c>d;
  }
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity)
    {
        // Your code here
        int n=val.size();
        Knapsack arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i].val=val[i];
            arr[i].wt=wt[i];
        }
        sort(arr,arr+n,comp);
        double points=0;
        int ind=0;
        double currentWeight=0;
        for(int i=0;i<n;i++)
        {
            if(currentWeight+arr[i].wt<=capacity)
            {
                currentWeight+=arr[i].wt;
              points=points+arr[i].val;
            }
            else
            {
                ind=i;
            double rem=capacity-currentWeight;
               points=points+((arr[i].val/arr[i].wt)*rem);
                break;
            }
        }
        
        return points;
    }
};
