void nBinaryTriangle(int n)
 {
    // Write your code here.
    int start=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2!=0)
        start=1;
        else
        start=0;

        for(int j=1;j<=i;j++)
        {
            cout<<start<<" ";
            start=1-start;
        }
        cout<<endl;
    }
}
