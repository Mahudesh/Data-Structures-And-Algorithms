  public:
    int toggleBits(int n , int l , int r) 
    {
        // code here
        //For Toggling Do XOR Operation
        for(int i=l;i<=r;i++)
        {
            n=n^(1<<i-1);
        }
        return n;
    }
