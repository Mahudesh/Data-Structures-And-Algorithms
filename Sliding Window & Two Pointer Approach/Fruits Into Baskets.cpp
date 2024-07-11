#LeetCode 904
class Solution {
public:
    int totalFruit(vector<int>& fruits)
     {
        //A Valid Window Should Contain Atmost 2 Different Integers Since You Have 2 Baskets
        //Use Map Data Structure If Its Size Exceeds 2 Then Remove And Shrink The Window Size
        int l=0;
        int r=0;
        int len=0;
        unordered_map<int,int>Map;
        while(r<fruits.size())
        {
            Map[fruits[r]]++;
            //If Size Is <= 2 Then Calculate The Maximum Length Will Be Calculated
            //Maximum Length Will Be The Maximum Fruit Gained
            if(Map.size()<=2)
            {
                len=max(len,r-l+1);
            }
            else if(Map.size()>2)
            {
                //If Size Greater Than 2 Then There Are More Than 2 Fruits Shrink The Left Window
                while(Map.size()>2)
                {
                    Map[fruits[l]]--;
                    //If The Frequency Of Fruits Reaches Zero Then Erase It From The Map
                    if(Map[fruits[l]]==0) Map.erase(fruits[l]);
                    l++;
                }
            }
            r++;
        }
        return len;
       
    }
};
// 1 1 2 3 2
// 0 1 2 3 4
