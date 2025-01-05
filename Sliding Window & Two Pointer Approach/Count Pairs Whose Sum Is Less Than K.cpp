Solution {
  public:
    int countPairs(vector<int> &arr, int target) 
    {
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        int cnt=0;
        while(i<j)
        {
            int sum=arr[i]+arr[j];
            if(sum>=target)
            j--;
            else
            {
                cnt=cnt+j-i;
                i++;
            }
        }
        return cnt;
    }
