class Solution {
public:
bool isPossible(vector<int>&nums, int op, int balls)
{
    //2 4 7 2
    int operations=0;
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>balls)
        {
            //If Bag has 8 balls and atmost balls to be 4 then 8/4 will theoretically give you 2 splits
            //But 8 can be divided into 4+4 in one operations
            //So If A Number Is Exactly divisible then operations--
            //If Bag Has 7 balls and atmost balls in a bag should be 4
            //Theoretically 7 balls in a bag can be splitted into 1 operation 7/4=1
            //So It Automatically detects 1 operation is needed while If 8/4=2 it detects 2 splits are needed
            //So remove the one extra split
           operations= operations+((nums[i])/balls);
           if(nums[i]%balls==0)
           operations--;

        }
    }
    return operations<=op;
}
    int minimumSize(vector<int>& nums, int maxOperations) 
    {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high)
        {
            //Search Space
            //Number of Atmost Balls We Desired To Have In One Bag
            //If mid Balls Were Desired To Keep In One Bag With MinOperations Then Look For Minimizing It Again
            //Because We Require Minimum Number Of Balls In Bag To Minimze The Penalty
            int mid=(low+high)/2;
            if(isPossible(nums,maxOperations,mid))
            {
                //If More Number Of Balls Can Contain In One Bag Then Min Operations Taken Will Be Lesser Than minOp
                //So Decrease Number Of Balls Required In One Bag To Have to Maximize the Minimum Operations
                high=mid-1;
            }
            else
            {
                //If Less Number Of Balls Can Contain In One Bag Then Maximum Operations Will Be Taken Which Is Greater Than Minop
                //So Increase The Balls Contained In One Bag To Have Correct Minop
                low=mid+1;
            }
        }
        return low;
    }
};
//2 4 8 2
