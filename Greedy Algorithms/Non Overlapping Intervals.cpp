Solution {
  public:
  bool static comp(pair<int,int>a, pair<int,int>b)
  {
      return a.second<b.second;
  }
    int minRemoval(int N, vector<vector<int>> &intervals) 
    {
        // code here
        vector<pair<int,int>>p;
        for(auto it: intervals)
        {
            p.push_back(make_pair(it[0],it[1]));
        }
        sort(p.begin(),p.end(),comp);
        int maxi=1;
        int freetime=p[0].second;
        for(int i=1;i<intervals.size();i++)
        {
            if(p[i].first>=freetime)
            {
                maxi++;
                freetime=p[i].second;
            }
        }
        return intervals.size()-maxi;
        // sort(intervals.begin(),intervals.end(),co);
    //     int last=intervals[0][1];
    //     int cnt=0;
    //     for(int i=1;i<intervals.size();i++)
    //     {
    //         if(intervals[i][0]<last)
    //         {
    //             cnt++;
    //             last=min(last,intervals[i][1]);
    //         }
    //         else
    //             last=intervals[i][1];
    //     }
    //     return cnt;
    }
};
