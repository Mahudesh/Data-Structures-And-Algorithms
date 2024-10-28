void nLetterTriangle(int n) 
{
    // Write your code here.
    for(int i=1;i<=n;i++)
    {
        char ch='A';
        for(int j=1;j<=n-i+1;j++)
        {
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}

Output: 

A B C
A B
A
