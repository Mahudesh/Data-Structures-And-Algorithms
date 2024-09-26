class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) 
    {
        //Same As 3Sum Problem
        vector<vector<int>>ans;
	sort(arr.begin(),arr.end());
    int closestSum=0;
    //Initialize The Closest Sum With Valid nums[0]+nums[1]+nums[2]
    closestSum=arr[0]+arr[1]+arr[2];
	for(int i=0;i<arr.size()-2;i++)
	{
		if(i>0 && arr[i]==arr[i-1])
		continue;
		int j=i+1;
		int k=arr.size()-1;
		while(j<k)
		{
			int sum=arr[i]+arr[j]+arr[k];
            //Check For If The Current Sum Is Closest To The Previous Closest Sum
            //If So Update The Closest Sum As Sum-Target
            if(abs(closestSum-target)>abs(sum-target))
            {
                closestSum=sum;
            }
			if(sum<target)
			{
				j++;
			}
			else if(sum>target)
			{
				k--;
			}
			else
			{
				// closestSum=sum;
                return sum;
			}
		}
	}
		return closestSum;
    }
};
