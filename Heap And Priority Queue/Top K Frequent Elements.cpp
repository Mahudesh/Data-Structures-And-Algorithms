class Solution {
public:
// //use pair<int,int> to receive the variable in custom comparator since it is a pair
//     static bool compare(pair<int,int> a,pair<int,int> b)
//     {
//         return a.second>b.second;
//     }

struct comp
{
    bool operator()(pair<int,int>a,pair<int,int>b)
    {
        return a.second<b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k)
     {
        // unordered_map<int,int>Map;
        //  vector<int>ans;
        //  for(auto i : nums)
        //  Map[i]++;
        //  //To sort the map based on keys or values then convert it to vector of pairs

        //  vector<pair<int,int>> temp(Map.begin(),Map.end());

        //  sort(temp.begin(),temp.end(),compare);//sort by using custom comparator


        //  for (int i = 0; i < k && i < temp.size(); ++i) 
        //  {
        //     ans.push_back(temp[i].first);
        // }

        // return ans;

        unordered_map<int,int>Map;
        vector<int>ans;
        for(auto it: nums)
        Map[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(auto it: Map)
        {
            pq.push({it.first,it.second});
        }
        for(int i=0;i<k;i++)
        {
            auto todo=pq.top();
            pq.pop();
            ans.push_back(todo.first);
        }
        return ans;



    }
};
