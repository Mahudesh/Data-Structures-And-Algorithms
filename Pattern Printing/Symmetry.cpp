void symmetry(int n) 
{
    // Write your code here.
    int sp=(n*2)-2;
    for(int i=1;i<=n;i++)
    {
        //stars
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }



        //spaces
        for(int j=1;j<=sp;j++)
        {
            cout<<"  ";
        }

        //stars
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        sp=sp-2;
        cout<<endl;

    }
    sp=2;
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }

        for(int j=1;j<=sp;j++)
        {
            cout<<"  ";
        }

        for(int j=1;j<=i;j++)
        {
            cout<<"* ";
        }
        sp=sp+2;
        cout<<endl;
    }
}


Output: 
*         *
* *     * *
* * * * * *
* *     * *
*         *
