class Solution {
public:
     int largestRectangleArea(vector<int>& heights) 
     {
    //     int size = heights.size();
    //     int ans = 0;
    //     stack<int> st;
    //     vector<int> prevsmaller(size,-1);
    //     vector<int> nextsmaller(size,size);

    //     // Calculate prevsmaller
    //     for (int i = 0; i < size; i++) 
    //     {
    //         while (!st.empty() && heights[st.top()] >= heights[i])
    //          {
    //             st.pop();
    //         }
    //         if (!st.empty()) 
    //         {
    //             prevsmaller[i] = st.top();
    //         } 
    //         //if stack is empty then it has no previous smaller element so it automatically be -1 since we have initialized it
    //         st.push(i);
    //     }

    //     // Clear the stack for the next calculation
    //     while (!st.empty())
    //      {
    //         st.pop();
    //     }

    //     // Calculate nextsmaller
    //     st.push(heights.size() - 1);
    //     for (int i = size - 2; i >= 0; i--) 
    //     {
    //         while (!st.empty() && heights[st.top()] >= heights[i]) 
    //         {
    //             st.pop();
    //         }
    //         if (!st.empty())
    //          {
    //             nextsmaller[i] = st.top();
    //         }
    //         //if stack is empty then we would be initialized that number in starting itself so we need not to enter it again
    //         st.push(i);
    //     }

    //     // Calculate the maximum area
    //     for (int i = 0; i < size; i++) 
    //     {
    //         //calculate the area of the current element
    //         long long temp = heights[i];
    //         //calculate the area untill previous smaller arrives (prev smaller should not be included to calculate area)
    //         temp += (i - prevsmaller[i] - 1) * heights[i];
    //         //calculate the area untill next smaller arrives (next smaller should not be included to calculate area)
    //         temp += (nextsmaller[i] - i - 1) * heights[i];
    //         //-1 is used to ignore the area of prev smaller and next smaller
    //         ans = max(ans, (int)(temp));
    //     }

      //  return ans;

      //Find PrevSmaller And NextSmaller 
      int n=heights.size();
      stack<int>st;
      vector<int>prevSmaller(n,0);
      vector<int>nextSmaller(n,n-1);

      for(int i=n-1;i>=0;i--)
      {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            nextSmaller[i]=st.top()-1;
        }
        st.push(i);
      }
      while(!st.empty())
      {
        st.pop();
      }
      for(int i=0;i<n;i++)
      {
        while(!st.empty() && heights[st.top()]>=heights[i])
        {
            st.pop();
        }
        if(!st.empty())
        {
            prevSmaller[i]=st.top()+1;
        }
        st.push(i);
      }
      int maxi=INT_MIN;
      for(int i=0;i<n;i++)
      {
        int width=(nextSmaller[i]-prevSmaller[i])+1;
        int height=heights[i];
        maxi=max(maxi,width*height);
      }
      return maxi;
    }
};
