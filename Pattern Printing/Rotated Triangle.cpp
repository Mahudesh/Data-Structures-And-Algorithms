void nStarTriangle(int n)
 {
    // Write your code here.
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }
    // for(int i=n-1;i>=1;i--)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         cout<<"*";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=(2*n)-1;i++)
    {
        if(i<=n)
        {
            for(int j=1;j<=i;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
        else
        {
            for(int j=1;j<=(2*n)-i;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }
}

Output: 

*
**
***
**
