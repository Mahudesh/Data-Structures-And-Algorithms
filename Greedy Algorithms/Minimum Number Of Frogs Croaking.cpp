class Solution {
public:
    int minNumberOfFrogs(string str)
     {
        vector<int>frogs(5,0);
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='c')
            {
                frogs[0]++;
                if(frogs[4]!=0)
                frogs[4]--;
            }
            else if(str[i]=='r')
            {
                if(frogs[0]==0)
                return -1;
                frogs[0]--;
                frogs[1]++;
            }
            else if(str[i]=='o')
            {
                if(frogs[1]==0)
                return -1;
                frogs[1]--;
                frogs[2]++;
            }
            else if(str[i]=='a')
            {
                if(frogs[2]==0)
                return -1;
                frogs[2]--;
                frogs[3]++;
            }
            else if(str[i]=='k')
            {
                if(frogs[3]==0)
                return -1;
                frogs[3]--;
                frogs[4]++;
            }
        }
        if(frogs[0]!=0 || frogs[1]!=0 || frogs[2]!=0 || frogs[3]!=0)
        return -1;
        return frogs[4];
    }
};
