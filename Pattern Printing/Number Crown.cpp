void numberCrown(int n) 
{
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        //Print
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";
        }
        //Space
        for(int j=1;j<=(2*n)-(2*i);j++)
        {
            cout<<" ";
        }
        //Print
        for(int j=i;j>=1;j--)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
