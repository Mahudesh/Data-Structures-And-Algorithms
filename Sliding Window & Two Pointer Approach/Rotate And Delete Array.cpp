class Solution {
  public:
  void rightRotateArray(vector<int>&arr)
  {
      int last=arr.back();
      arr.pop_back();
      arr.insert(arr.begin(),last);
  }
    int rotateDelete(vector<int> &arr) 
    {
        int size=arr.size();
        for(int i=1;i<=size/2;i++)
        {
            rightRotateArray(arr);
            
            int ind=arr.size()-i;
            arr.erase(arr.begin()+ind);
        }
        return arr[0];
    }//  1 3  6 
