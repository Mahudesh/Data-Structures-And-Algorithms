class Solution {
public:
    int singleNumber(vector<int>& nums)
     {
    //     sort(nums.begin(),nums.end());
    //     for(int i=0;i<nums.size()-1;i=i+2)
    //     {
    //         if(nums[i]!=nums[i+1])
    //         {
    //             return nums[i];  
    //         }
    //     }
    //     return nums[nums.size()-1];
    //XOR Of Same Number Gives You The Zero
    //And Zero XOR With Any Number Gives You That Number Itself
    int Xor1=0;
    for(auto it: nums)
    Xor1=Xor1^it;
    return Xor1;
     }

            // int low=1;
            // int high=nums.size()-2;
            // while(low<=high)
            // {
            //     int mid=(low+high)/2;
            //     if(arr[mid]-1!=arr[mid])
            // }
     
};
