public:
    int binary_to_decimal(string str)
    {
        // Code here.
        int ans=0;
        int power=1;
        for(int i=str.length()-1;i>=0;i--)
        {
            if(str[i]=='1')
            {
                ans=ans+power;
            }
            power=power*2;
        }
        return ans;
    }
