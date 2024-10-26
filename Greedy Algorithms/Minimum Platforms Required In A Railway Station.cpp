Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) 
    {
        // Your code here
        //Try To Find The Arrival And Departure Of Trains By The Time Passes
        //As A Person You Stand Outside And Clock Ticks Find Trains Are Arriving And Departuring
        ///If A Train Arrives ReqPlatforms++
        //If A Train Departs ReqPlatforms--
        
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int reqPlatforms=0;
        int maxi=0;
        int i=0,j=0;
        while(i<arr.size() && j<dep.size())
        {
            if(arr[i]<=dep[j])
            {
                reqPlatforms++;
                i++;
            }
            else if(arr[i]>dep[j])
            {
                reqPlatforms--;
                j++;
            }
                maxi=max(maxi,reqPlatforms);
        }
        return maxi;
    }
