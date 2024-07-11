Maximum Points You Can Obtain From Cards
#LeetCode 1423

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) 
    {

        int n=cardPoints.size();
        int leftsum=0;
        int rightsum=0;
        int maxSum=INT_MIN;
        //Pick All Cards Initially From Left
        for(int i=0;i<k;i++)
        {
            leftsum+=cardPoints[i];
        }
        maxSum=max(maxSum,leftsum);
        //Remove One Card From Left And Take The Right Card For Maximum Sum
        for(int i=0;i<k;i++)
        {
            leftsum-=cardPoints[k-1-i];
            rightsum=rightsum+cardPoints[n-i-1];
            maxSum=max(maxSum,leftsum+rightsum);
        }
        return maxSum;
    }
};
