#include<vector>

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &intervals)
{
	// Write your code here.
	sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        // for(int i=0;i<intervals.size();i++)
        // {
        //     if(ans.empty())
        //     {
        //         ans.push_back(intervals[i]);
        //     }
        //     else if(intervals[i][0]<=ans.back()[1])
        //     {
        //         //If Start Is Greater Than Previous End Of The Interval Then Extend The Maximum Interval
        //         ans.back()[1] = max(ans.back()[1],intervals[i][1]);
        //     }
        //     else
        //     {
        //         ans.push_back(intervals[i]);
        //     }
        // }
        // return ans;

        for(int i=0;i<intervals.size();i++)
        {
            if(ans.empty())
            {
                ans.push_back(intervals[i]);
            }
            else if(ans.back()[1]>=intervals[i][0])
            {
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else
            {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
}
