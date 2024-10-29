void symmetry(int n)
 {

    // Write your code here.
    int sp=0;
    for(int i=1;i<=(2*n);i++)
    {
      
            int stars=(2*n)-sp;
            for(int j=1;j<=stars/2;j++)
            {
                cout<<"* ";
            }
            for(int j=1;j<=sp;j++)
            {
                cout<<" ";
            }
            for(int j=1;j<=stars/2;j++)
            {
                cout<<"* ";
            }
            if(i<n)
            sp=sp+2;
            else if(i>n)
            sp=sp-2;
            cout<<endl;
        
       
    }
}

Output:
* * * * * * 
* *     * * 
*         * 
*         * 
* *     * * 
* * * * * * 
