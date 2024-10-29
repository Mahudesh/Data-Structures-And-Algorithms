void getStarPattern(int n)
 {
    // Write your code here.
    int len=n;
    for(int i=1;i<=len;i++)
    {
        if(i==1 || i==len)
        {
            for(int j=1;j<=len;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        else
        {
            for(int j=1;j<=len;j++)
            {
                if(j==1 || j==len)
                {
                    cout<<"* ";
                }
                else
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
}
