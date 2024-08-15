long long maxSubarraySum(vector<int> arr, int n)
{
    long long len = 0,sum = 0,maxiSum=0;
    for(int i=0;i<arr.size();i++)
    {
        sum = sum+arr[i];
        if(sum<0)
        {
            sum =0;
        }
        if(maxiSum<sum)
        {
            maxiSum = sum;
        }
    }
    return maxiSum;
}
