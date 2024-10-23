   class Demo
    {
        public:
        int start;
        int end;
        int pos;
        
    };
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    bool static comp(Demo a, Demo b)
    {
        return a.end<b.end;
    }
    int maxMeetings(vector<int> start, vector<int> end) 
    {
        // Your code here
        //They can ask the order of the meeting too
        //So Try to store the order of the meeting also 
        Demo arr[start.size()];
        for(int i=0;i<start.size();i++)
        {
            arr[i].start=start[i];
            arr[i].end=end[i];
            arr[i].pos=i+1;
        }
        sort(arr,arr+start.size(),comp);
        int freeTime=arr[0].end;
        int m=1;
        for(int i=1;i<start.size();i++)
        {
            if(arr[i].start>freeTime)
            {
                m++;
                freeTime=arr[i].end;
            }
        }
        return m;
    }
};
