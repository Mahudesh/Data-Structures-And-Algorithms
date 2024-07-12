#include<unordered_map>
int getLengthofLongestSubstring(int k, string s)
{
   // Write your code here.
   int l=0;
   int r=0;
   int len=0;
   unordered_map<char,int>Map;
   while(r<s.length())
   {
      Map[s[r]]++;
      while(Map.size()>k)
      {
         Map[s[l]]--;
         if(Map[s[l]]==0)
         Map.erase(s[l]);
         l++;
      }
      len=max(len,r-l+1);
      r++;

   }
   return len;
   // a b c b a
   // 0 1 2 3 4
}
