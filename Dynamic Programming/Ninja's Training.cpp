int helper(int dayIndex,vector<vector<int>> task, int last,vector<vector<int>>&dp)
{
    
    if(dayIndex==0)
    {
        int maxi=0;
        for(int i=0;i<=2;i++)
        {
            if(i!=last)
            maxi=max(maxi,task[0][i]);
        }
        return maxi;
    }
    if(dp[dayIndex][last]!=-1)
    return dp[dayIndex][last];
    int maxi=0;
    for(int i=0;i<=2;i++)
    {
        if(i!=last){
          int points=task[dayIndex][i]+ helper(dayIndex-1,task,i,dp);
          maxi=max(maxi,points);
        }
    }
    return dp[dayIndex][last]=maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    // vector<vector<int>>dp(n,vector<int>(4,-1));
    // return helper(n-1,points,3,dp);



    //Tabulation Approach
    vector<vector<int>>dp(n, vector<int>(4,-1));
    //Base Condition
    //Bottom Up Approach
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));

    for(int day=1;day<n;day++)
    {
        // int maxi=0;
        for(int last=0;last<=3;last++)
        {
            int maxi=0;
            for(int i=0;i<=2;i++)
            {
                if(i!=last)
                {
                    int point=points[day][i]+dp[day-1][i];
                    maxi=max(maxi,point);
                }
            }
            dp[day][last]=maxi;
        }
    }
    return dp[n-1][3];
}
