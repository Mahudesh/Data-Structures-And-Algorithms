class Solution {
public:
    bool lemonadeChange(vector<int>& bills)
     {
         int f=0;
         int t=0;
         for(auto ele : bills)
         {
             if(ele==5)
             {
                 f++;
             }
             else if(ele==10)
             {
                 f--;
                 t++;
             }
             else if(t>0)
             {
                 t--;
                 f--;
             }
             else
             {
                 f--;
                 f--;
                 f--;
             }
             if(f<0)
             return false;
         }
         return true;
    }
};
