bool isPerfectSquare(int num) 
    {
        // bool f=false;
        // for(long long i=1;i<=num;i++)
        // {
        //     long long prod=i*i;
        //     if(prod>num)
        //     return false;
        //     else if(prod==num)
        //     {
        //         f=true;
        //         break;
        //     }
        // }
        // if(f)
        // return true;
        // return false;

        long long low=1;
        long long high=num;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if((long long)mid*(long long)mid==num)
            return true;
            if((long long)mid*(long long)mid<num)
            {
                low=mid+1;
            }
            else if((long long)mid*(long long)mid>num)
            {
                high=mid-1;
            }
        }
        return false;
    }
