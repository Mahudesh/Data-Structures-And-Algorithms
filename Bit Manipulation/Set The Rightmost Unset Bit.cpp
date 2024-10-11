  public:
    int setBit(int n) 
    {
        // Write Your Code here
        //It(n+1) Automatically Set Just Below The Last Unset Below As 1
        //So To Set The Bit Just Do The OR Operation
        return (n|n+1);
    }
