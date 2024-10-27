class Demo
{
    public:
    int boxType;
    int quantity;
};
class Solution {
public:
bool static comp(Demo a, Demo b)
{
    //Since Quantity Per Box Is Given As Straight No Need To Find Per BoxType
    return a.quantity>b.quantity;
}
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        //Modified Fractional Knapsack Problem Only
        Demo arr[boxTypes.size()];
        for(int i=0;i<boxTypes.size();i++)
        {
            arr[i].boxType=boxTypes[i][0];
            arr[i].quantity=boxTypes[i][1];
        }
        sort(arr,arr+boxTypes.size(),comp);
        int maxBoxesUnits=0;
        for(int i=0;i<boxTypes.size();i++)
        {
            if(arr[i].boxType<=truckSize)
            {
                maxBoxesUnits=maxBoxesUnits+(arr[i].boxType*arr[i].quantity);
                truckSize=truckSize-arr[i].boxType;
            }
            else
            {
                //Since Quantity Per Each Box Given As Straight Just Directly Multiply
                //RemainingTruckSize Multiplied By Current BoxType's Quantity
                maxBoxesUnits+=arr[i].quantity*truckSize;
                truckSize=0;
                break;
            }
        }
        return maxBoxesUnits;
    }
};
