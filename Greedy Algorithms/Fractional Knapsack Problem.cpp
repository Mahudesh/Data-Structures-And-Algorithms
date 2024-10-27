Solution {
  public:
    bool static comp(Item a, Item b)
    {
        double perWeightA=a.value/a.weight;
        double perWeightB=b.value/b.weight;
        return perWeightA>perWeightB;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& values, vector<int>& weights, int w)
    {
        // Your code here
        Item arr[values.size()];
        for(int i=0;i<values.size();i++)
        {
            arr[i].value=values[i];
            arr[i].weight=weights[i];
        }
        sort(arr,arr+values.size(),comp);
        double maxVal=0;
        for(int i=0;i<values.size();i++)
        {
            if(arr[i].weight<=w)
            {
                w=w-arr[i].weight;
                maxVal=maxVal+arr[i].value;
            }
            else
            {
                maxVal=maxVal+((arr[i].value/arr[i].weight)*w);
                w=0;
                break;
            }
        }
        return maxVal;
    }
