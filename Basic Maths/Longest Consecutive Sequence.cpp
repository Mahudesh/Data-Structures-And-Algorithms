  // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_set<int>st;
      for(int i=0;i<N;i++)
      st.insert(arr[i]);
      int c=1;
      int maxLen=0;
      for(auto it : st)
      {
          int val=it;
          c=1;
          if(st.find(val-1)==st.end())
          {
              while(st.find(val+1)!=st.end())
              {
                  c++;
                  val++;
              }
              maxLen=max(maxLen,c);
          }
      }
      return maxLen;
    }
