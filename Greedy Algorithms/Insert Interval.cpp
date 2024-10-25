class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        //Boil Down The Problem To 3 Parts
        //Left Part Which Does Not Overlap
        //Middle Part Which May Or May Not Overlap
        //Right Part Which Does Not Overlap Since It Is Sorted

        vector<vector<int>>ans;
        int i=0;
        int n=intervals.size();
        while(i<n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while(i<n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
