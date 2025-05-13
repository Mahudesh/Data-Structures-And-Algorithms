class Solution {
public:
bool isVowel(char ch)
{
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
    int maxVowels(string s, int k)
    {
        int len=s.length();
        int l=0,r=0;
        int maxVowel=0;
        int vow=0;
        while(r<len)
        {
            if(isVowel(s[r]))
            vow++;

            if(r-l+1>k)
            {
                if(isVowel(s[l]))
                vow--;
                l++;
            }
            if(r-l+1==k)
            {
                maxVowel=max(maxVowel,vow);
            }
            r++;
        }
        return maxVowel;
    }
};
