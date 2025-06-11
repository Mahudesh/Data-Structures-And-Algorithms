class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        // vector<vector<int>>ans;
        // vector<pair<int,vector<int>>>temp;
        // for(int i=0;i<points.size();i++)
        // {
        //     int dist=(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
        //     temp.push_back({dist,{points[i][0],points[i][1]}});
        // }
        // sort(temp.begin(),temp.end());
        // for(int i=0;i<k;i++)
        // {
        //     ans.push_back(temp[i].second);
        // }
        // return ans;

        // Instead of Sorting Using Minheap We Can Store The Closest points Element At First
        vector<vector<int>>ans;
        priority_queue<pair<int,vector<int>>, vector<pair<int,vector<int>>>, greater<pair<int,vector<int>>>>pq;
        for(int i=0;i<points.size();i++)
        {
             int dist=(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
             pq.push({dist,{points[i][0],points[i][1]}});
        }
        for(int i=1;i<=k;i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
