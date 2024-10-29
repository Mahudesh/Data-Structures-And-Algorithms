void getNumberPattern(int n) 
{
    // Write your code here.
    for(int i=0;i<(2*n)-1;i++)
    {
        for(int j=0;j<(2*n)-1;j++)
        {
            int top=i;
            int left=j;
            int right=(2*n)-1-1-j;
            int bottom=(2*n)-1-1-i;
            //n-oldmatrix=newmatrix
            //so oldmatrix=n-newmatrix
            cout<<n-(min(min(top,left),min(right,bottom)));
        }
        cout<<endl;
    }
}
