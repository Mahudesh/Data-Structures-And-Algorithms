void nStarDiamond(int n) 
{
    // Write your code here.
    //First Print Front Pyramid
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=(2*i)-1;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=n-1;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
    //Next Print Inverted Pyramid
    int sp=0;
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=sp;j++)
        {
            cout<<" ";
        }
        for(int j=1;j<=(2*i)-1;j++)
        {
            cout<<"*";
        }
        for(int j=1;j<=sp;j++)
        {
            cout<<" ";
        }
        sp++;
        cout<<endl;
    }
}