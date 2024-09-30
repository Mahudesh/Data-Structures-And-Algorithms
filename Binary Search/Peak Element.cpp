long long int floorSqrt(long long int n) 
    {
        // Your code goes here
        long long low=1;
        long long high=n;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if((long long)mid*(long long)mid == n)
            return mid;
            if((long long)mid*(long long)mid>n)
            high=mid-1;
            else if((long long)mid*(long long)mid<n)
            low=mid+1;
            
        }
        return high;
    }
