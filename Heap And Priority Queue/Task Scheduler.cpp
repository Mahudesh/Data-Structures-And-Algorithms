class Solution {
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        // Always Take The Most Frequently Occurring Character First
        // Since By Doing This We Can Avoid Grouping Of These Most Frequent Characters At Last
        // Because If We Group That At Last We Need An Idle Time To Process It

        unordered_map<char,int>Map;
        for(auto ch : tasks)
        Map[ch]++;

        priority_queue<int>pq;
        for(auto it : Map)
        {
            pq.push(it.second);
        }
        queue<pair<int,int>>q;
        int timer=0;
        while(!pq.empty() || !q.empty())
        {
            timer++;
            int task=0;
            if(!pq.empty())
            {
                task=pq.top();
                pq.pop();
                task--;

                // If Task Becomes 0 Then No Point Of Adding Into The Queue
                if(task>0)
                {
                     int nxtAvailable=timer+n;
                     q.push({task,nxtAvailable});
                }
            }
            // Look For Queue Whether The Time Has Arrived To Take The Scheduled Tasks
        while(!q.empty() && timer==q.front().second)
            {
            pq.push(q.front().first);
            q.pop();
            }
        }
        return timer;
    }
};
