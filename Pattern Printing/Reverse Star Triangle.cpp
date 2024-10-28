void nStarTriangle(int n) 
{
    // Write your code here.
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
Output: 

*****
 ***
  *
