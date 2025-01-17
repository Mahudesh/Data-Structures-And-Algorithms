class Solution {
public:
void rev(string&str, int st, int end)
{
    while(st<end)
    {
        swap(str[st],str[end]);
        st++;
        end--;
    }
}
    string reverseWords(string s)
     {
        int i=0;
        int j=0;
        int len=s.length();
        int st=-1;
        int end=-1;
        reverse(s.begin(),s.end());
        while(j<len)
        {
            while(j<len && s[j]==' ')
            {
                j++;
            }
            if(j==len)
            break;
            st=i;
            while(j<len && s[j]!=' ')
            {
                s[i]=s[j];
                i++;
                j++;
            }
            end=i-1;
            // reverse(s.begin()+st,s.begin()+end);
            rev(s,st,end);
            s[i]=' ';
            i++;

        }
        // while(i)

        return s.substr(0,end+1);
    }
};
