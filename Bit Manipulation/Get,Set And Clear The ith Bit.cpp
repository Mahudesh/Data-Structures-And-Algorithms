  public:
    void bitManipulation(int num, int i) 
    {
        // your code here
        int a,b,c;
        a=1<<i-1;
        if((num&a)>0)
        cout<<"1"<<" ";
        else
        cout<<"0 ";
        b=num|(1<<i-1);
        cout<<b<<" ";
        
        c=num&(~(1<<i-1));
        cout<<c;
    }
};
