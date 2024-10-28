void alphaHill(int n) 
{
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        char ch='A';
        int breakPoint=(((2*i)-1)/2);
        for(int j=1;j<=(2*i)-1;j++)
        {
            cout<<ch<<" ";
            if(j<=breakPoint)
            ch++;
            else
            ch--;
        }
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        cout<<endl;
    }
}
