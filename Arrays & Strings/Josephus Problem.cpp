class Solution {
public:
    int findTheWinner(int n, int k) 
    {
    //     vector<bool>survival(n,true);
    //     vector<int>arr;
    //     for(int i=0;i<n;i++)
    //     {
    //         arr.push_back(i+1);
    //     }
    //     int i=0;
    //    while(arr.size()>1)
    //    {
    //          i=i+k-1;
    //          if(i>=arr.size())
    //          {
    //             i=i%arr.size();
    //          }
    //          arr.erase(find(arr.begin(),arr.end(),arr[i]));

    //    }
    //    return arr[0];
          int safepos=0;
          for(int i=1;i<=n;i++)
          {
            //Find The Safe Position For Each Iteration By Increasing The Circle Size
            //Find Safe Position For 1 Person, 2 Person, 3 Person etc
            //Untill Safe Position For Nth Person
            safepos=(safepos+k)%i;
          }
          //Since I Keep Initially 0th Index Person Is Safe Now Return safepos+1 For Person 1 To N
          return ++safepos;
    }
};
