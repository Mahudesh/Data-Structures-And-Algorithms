void alphaRamp(int n) 
{
    // Write your code here.
        char ch='A';
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<ch<<" ";
        }
        cout<<endl;
        ch++;
    }
}
