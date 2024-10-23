class Solution {
public:
bool static comp(pair<int,int>a, pair<int,int>b)
{
    return a.second<b.second;
}
    int findLongestChain(vector<vector<int>>& pairs)
     {
        vector<pair<int,int>>p;
        for(auto it: pairs)
        {
            p.push_back(make_pair(it[0],it[1]));
        }
        sort(p.begin(),p.end(),comp);
        int maxi=1;
        int lastpair=p[0].second;
        for(int i=1;i<pairs.size();i++)
        {
            if(p[i].first>lastpair)
            {
                maxi++;
                lastpair=p[i].second;
            }
        }
        return maxi;
    }
};
