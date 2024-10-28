class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        // //BruteForce: Find Out Candies Needed By Considering Only Left Neighbours
        // //Find Out Candies Needed By Considering Only Right Neighbours
        // //Find Out Maximum Candies Required By Taking Max Of Both left[i] And right[i]
        // int can=1;
        // int c=1;
        // int n=ratings.size();
        // vector<int>left(n,1);
        // // vector<int>right(n,1);
        // for(int i=1;i<n;i++)
        // {
        //     if( ratings[i]>ratings[i-1])
        //     {
        //     //    left[i]=can;
        //     //    can++;
        //     left[i]=left[i-1]+1;
        //     }
        //     else
        //     {
        //         left[i]=1;
        //         // can++;
        //     }
        // }
        // int ans=0;
        // can=1;
        // c=1;
        // for(int i=n-2;i>=0;i--)
        // {
        //     if(ratings[i]>ratings[i+1])
        //     {

        //         // right[i]=right[i+1]+1;
        //         can=c+1;
        //         c=can;
        //         // can++;
        //     }
        //     else
        //     {
        //         // right[i]=1;
        //         can=1;
        //         c=1;
        //         // can++;
        //     }
        //     ans+=max(left[i],can);
        // }
        // ans=ans+max(left[n-1],1);
        // // for(int i=0;i<n;i++)
        // // {
        // //     ans+=max(left[i],right[i]);
        // // }
        // return ans;
        //Optimal Approach
        //Slope Based Intution Approach
        int sum=1;
        int i=1;
        int peak=1,down=1;
        while(i<ratings.size())
        {
            if(i<ratings.size() && ratings[i]==ratings[i-1])
            {
                sum++;
                i++;
                continue;
            }
            peak=1;
            while(i<ratings.size() && ratings[i]>ratings[i-1])
            {
                peak++;
                sum=sum+peak;
                i++;
            }   
            down=1;
            while(i<ratings.size() && ratings[i]<ratings[i-1])
            {
                sum+=down;
                down++;
                i++;
            }
            if(peak<down)
            {
                sum=sum+(down-peak);
            }
        }
        return sum;
    }
};
